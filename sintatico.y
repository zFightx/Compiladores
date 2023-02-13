%{
#include <stdio.h> 
#include <string.h>
#include "CODE.H"

extern FILE *yyin;
extern FILE *yyout;

int yylex(void);
int yyerror(char* s);

enum tipoEnum {tipo_int, tipo_void};

char* tipos[] = {
  "tipo_int", "tipo_void"
};

/* TM location number for current instruction emission */
static int emitLoc = 0;

/* Highest TM location emitted so far
   For use in conjunction with emitSkip,
   emitBackup, and emitRestore */
static int highEmitLoc = 0;

int tipo = 0;

struct regTabSimb {
	char *nome;                 /* nome do simbolo */
	char *tipo;                 /* tipo_int ou tipo_cad ou nsa */
	char *natureza;             /* variavel ou procedimento */
	int usado;                  /* 1=sim ou 0=nao */
	struct regTabSimb *prox;    /* ponteiro */
};
typedef struct regTabSimb regTabSimb;
regTabSimb *tabSimb = (regTabSimb *)0;
regTabSimb *colocaSimb();
int constaTabSimb(char *nomeSimb);
int HaWarningTabSimb();
void declaraUsadoTabSimb();
void imprimeTabSimb();
int erroSemantico;


%}

%union{
	int Uinteiro;
    float Uflutuante;
    char *Ucadeia;
}

%token LEITURA
%token ESCRITA
%token WHILE
%token IF
%token ELSE
%token RETURN
%token LESSEQUAL
%token LESS
%token GREATER
%token GREATEREQUAL
%token EQUALEQUAL
%token NOTEQUAL
%token ADD
%token MINUS
%token MULTIPLIER
%token DIVISION
%token TYPEINT
%token TYPEVOID
%token <Uflutuante> FLOAT
%token <Uinteiro> INT
%token <Ucadeia> ID

%right "then" ELSE

%%
programa:           declaracao_lista
                    { 
                        if (erroSemantico) {
                            printf("\n Sintaxe ok, mas erro semantico: esqueceu de declarar alguma variavel que usou...\n");
                        } else {
                            printf("Sintaxe e semantica ok!\n");
                            if (HaWarningTabSimb()) { 
                                printf("Aviso: alguma variavel declarada e nao usada!\n");
                                imprimeTabSimb();
                            };
                        }   
                    }
;
declaracao_lista:   declaracao_lista declaracao                     {;}
                    | declaracao                                    {;}
;
declaracao:         var_declaracao                                  {;}
                    | fun_declaracao                                {;}
;
var_declaracao:     tipo_especificador ID ';'                           
                    {
                        printf("VARIAVEL CRIADA: %s, com o tipo %s\n", $2, tipos[tipo]);
                        colocaSimb($2,tipos[tipo],"variavel",0);
                    }
                    | tipo_especificador ID '[' INT ']'                 
                    {
                        {
                            printf("VARIAVEL CRIADA: %s, com o tipo %s\n", $2, tipos[tipo]);
                            colocaSimb($2,tipos[tipo],"variavel",0);
                        }
                    }
;
tipo_especificador: TYPEINT                                 { tipo=0; }
                    | TYPEVOID                              { tipo=1; }
;
fun_declaracao:     tipo_especificador ID '(' params ')' escopo_stmt    
                    {
                        printf("FUNCAO CRIADA: %s, com o tipo %s\n", $2, tipos[tipo]);
                        colocaSimb($2,tipos[tipo],"funcao",0);
                    }
;
params:             params_lista                                    {;}
                    | TYPEVOID                                      {;}
;
params_lista:       params_lista ',' param                          {;}
                    | param
;
param:              tipo_especificador ID                               
                    {   
                        printf("PARAMETRO CRIADO: %s, com o tipo %s\n", $2, tipos[tipo]);
                        colocaSimb($2, tipos[tipo], "variavel", 0);
                    }
                    | tipo_especificador ID '[' ']'                     
                    {   
                        printf("PARAMETRO CRIADO: %s, com o tipo %s\n", $2, tipos[tipo]);
                        colocaSimb($2, tipos[tipo], "variavel", 0);
                    }
;
escopo_stmt:        '{' declaracoes_locais statement_lista '}'      {;}
;
declaracoes_locais: /*empty*/
                    | declaracoes_locais var_declaracao             {;}
;
statement_lista:    /*empty*/
                    | statement_lista statement                     {;}
;
statement:          expressao_stmt                                  {;}
                    | escopo_stmt                                   {;}
                    | selecao_stmt                                  {;}
                    | iteracao_stmt                                 {;}
                    | retorno_stmt                                  {;}
;
expressao_stmt:     expressao ';'                                   {;}
                    | ';'                                           {;}
;
selecao_stmt:       IF '(' expressao ')' statement %prec "then"     {;}
                    | IF '(' expressao ')' statement ELSE statement {;}
;
iteracao_stmt:      WHILE '(' expressao ')' statement               {;}
;
retorno_stmt:       RETURN ';'                                      {;}
                    | RETURN expressao ';'                          {;}
;
expressao:          var '=' expressao                               {;}
                    | expressao_simples                             {;}
;
var:                ID                                                  
                    {
                        if (!constaTabSimb($1))
			                erroSemantico=1;
                        else
                            declaraUsadoTabSimb($1);
                    }
                    | ID '[' expressao ']'                              
                    {
                        if (!constaTabSimb($1))
			                erroSemantico=1;
                        else
                            declaraUsadoTabSimb($1);
                    }
