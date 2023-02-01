%{
	#include "sintatico.tab.h"
%}
LETRA		[a-zA-Z]
DIGITO		[0-9]
NUM			{DIGITO}+
SINAL		[+-]
ESCRITA		printf
LEITURA		scanf
WHILE		while
TYPEINT		int{ESPACO}
ID			{LETRA}+
INT 		{SINAL}?{NUM}
COMENTARIO	\/\*[^\*]*\*+([^\*\/][^\*]*\*+)*\/
FLOAT		[+-]?({NUM}([.]{DIGITO}*)?|[.]{NUM})
ESPACO		[ \t\n]+
OUTRO		.
%%
{INT}			{yylval.inteiro = atoi(yytext); return INT;}
{FLOAT}			{yylval.flutuante = atof(yytext); return FLOAT;}
{ESCRITA}		{return ESCRITA;}
{LEITURA}		{return LEITURA;}
{WHILE}		    {return WHILE;}
{ID}			{return ID;}
{TYPEINT}		{return TYPEINT;}
{COMENTARIO}	{return COMENTARIO;}
{ESPACO}		{;}
{OUTRO}			{return yytext[0];}
%%
/* recomendavel declarar sempre funcao yywrap() */
/* int yywrap (); */

int yywrap() {
	return 1;
}