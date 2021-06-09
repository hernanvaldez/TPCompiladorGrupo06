
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "Sintactico.y"

	#include <stdio.h>
	#include <stdlib.h>
	#include <conio.h>
	#include <string.h>
	#include <math.h>
	#include "y.tab.h"

	#define TAM 35
	#define DUPLICADO 2
	#define SIN_MEMORIA 3
	#define ID_EN_LISTA 4
	
	int yyerror(char* mensaje);

	extern int yylineno;
	extern char * yytext;

	FILE  *yyin;

	// Estructuras para la tabla de simbolos

	typedef struct
	{
			char nombre[TAM];
			char tipodato[TAM];
			char valor[TAM];
			int longitud;
	}t_info;

	typedef struct s_nodo
	{
		t_info info;
		struct s_nodo *pSig;
	}t_nodo;

	typedef t_nodo *t_lista;

	typedef int (*t_cmp)(const void *, const void *);

	// Declaracion funciones primera entrega

	int compararPorNombre(const void *, const void *);

	void crear_lista(t_lista *p);
	int insertarEnListaEnOrdenSinDuplicados(t_lista *l_ts, t_info *d, t_cmp);
	int BuscarEnLista(t_lista *pl, char* cadena );

	void crear_ts(t_lista *l_ts);
	int insertar_en_ts(t_lista *l_ts, t_info *d);

	void grabar_lista(t_lista *);
	void reemplazar_blancos_por_guiones_y_quitar_comillas(char *);
	void quitar_comillas(char *);

	t_lista lista_ts;
	t_info dato;

	// Estructuras para los tercetos //

	typedef struct
	{
		int numeroTerceto;
		char primerElemento[TAM];
		char segundoElemento[TAM];
		char tercerElemento[TAM];
	} t_info_terceto;

	typedef struct s_nodo_terceto
	{
		t_info_terceto info;
		struct s_nodo_terceto *pSig;
	} t_nodo_terceto;

	typedef t_nodo_terceto *t_lista_terceto;
	t_lista_terceto lista_terceto;
	t_info_terceto dato_terceto;
	int contadorTercetos = 0;

	// +++++++++++++++++ Indices +++++++++++++++++ //

	// Expresion //

	int expresionIndice;
	int terminoIndice;
	int factorIndice;

	// Declaracion funciones segunda entrega //

	// Lista

	void crear_lista_terceto(t_lista_terceto *p);
	int	insertar_en_lista_terceto(t_lista_terceto *p, const t_info_terceto *d);

	// Tercetos

	char* crearIndice(int); //Recibe un numero de terceto y lo combierte en un indice
	int crearTerceto(char*, char*, char*); //Se mandan los 3 strings, y se guarda el terceto creado en la lista
										   //La posicion en la lista se lo da contadorTercetos. Variable que aumenta en 1
  	void guardarTercetosEnArchivo(t_lista_terceto *);								   



/* Line 189 of yacc.c  */
#line 177 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


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
     INLIST = 279,
     COMA = 280,
     PUNTO_COMA = 281,
     DOS_PUNTOS = 282,
     CORCHA = 283,
     CORCHC = 284,
     PARA = 285,
     PARC = 286,
     LLA = 287,
     LLC = 288,
     READ = 289,
     WRITE = 290,
     ID = 291,
     CTE_REAL = 292,
     CTE_ENTERA = 293,
     CTE_STRING = 294,
     NO_ELSE = 295,
     ELSE = 296
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
#define INLIST 279
#define COMA 280
#define PUNTO_COMA 281
#define DOS_PUNTOS 282
#define CORCHA 283
#define CORCHC 284
#define PARA 285
#define PARC 286
#define LLA 287
#define LLC 288
#define READ 289
#define WRITE 290
#define ID 291
#define CTE_REAL 292
#define CTE_ENTERA 293
#define CTE_STRING 294
#define NO_ELSE 295
#define ELSE 296




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 104 "Sintactico.y"

	int int_val;
	float float_val;
	char *string_val;