;
expressao_simples:  expressao_aditiva relop expressao_aditiva       {;}
                    | expressao_aditiva                             {;}
;
relop:              LESSEQUAL                                       {;}
                    | LESS                                          {;}
                    | GREATER                                       {;}
                    | GREATEREQUAL                                  {;}
                    | EQUALEQUAL                                    {;}
                    | NOTEQUAL                                      {;}
;
expressao_aditiva:  expressao_aditiva addop termo                   {;}
                    | termo                                         {;}
;
addop:              ADD                                             {;}
                    | MINUS                                         {;}
;
termo:              termo mulop fator                               {;}
                    | fator                                         {;}
;
mulop:              MULTIPLIER                                      {;}
                    | DIVISION                                      {;}
;
fator:              '(' expressao ')'                               {;}
                    | var                                           {;}
                    | call                                          {;}
                    | INT 
                    { emitRM("LDC",ac,$1,0,"load const"); }
                    | FLOAT
                    { emitRM("LDC",ac,$1,0,"load const"); }
;
call:               ESCRITA '(' args ')' 
                    {
                        printf("FEZ UMA ESCRITA\n");
                        emitRO("OUT",ac,0,0,"write ac");
                    }
                    | LEITURA '(' args ')' 
                    { printf("FEZ UMA LEITURA\n"); }
                    | ID '(' args ')'                               {;}
;
args:               /*empty*/
                    | args_lista                                    {;}
;
args_lista:         args_lista ',' expressao                        {;}
                    | expressao                                     {;}
;
%%

regTabSimb *colocaSimb(char *nomeSimb, char *tipoSimb, char *naturezaSimb, int usadoSimb){
	regTabSimb *ptr;
	ptr = (regTabSimb *) malloc (sizeof(regTabSimb));

	ptr->nome= (char *) malloc(strlen(nomeSimb)+1);
	ptr->tipo= (char *) malloc(strlen(tipoSimb)+1);
	ptr->natureza= (char *) malloc(strlen(naturezaSimb)+1);

	strcpy (ptr->nome,nomeSimb);
	strcpy (ptr->tipo,tipoSimb);
	strcpy (ptr->natureza,naturezaSimb);
	ptr->usado = usadoSimb;

	ptr->prox= (struct regTabSimb *)tabSimb;
	tabSimb= ptr;
	return ptr;
}
int constaTabSimb(char *nomeSimb) {
	regTabSimb *ptr;
	for (ptr=tabSimb; ptr!=(regTabSimb *)0; ptr=(regTabSimb *)ptr->prox)
	  if (strcmp(ptr->nome,nomeSimb)==0) return 1;
    printf("VARIAVEL NAO DECLARADA USADA: %s\n", nomeSimb);
	return 0;
}
int HaWarningTabSimb() {
	regTabSimb *ptr;
	for (ptr=tabSimb; ptr!=(regTabSimb *)0; ptr=(regTabSimb *)ptr->prox)
	  if ((ptr->usado==0) && (strcmp(ptr->natureza,"variavel")==0)) return 1;
	return 0;
}
void declaraUsadoTabSimb(char *nomeSimb) {
	regTabSimb *ptr;
	for (ptr=tabSimb; ptr!=(regTabSimb *)0; ptr=(regTabSimb *)ptr->prox)
	  if (strcmp(ptr->nome,nomeSimb)==0) {
        ptr->usado = 1; return;
      }
}
void imprimeTabSimb() {
	regTabSimb *ptr;
	for (ptr=tabSimb; ptr!=(regTabSimb *)0; ptr=(regTabSimb *)ptr->prox)  
        if (strcmp(ptr->natureza,"variavel")==0)
            printf("%s usado: %d\n", ptr->nome, ptr->usado);      
}

void emitRO( char *op, int r, int s, int t, char *c)
{ fprintf(yyout,"%3d:  %5s  %d,%d,%d ",emitLoc++,op,r,s,t);
//  if (TraceCode) fprintf(code,"\t%s",c) ;
  fprintf(yyout,"\n") ;
//  if (highEmitLoc < emitLoc) highEmitLoc = emitLoc ;
} /* emitRO */

/* Procedure emitRM emits a register-to-memory
 * TM instruction
 * op = the opcode
 * r = target register
 * d = the offset
 * s = the base register
 * c = a comment to be printed if TraceCode is TRUE
 */
void emitRM( char * op, int r, int d, int s, char *c)
{ fprintf(yyout,"%3d:  %5s  %d,%d(%d) ",emitLoc++,op,r,d,s);
//  if (TraceCode) fprintf(code,"\t%s",c) ;
  fprintf(yyout,"\n") ;
//  if (highEmitLoc < emitLoc)  highEmitLoc = emitLoc ;
} /* emitRM */

int main (int argc, char* argv[]) 
{
    if (argc <= 0) return 0;
    yyin = fopen(argv[1], "rt");
    yyout = fopen("out.tm", "wt");

    //emitComment("Standard prelude:");
    emitRM("LD",mp,0,ac,"load maxaddress from location 0");
    emitRM("ST",ac,0,ac,"clear location 0");
    //emitComment("End of standard prelude.");

    erroSemantico=0;

	yyparse ();
    
    //emitComment("End of execution.");
    emitRO("HALT",0,0,0,"");

    fclose(yyin);
    fclose(yyout);
    return 0;
}
int yyerror (s) /* Called by yyparse on error */
	char *s;
{
	printf ("Problema com a analise sintatica!\n%s\n", s);
}