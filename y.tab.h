
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     DECVAR = 258,
     ENDDEC = 259,
     ENTERO = 260,
     REAL = 261,
     STRING = 262,
     WHILE = 263,
     IF = 264,
     OP_ASIG = 265,
     NOT = 266,
     OR = 267,
     AND = 268,
     OP_RESTA = 269,
     OP_SUMA = 270,
     OP_DIV = 271,
     OP_MULT = 272,
     MENOR_IGUAL = 273,
     MAYOR_IGUAL = 274,
     MENOR = 275,
     MAYOR = 276,
     IGUAL = 277,
     DISTINTO = 278,
     COMA = 279,
     PUNTO_COMA = 280,
     DOS_PUNTOS = 281,
     PARA = 282,
     PARC = 283,
     LLA = 284,
     LLC = 285,
     READ = 286,
     WRITE = 287,
     ID = 288,
     CTE_REAL = 289,
     CTE_ENTERA = 290,
     CTE_STRING = 291,
     NO_ELSE = 292,
     ELSE = 293
   };
#endif
/* Tokens.  */
#define DECVAR 258
#define ENDDEC 259
#define ENTERO 260
#define REAL 261
#define STRING 262
#define WHILE 263
#define IF 264
#define OP_ASIG 265
#define NOT 266
#define OR 267
#define AND 268
#define OP_RESTA 269
#define OP_SUMA 270
#define OP_DIV 271
#define OP_MULT 272
#define MENOR_IGUAL 273
#define MAYOR_IGUAL 274
#define MENOR 275
#define MAYOR 276
#define IGUAL 277
#define DISTINTO 278
#define COMA 279
#define PUNTO_COMA 280
#define DOS_PUNTOS 281
#define PARA 282
#define PARC 283
#define LLA 284
#define LLC 285
#define READ 286
#define WRITE 287
#define ID 288
#define CTE_REAL 289
#define CTE_ENTERA 290
#define CTE_STRING 291
#define NO_ELSE 292
#define ELSE 293




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 14 "Sintactico.y"

	int int_val;
	float float_val;
	char *string_val;



/* Line 1676 of yacc.c  */
#line 136 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


