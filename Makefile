cc = gcc

CFLAGS = 

main: lexico
	gcc lex.yy.c sintatico.tab.c -o main

lexico: sintatico
	flex lexico.l

sintatico: sintatico.y
	bison -d sintatico.y