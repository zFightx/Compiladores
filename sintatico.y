%{
#include <stdio.h> 
#include "CODE.H"

extern FILE *yyin;
extern FILE *yyout;

int yylex(void);
int yyerror(char* s);

/* TM location number for current instruction emission */
static int emitLoc = 0;

/* Highest TM location emitted so far
   For use in conjunction with emitSkip,
   emitBackup, and emitRestore */
static int highEmitLoc = 0;
%}

%union{
	int Uinteiro;
    float Uflutuante;
}

%token LEITURA
%token ESCRITA
%token WHILE
%token COMENTARIO
%token TYPEINT
%token <Uflutuante> FLOAT
%token <Uinteiro> INT
%token ID
%%
programa:           declaracao_lista
                    { printf("Rodando programa\n"); }
;
declaracao_lista:   declaracao_lista declaracao                         {;}
                    | declaracao                                        {;}
;
declaracao:         var_declaracao                                      {;}
                    | fun_declaracao                                    {;}
;
var_declaracao:     tipo_especificador ID ';'
                    { printf("var declaracao\n"); }
;
fun_declaracao:     tipo_especificador ID '(' params ')' escopo_stmt    {;}
;
params:             params_lista                                        {;}
;
params_lista:       params_lista ',' param                              {;}
                    | param
;
param:              tipo_especificador ID                               {;}
;
tipo_especificador: TYPEINT                                             {;}
;
escopo_stmt:        '{' declaracoes_locais statement_lista '}'          {;}
;
declaracoes_locais: /*empty*/
                    | declaracoes_locais var_declaracao                 {;}
;
statement_lista:    /*empty*/
                    | statement_lista statement                         {;}
;
statement:          expressao_stmt                                      {;}
                    | escopo_stmt                                       {;}
                    | iteracao_stmt                                     {;}
;
expressao_stmt:     expressao ';'                                       {;}
                    | ';'                                               {;}
;
iteracao_stmt:      WHILE '(' expressao ')' statement                   {;}
;
expressao:          var '=' expressao                                   {;}
                    | expressao_simples                                 {;}
;
var:                ID                                                  {;}
;
expressao_simples:  expressao_aditiva                                   {;}
;
expressao_aditiva:  termo                                               {;}
;
termo:              fator                                               {;}
;
fator:              var                                                 {;}
                    | call                                              {;}
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
                    | ID '(' args ')'                                   {;}
;
args:               /*empty*/
                    | args_lista                                        {;}
;
args_lista:         args_lista ',' expressao                            {;}
                    | expressao                                         {;}
;
%%

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

int main () 
{
    yyin = fopen("teste.txt", "rt");
    yyout = fopen("out.tm", "wt");

    //emitComment("Standard prelude:");
    emitRM("LD",mp,0,ac,"load maxaddress from location 0");
    emitRM("ST",ac,0,ac,"clear location 0");
    //emitComment("End of standard prelude.");

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