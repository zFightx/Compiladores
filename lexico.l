%{
#include "sintatico.tab.h"
%}

LETRA           [a-zA-Z]
DIGITO          [0-9]
NUM             {DIGITO}+
SINAL           [+-]
ESCRITA         escreval
LEITURA         leitural
WHILE           enquanto
IF              se
ELSE            senao
RETURN          retorno
LESSEQUAL       <=
LESS            <
GREATER         >
GREATEREQUAL    >=
EQUALEQUAL      ==
NOTEQUAL        !=
TYPEINT         inteiro{ESPACO}
TYPEVOID        vazio{ESPACO}
ID              {LETRA}+
INT             {SINAL}?{NUM}
COMENTARIO      \/\*[^\*]*\*+([^\*\/][^\*]*\*+)*\/
FLOAT           [+-]?({NUM}([.]{DIGITO}*)?|[.]{NUM})
ADD             [+]
MINUS           [-]
MULTIPLIER      [*]
DIVISION        [/] 
ESPACO          [ \t\n]
OUTRO           .

%%

{INT}           {yylval.Uinteiro = atoi(yytext); return INT;}
{FLOAT}         {yylval.Uflutuante = atof(yytext); return FLOAT;}
{ESCRITA}       {return ESCRITA;}
{LEITURA}       {return LEITURA;}
{WHILE}         {return WHILE;}
{IF}            {return IF;}
{ELSE}          {return ELSE;}
{RETURN}        {return RETURN;}
{LESSEQUAL}     {return LESSEQUAL;}
{LESS}          {return LESS;}
{GREATER}       {return GREATER;}
{GREATEREQUAL}  {return GREATEREQUAL;}
{EQUALEQUAL}    {return EQUALEQUAL;}
{NOTEQUAL}      {return NOTEQUAL;}
{ID}            {return ID;}
{TYPEINT}       {return TYPEINT;}
{TYPEVOID}      {return TYPEVOID;}
{COMENTARIO}    {return COMENTARIO;}
{ADD}           {return ADD;}
{MINUS}         {return MINUS;}
{MULTIPLIER}    {return MULTIPLIER;}
{DIVISION}      {return DIVISION;}
{ESPACO}        {;}
{OUTRO}         {return yytext[0];}

%%

/* recomendavel declarar sempre funcao yywrap() */
/* int yywrap (); */

int yywrap () {
    return 1;
}