/* Line 214 of yacc.c  */
#line 303 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 315 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  28
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   149

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  60
/* YYNRULES -- Number of states.  */
#define YYNSTATES  108

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    14,    17,    19,    23,
      27,    29,    31,    33,    35,    38,    40,    42,    44,    46,
      48,    50,    54,    58,    60,    63,    69,    77,    80,    85,
      91,    99,   101,   105,   109,   112,   116,   118,   127,   131,
     133,   135,   137,   139,   141,   143,   145,   149,   153,   155,
     158,   162,   166,   168,   172,   174,   176,   178,   180,   183,
     186
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      43,     0,    -1,    44,    -1,    45,    50,    -1,    50,    -1,
       3,    46,     4,    -1,    46,    47,    -1,    47,    -1,    48,
      27,    49,    -1,    48,    25,    36,    -1,    36,    -1,     5,
      -1,     6,    -1,     7,    -1,    50,    51,    -1,    51,    -1,
      52,    -1,    53,    -1,    56,    -1,    65,    -1,    66,    -1,
      36,    10,    62,    -1,    36,    10,    52,    -1,    54,    -1,
      54,    55,    -1,     9,    30,    57,    31,    51,    -1,     9,
      30,    57,    31,    32,    50,    33,    -1,    41,    51,    -1,
      41,    32,    50,    33,    -1,     8,    30,    57,    31,    51,
      -1,     8,    30,    57,    31,    32,    50,    33,    -1,    58,
      -1,    58,    13,    58,    -1,    58,    12,    58,    -1,    11,
      58,    -1,    62,    61,    62,    -1,    59,    -1,    24,    30,
      36,    26,    28,    60,    29,    31,    -1,    60,    26,    62,
      -1,    62,    -1,    18,    -1,    19,    -1,    20,    -1,    21,
      -1,    22,    -1,    23,    -1,    62,    15,    63,    -1,    62,
      14,    63,    -1,    63,    -1,    14,    63,    -1,    63,    17,
      64,    -1,    63,    16,    64,    -1,    64,    -1,    30,    62,
      31,    -1,    36,    -1,    38,    -1,    37,    -1,    39,    -1,
      35,    36,    -1,    35,    39,    -1,    34,    36,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   143,   143,   146,   147,   152,   155,   156,   159,   162,
     169,   178,   179,   180,   185,   186,   189,   190,   191,   192,
     193,   196,   197,   200,   201,   204,   205,   208,   209,   212,
     213,   216,   217,   218,   219,   222,   223,   226,   229,   230,
     233,   234,   235,   236,   237,   238,   241,   245,   249,   253,
     259,   263,   267,   273,   278,   284,   296,   307,   317,   320,
     330
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DECVAR", "ENDDEC", "ENTERO", "REAL",
  "STRING", "WHILE", "IF", "OP_ASIG", "NOT", "OR", "AND", "OP_RESTA",
  "OP_SUMA", "OP_DIV", "OP_MULT", "MENOR_IGUAL", "MAYOR_IGUAL", "MENOR",
  "MAYOR", "IGUAL", "DISTINTO", "INLIST", "COMA", "PUNTO_COMA",
  "DOS_PUNTOS", "CORCHA", "CORCHC", "PARA", "PARC", "LLA", "LLC", "READ",
  "WRITE", "ID", "CTE_REAL", "CTE_ENTERA", "CTE_STRING", "NO_ELSE", "ELSE",
  "$accept", "inicio", "programa", "seccion_declaracion", "bloque_dec",
  "declaracion", "lista_id", "t_dato", "bloque_cod", "sentencia",
  "asignacion", "seleccion", "bloque_if", "bloque_else", "iteracion",
  "condicion", "comparacion", "inlist", "lista_expr", "comparador",
  "expresion", "termino", "factor", "salida", "entrada", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    44,    44,    45,    46,    46,    47,    48,
      48,    49,    49,    49,    50,    50,    51,    51,    51,    51,
      51,    52,    52,    53,    53,    54,    54,    55,    55,    56,
      56,    57,    57,    57,    57,    58,    58,    59,    60,    60,
      61,    61,    61,    61,    61,    61,    62,    62,    62,    62,
      63,    63,    63,    64,    64,    64,    64,    64,    65,    65,
      66
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     3,     2,     1,     3,     3,
       1,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     3,     3,     1,     2,     5,     7,     2,     4,     5,
       7,     1,     3,     3,     2,     3,     1,     8,     3,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     1,     2,
       3,     3,     1,     3,     1,     1,     1,     1,     2,     2,
       2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     2,     0,
       4,    15,    16,    17,    23,    18,    19,    20,    10,     0,
       7,     0,     0,     0,    60,    58,    59,     0,     1,     3,
      14,     0,    24,     5,     6,     0,     0,     0,     0,     0,
       0,    54,    56,    55,    57,     0,    31,    36,     0,    48,
      52,     0,    54,    22,    21,     0,    27,     9,    11,    12,
      13,     8,    34,    49,     0,     0,     0,     0,     0,     0,
       0,    40,    41,    42,    43,    44,    45,     0,     0,     0,
       0,     0,     0,    53,     0,    29,    33,    32,    47,    46,
      35,    51,    50,     0,    25,    28,     0,     0,     0,     0,
      30,    26,     0,    39,     0,     0,    38,    37
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     7,     8,     9,    19,    20,    21,    61,    10,    11,
      12,    13,    14,    32,    15,    45,    46,    47,   102,    77,
      48,    49,    50,    16,    17
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -33
static const yytype_int8 yypact[] =
{
       0,   -20,    23,    45,   -16,   -12,    97,    33,   -33,    93,
      93,   -33,   -33,   -33,    76,   -33,   -33,   -33,   -33,     3,
     -33,    59,    53,    53,   -33,   -33,   -33,   105,   -33,    93,
     -33,    -4,   -33,   -33,   -33,    84,    56,    94,    21,    92,
     109,   -33,   -33,   -33,   -33,    90,    13,   -33,    91,    49,
     -33,    95,    97,   -33,    89,    93,   -33,   -33,   -33,   -33,
     -33,   -33,   -33,    49,    98,    -2,    14,    94,    94,    21,
      21,   -33,   -33,   -33,   -33,   -33,   -33,   109,    21,    21,
      46,     9,    99,   -33,    93,   -33,   -33,   -33,    49,    49,
      89,   -33,   -33,    93,   -33,   -33,   108,    60,    64,   109,
     -33,   -33,   -15,    89,   109,   106,    89,   -33
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -33,   -33,   -33,   -33,   -33,   119,   -33,   -33,    -8,   -10,
     113,   -33,   -33,   -33,   -33,   126,   -27,   -33,   -33,   -33,
     -25,   -32,    37,   -33,   -33
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      30,    29,    54,     1,     2,     3,    63,    33,     2,     3,
      62,   104,    69,    70,   105,    65,    18,     2,     3,    30,
      24,    56,     2,     3,    25,    67,    68,    26,    55,    83,
       4,     5,     6,    28,     4,     5,     6,    88,    89,    18,
      86,    87,    95,     4,     5,     6,    84,    81,     4,     5,
       6,    40,    90,    22,     2,     3,    85,    41,    42,    43,
      44,    58,    59,    60,    37,    78,    79,    38,     2,     3,
      94,    30,     2,     3,   103,    23,    97,    39,    93,   106,
       4,     5,     6,    40,    35,    98,    36,    30,    30,    41,
      42,    43,    44,   100,     4,     5,     6,   101,     4,     5,
       6,     2,     3,    69,    70,    69,    70,    27,    38,    71,
      72,    73,    74,    75,    76,    91,    92,    31,    39,    38,
      57,    66,    64,    38,    40,    96,    80,     4,     5,     6,
      41,    42,    43,    44,    82,    40,    99,   107,    34,    40,
      53,    52,    42,    43,    44,    41,    42,    43,    44,    51
};

