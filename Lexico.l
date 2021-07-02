%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <conio.h>
	#include <string.h>
	#include "y.tab.h"

	int mensaje_error(char* mensaje);

	FILE  *yyin;
%}

%option noyywrap
%option yylineno

DIGITO			[0-9]
LETRA			[a-zA-Z]
SIMBOLO			[" "|'\t'|"#"|"%"|"?"|"¿"|"°"|","|";"|"!"|"¡"|"\\"|"@"|"."|":"|"_"|'\-'|'/'|"="|"“"|"”"|"("|")"]
SIMBOLOCOMENTARIO			[" "|'\t'|"#"|"%"|"?"|"¿"|"°"|","|";"|"!"|"¡"|"\\"|"@"|"."|":"|"_"|'\-'|'+'|'*'|'/'|"["|'\]'|'{'|'}'|"="|"“"|"”"|"("|")"]
ID				{LETRA}({LETRA}|{DIGITO})*
CTE_ENTERA		{DIGITO}+
CTE_REAL		{DIGITO}+"."{DIGITO}*|{DIGITO}*"."{DIGITO}+
CTE_STRING		\"({LETRA}|{DIGITO}|{SIMBOLO})*\"
/*CTE_STRING		\".*\" */
COMENTARIO		\-\/({LETRA}|{DIGITO}|{SIMBOLOCOMENTARIO})*\/\-
COMENT_ERROR	\-\/ 
/*COMENTARIO		\-\/.*\/\- */

%%

"DECVAR"		{ return DECVAR;}
"ENDDEC"		{ return ENDDEC;}
"INTEGER"		{ return ENTERO;}
"FLOAT"			{ return REAL;}
"STRING"		{ return STRING;}
"READ"			{ return READ;}
"WRITE"			{ return WRITE;}
"WHILE"			{ return WHILE;}
"IF"			{ return IF;}
"ELSE"			{ return ELSE;}
"INLIST"		{ return INLIST;}
"NEWLINE"		{ return NEWLINE;}
"&&"			{ return AND;}
"||"			{ return OR;}
"NOT"			{ return NOT;}
"="				{ return OP_ASIG;}
","				{ return COMA;}
";"				{ return PUNTO_COMA;}
":"				{ return DOS_PUNTOS;}
"+"				{ return OP_SUMA;}
"-"				{ return OP_RESTA;}
"*"				{ return OP_MULT;}
"/"				{ return OP_DIV;}
"["				{ return CORCHA;}
"]"				{ return CORCHC;}
"("				{ return PARA;}
")"				{ return PARC;}
"{"				{ return LLA;}
"}"				{ return LLC;}
"<="			{ return MENOR_IGUAL;}
">="			{ return MAYOR_IGUAL;}
"<"				{ return MENOR;}
">" 			{ return MAYOR;}
"!="			{ return DISTINTO;}
"=="			{ return IGUAL;}

{ID}		   		{if(strlen(yytext) <= 31){
						yylval.string_val = strdup(yytext);
						return ID;
						}
					mensaje_error("variable de mas de 30 caracteres");
					}

{CTE_REAL}+   		{if(atof(yytext)<=3.40282347e+38F){
						yylval.float_val = atof(yytext);
						return CTE_REAL;
						}
					mensaje_error("constante real demasiado grande");
					}

{CTE_ENTERA}+   	{if(atoll(yytext)<=2147483647)
						{	yylval.int_val = atoi(yytext);
							return CTE_ENTERA;
						}
					mensaje_error("constante entera demasiado grande");
					}

{CTE_STRING}		{if(strlen(yytext)<=33){
						
						return CTE_STRING;
						}
					mensaje_error("constante string de mas de 30 caracteres");
					}

{COMENTARIO}		{printf("\t\tcomentario: %s\n", yytext);}
{COMENT_ERROR}		{mensaje_error("Caracter invalido en comentario");}
" "
"\n"
"\t"
.		{mensaje_error("Caracter invalido");}

%%

int mensaje_error(char* mensaje)
{
	printf("Error lexico: %s\nLinea: %d %s\n", mensaje , yylineno, yytext);
	system ("Pause");
	exit (1);
}