static const yytype_uint8 yycheck[] =
{
      10,     9,    27,     3,     8,     9,    38,     4,     8,     9,
      37,    26,    14,    15,    29,    40,    36,     8,     9,    29,
      36,    31,     8,     9,    36,    12,    13,    39,    32,    31,
      34,    35,    36,     0,    34,    35,    36,    69,    70,    36,
      67,    68,    33,    34,    35,    36,    32,    55,    34,    35,
      36,    30,    77,    30,     8,     9,    66,    36,    37,    38,
      39,     5,     6,     7,    11,    16,    17,    14,     8,     9,
      80,    81,     8,     9,    99,    30,    84,    24,    32,   104,
      34,    35,    36,    30,    25,    93,    27,    97,    98,    36,
      37,    38,    39,    33,    34,    35,    36,    33,    34,    35,
      36,     8,     9,    14,    15,    14,    15,    10,    14,    18,
      19,    20,    21,    22,    23,    78,    79,    41,    24,    14,
      36,    31,    30,    14,    30,    26,    31,    34,    35,    36,
      36,    37,    38,    39,    36,    30,    28,    31,    19,    30,
      27,    36,    37,    38,    39,    36,    37,    38,    39,    23
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     8,     9,    34,    35,    36,    43,    44,    45,
      50,    51,    52,    53,    54,    56,    65,    66,    36,    46,
      47,    48,    30,    30,    36,    36,    39,    10,     0,    50,
      51,    41,    55,     4,    47,    25,    27,    11,    14,    24,
      30,    36,    37,    38,    39,    57,    58,    59,    62,    63,
      64,    57,    36,    52,    62,    32,    51,    36,     5,     6,
       7,    49,    58,    63,    30,    62,    31,    12,    13,    14,
      15,    18,    19,    20,    21,    22,    23,    61,    16,    17,
      31,    50,    36,    31,    32,    51,    58,    58,    63,    63,
      62,    64,    64,    32,    51,    33,    26,    50,    50,    28,
      33,    33,    60,    62,    26,    29,    62,    31
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 143 "Sintactico.y"
    {printf("Compilacion Exitosa\n");}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 146 "Sintactico.y"
    {printf("Regla 1: programa -> seccion_declaracion bloque_cod\n");}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 147 "Sintactico.y"
    {printf("Regla 2: programa -> bloque_cod\n");}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 152 "Sintactico.y"
    {printf("Regla 3: seccion_declaracion -> DECVAR bloque_dec ENDDEC\n");}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 155 "Sintactico.y"
    {printf("Regla 4: bloque_dec -> bloque_dec declaracion\n");}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 156 "Sintactico.y"
    {printf("Regla 5: bloque_dec -> declaracion\n");}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 159 "Sintactico.y"
    {printf("Regla 6: declaracion -> lista_id DOS_PUNTOS t_dato\n");}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 162 "Sintactico.y"
    {
	                                            strcpy(dato.nombre, yylval.string_val);
	                                            strcpy(dato.valor, "");
	                                            strcpy(dato.tipodato, "");
	                                            dato.longitud = 0;
	                                            insertar_en_ts(&lista_ts, &dato);
	                                            printf("Declaracion: %s\n",yylval.string_val );printf("Regla 7: lista_id -> lista_id COMA ID\n");}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 169 "Sintactico.y"
    {
	                                            strcpy(dato.nombre, yylval.string_val);
	                                            strcpy(dato.valor, "");
	                                            strcpy(dato.tipodato, "");
	                                            dato.longitud = 0;
	                                            insertar_en_ts(&lista_ts, &dato);
	                                            printf("Declaracion: %s\n",yylval.string_val);printf("Regla 8: lista_id -> ID\n");}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 178 "Sintactico.y"
    {printf("Regla 9: t_dato -> ENTERO\n");}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 179 "Sintactico.y"
    {printf("Regla 10: t_dato -> REAL\n");}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 180 "Sintactico.y"
    {printf("Regla 11: t_dato -> STRING\n");}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 185 "Sintactico.y"
    {printf("Regla 12: bloque_cod -> bloque_cod sentencia\n");}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 186 "Sintactico.y"
    {printf("Regla 13: bloque_cod -> sentencia\n");}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 189 "Sintactico.y"
    {printf("Regla 14: sentencia -> asignacion\n");}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 190 "Sintactico.y"
    {printf("Regla 15: sentencia -> seleccion\n");}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 191 "Sintactico.y"
    {printf("Regla 16: sentencia -> iteracion\n");}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 192 "Sintactico.y"
    {printf("Regla 17: sentencia -> salida\n");}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 193 "Sintactico.y"
    {printf("Regla 18: sentencia -> entrada\n");}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 196 "Sintactico.y"
    {printf("Regla 19: asignacion -> ID OP_ASIG expresion\n");}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 197 "Sintactico.y"
    {printf("Regla 20: asignacion -> ID OP_ASIG asignacion\n");}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 200 "Sintactico.y"
    {printf("Regla 21: seleccion -> bloque_if\n");}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 201 "Sintactico.y"
    {printf("Regla 22: seleccion -> bloque_if bloque_else\n");}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 204 "Sintactico.y"
    {printf("Regla 23: bloque_if -> IF PARA condicion PARC sentencia\n");}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 205 "Sintactico.y"
    {printf("Regla 24: bloque_if -> IF PARA condicion PARC LLA bloque_cod LLC\n");}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 208 "Sintactico.y"
    {printf("Regla 25: bloque_else -> ELSE sentencia\n");}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 209 "Sintactico.y"
    {printf("Regla 26: bloque_else -> ELSE LLA bloque_cod LLC\n");}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 212 "Sintactico.y"
    {printf("Regla 27: iteracion -> WHILE PARA condicion PARC sentencia\n");}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 213 "Sintactico.y"
    {printf("Regla 28: iteracion -> WHILE PARA condicion PARC LLA bloque_cod LLC\n");}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 216 "Sintactico.y"
    {printf("Regla 29: condicion -> comparacion\n");}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 217 "Sintactico.y"
    {printf("Regla 30: condicion -> comparacion AND comparacion\n");}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 218 "Sintactico.y"
    {printf("Regla 31: condicion -> comparacion OR comparacion\n");}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 219 "Sintactico.y"
    {printf("Regla 32: condicion -> NOT comparacion\n");}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 222 "Sintactico.y"
    {printf("Regla 33: comparacion -> expresion comparador expresion\n");}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 223 "Sintactico.y"
    {printf("Regla 34: comparacion -> inlist\n");}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 226 "Sintactico.y"
    {printf("Regla 35: inlist -> INLIST PARA ID PUNTO_COMA CORCHA lista_expr CORCHC PARC\n");}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 229 "Sintactico.y"
    {printf("Regla 36: lista_expr -> lista_expr PUNTO_COMA expresion\n");}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 230 "Sintactico.y"
    {printf("Regla 37: lista_expr -> expresion\n");}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 233 "Sintactico.y"
    {printf("Regla 38: comparador -> MENOR_IGUAL\n");}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 234 "Sintactico.y"
    {printf("Regla 39: comparador -> MAYOR_IGUAL\n");}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 235 "Sintactico.y"
    {printf("Regla 40: comparador -> MENOR\n");}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 236 "Sintactico.y"
    {printf("Regla 41: comparador -> MAYOR\n");}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 237 "Sintactico.y"
    {printf("Regla 42: comparador -> IGUAL\n");}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 238 "Sintactico.y"
    {printf("Regla 43: comparador -> DISTINTO\n");}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 241 "Sintactico.y"
    {
													printf("Regla 44: expresion -> expresion OP_SUMA termino\n");
													expresionIndice = crearTerceto("+",crearIndice(expresionIndice),crearIndice(terminoIndice));
												}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 245 "Sintactico.y"
    {
													printf("Regla 45: expresion -> expresion OP_RESTA termino\n");
													expresionIndice = crearTerceto("-",crearIndice(expresionIndice),crearIndice(terminoIndice));
												}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 249 "Sintactico.y"
    {
													printf("Regla 46: expresion -> termino\n");
													expresionIndice = terminoIndice;
												}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 253 "Sintactico.y"
    {
													printf("Regla 47: expresion -> OP_RESTA termino\n");
													expresionIndice = crearTerceto("-",crearIndice(terminoIndice),"");
												}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 259 "Sintactico.y"
    {
													printf("Regla 48: termino -> termino OP_MULT factor\n");
													terminoIndice = crearTerceto("*",crearIndice(terminoIndice),crearIndice(factorIndice));
												}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 263 "Sintactico.y"
    {
													printf("Regla 49: termino -> termino OP_DIV factor\n");
													terminoIndice = crearTerceto("/",crearIndice(terminoIndice),crearIndice(factorIndice));
												}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 267 "Sintactico.y"
    {
													printf("Regla 50: termino -> factor\n");
													terminoIndice = factorIndice;
												}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 273 "Sintactico.y"
    {
													printf("Regla 51: factor -> PARA expresion PARC\n");
													// CrearTerceto
												}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 278 "Sintactico.y"
    {
	                                            BuscarEnLista(&lista_ts, yylval.string_val);
	                                            printf("factor ID: %s\n",yylval.string_val);printf("Regla 52: factor -> ID\n");
												factorIndice = crearTerceto((yyvsp[(1) - (1)].string_val),"","");
												}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 284 "Sintactico.y"
    {
	                                            // strcpy(d.clave, guion_cadena(yytext));
												char aux [50];
	                                            strcpy(dato.nombre, yytext);
	                                            strcpy(dato.valor, yytext);
	                                            strcpy(dato.tipodato, "const_Integer");
	                                            dato.longitud = 0;
	                                            insertar_en_ts(&lista_ts, &dato);
	                                            printf("Regla 53: factor -> CTE_ENTERA\n");
												factorIndice = crearTerceto(itoa((yyvsp[(1) - (1)].int_val),aux,10),"","");
												}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 296 "Sintactico.y"
    {
												char aux [50];
	                                            strcpy(dato.nombre, yytext);
	                                            strcpy(dato.valor, yytext);
	                                            strcpy(dato.tipodato, "const_Float");
	                                            dato.longitud = 0;
	                                            insertar_en_ts(&lista_ts, &dato);
	                                            printf("Regla 54: factor -> CTE_REAL\n");
												// factorIndice = crearTerceto($1,"",""); //Falta pasar $1 a char*
												}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 307 "Sintactico.y"
    {				
	                                            dato.longitud = strlen(yytext)-2;
	                                            strcpy(dato.nombre, yytext);
	                                            reemplazar_blancos_por_guiones_y_quitar_comillas(yytext);
	                                            strcpy(dato.valor, yytext);												
	                                            strcpy(dato.tipodato, "const_String");												
	                                            insertar_en_ts(&lista_ts, &dato);
	                                            printf("Regla 55: factor -> CTE_STRING\n");}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 317 "Sintactico.y"
    {
	                                            BuscarEnLista(&lista_ts, yylval.string_val);
	                                            printf("Regla 56: salida -> WRITE ID\n");}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 320 "Sintactico.y"
    {
	                                            dato.longitud = strlen(yytext)-2;
	                                            strcpy(dato.nombre, yytext);
	                                            reemplazar_blancos_por_guiones_y_quitar_comillas(yytext);
	                                            strcpy(dato.valor, yytext);												
	                                            strcpy(dato.tipodato, "const_String");
	                                            insertar_en_ts(&lista_ts, &dato);
	                                            printf("Regla 57: salida -> WRITE CTE_STRING\n");}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 330 "Sintactico.y"
    {
	                                            BuscarEnLista(&lista_ts, yylval.string_val);
	                                            printf("Regla 58: entrada -> READ ID\n");}
    break;



/* Line 1455 of yacc.c  */
#line 2103 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 334 "Sintactico.y"


int main(int argc,char *argv[])
{
  if ((yyin = fopen(argv[1], "rt")) == NULL)
  {
	printf("\nNo se puede abrir el archivo: %s\n", argv[1]);
  }
  else
  {
	crear_ts(&lista_ts);
	crear_lista_terceto(&lista_terceto);

	yyparse();

	grabar_lista(&lista_ts);
	guardarTercetosEnArchivo(&lista_terceto);
  	fclose(yyin);
  }
  return 0;
}

int yyerror(char* mensaje)
 {
	printf("Error sintactico en line %d: %s\n", yylineno, mensaje );
	system ("Pause");
	exit (1);
 }

 void crear_ts(t_lista *l_ts) {
	crear_lista(l_ts);

	printf("\n");
	printf("Creando tabla de simbolos...\n");	
	printf("Tabla de simbolos creada\n");
}

int insertar_en_ts(t_lista *l_ts, t_info *d) {
	insertarEnListaEnOrdenSinDuplicados(l_ts, d, compararPorNombre);
	
	// Un reinicio de la estructura dato para que vuelva a ser reutilizada sin problemas (quizas no hace falta) .
	strcpy(d->nombre,"\0");
	strcpy(d->tipodato,"\0");
	strcpy(d->valor,"\0");	
	d->longitud=0;
}

void crear_lista(t_lista *p) {
    *p=NULL;
}

int insertarEnListaEnOrdenSinDuplicados(t_lista *pl, t_info *d, t_cmp comparar)
{
    int cmp;
    t_nodo *nuevo;
    while(*pl && (cmp=comparar(d, &(*pl)->info))!=0)
        pl=&(*pl)->pSig;
    if(*pl && cmp==0)
        return DUPLICADO;
    nuevo=(t_nodo*)malloc(sizeof(t_nodo));
    if(!nuevo)
        return SIN_MEMORIA;
    nuevo->info=*d;
    nuevo->pSig=*pl;
    *pl=nuevo;
    return 1;
}

int BuscarEnLista(t_lista *pl, char* cadena )
{
    int cmp;

    while(*pl && (cmp=strcmp(cadena,(*pl)->info.nombre))!=0)
        pl=&(*pl)->pSig;
    if(cmp==0)
	{
        return ID_EN_LISTA;
	}
	printf("\nVariable sin declarar: %s \n",cadena);
    exit(1);
}

int compararPorNombre(const void *d1, const void *d2)
{
    t_info *dato1=(t_info*)d1;
    t_info *dato2=(t_info*)d2;

    return strcmp(dato1->nombre, dato2->nombre);
}

void grabar_lista(t_lista *pl){
	FILE *pf;

	pf = fopen("ts.txt", "wt");

	// Cabecera de la tabla
	fprintf(pf,"%-35s %-16s %-35s %-35s", "NOMBRE", "TIPO DE DATO", "VALOR", "LONGITUD");
	// Datos
	while(*pl) {
		fprintf(pf,"\n%-35s %-16s %-35s %-35d", (*pl)->info.nombre, (*pl)->info.tipodato, (*pl)->info.valor, (*pl)->info.longitud);
		pl=&(*pl)->pSig;
	}

	fclose(pf);
}

void reemplazar_blancos_por_guiones_y_quitar_comillas(char *pc){

	quitar_comillas(pc);

	char *aux = pc;
	
	while(*aux != '\0'){
		if(*aux == ' '){
			*aux= '_';
		}
		aux++;
	}
}

void quitar_comillas(char *pc){

	// Cadena del tipo "" (sin nada)
	if(strlen(pc) == 2){
		*pc='\0';
	}
	else{
		*pc = *(pc+1);
		pc++;
		while(*(pc+1) != '"'){
			*pc = *(pc+1);		
			pc++;
		}
		*pc='\0';
	}	
}

// Implementacion Funciones segunda entrega //

void crear_lista_terceto(t_lista_terceto *p){
	*p = NULL;
}

int insertar_en_lista_terceto(t_lista_terceto *p, const t_info_terceto *d)
{
    t_nodo_terceto* nue = (t_nodo_terceto *)malloc(sizeof(t_nodo_terceto));
    if(!nue)
        return SIN_MEMORIA;
    nue->info = *d;
    nue->pSig = NULL;
    while(*p)
        p = &(*p)->pSig;
    *p = nue;
    return 1;
}

char* crearIndice(int indice){
	
	char* resultado = (char*) malloc(sizeof(char)*7);
	char numeroTexto [4];

	strcpy(resultado,"[");
	itoa(indice,numeroTexto,10);
	strcat(resultado,numeroTexto);
	strcat(resultado,"]");
	return resultado;
}

int crearTerceto(char* primero, char* segundo, char* tercero){
	t_info_terceto nuevo;
	//nuevo.primerElemento = malloc(sizeof(char)*strlen(primero)+1);
	strcpy(nuevo.primerElemento,primero);
	//nuevo.segundoElemento = malloc(sizeof(char)*strlen(segundo)+1);
	strcpy(nuevo.segundoElemento,segundo);
	//nuevo.tercerElemento = malloc(sizeof(char)*strlen(tercero)+1);
	strcpy(nuevo.tercerElemento,tercero);
	nuevo.numeroTerceto = contadorTercetos;
	//printf("%d %s %s %s\n",nuevo.numeroTerceto,nuevo.primerElemento,nuevo.segundoElemento,nuevo.tercerElemento);
	insertar_en_lista_terceto(&lista_terceto,&nuevo);
  	contadorTercetos++;
  	return nuevo.numeroTerceto;
}

void guardarTercetosEnArchivo(t_lista_terceto *pl){
  FILE * pf = fopen("intermedia.txt","wt");

  while(*pl) {
		fprintf(pf,"%d (%s,%s,%s) \n", (*pl)->info.numeroTerceto, (*pl)->info.primerElemento, (*pl)->info.segundoElemento, (*pl)->info.tercerElemento);
		pl=&(*pl)->pSig;
  }
  
  fclose(pf);
} 
