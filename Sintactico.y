%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <conio.h>
	#include <string.h>
	#include <math.h>
	#include "y.tab.h"

	#define TAM 35
	#define DUPLICADO 2
	#define SIN_MEMORIA 3

	int yyerror(char* mensaje);

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
	int compararPorNombre(const void *, const void *);

	void crear_lista(t_lista *p);
	int insertarEnListaEnOrdenSinDuplicados(t_lista *l_ts, t_info *d, t_cmp);

	void crear_ts(t_lista *l_ts);
	int insertar_en_ts(t_lista *l_ts, t_info *d);

	void grabar_lista(t_lista *);
	void reemplazar_blancos_por_guiones_y_quitar_comillas(char *);
	void quitar_comillas(char *);

	t_lista lista_ts;
	t_info dato;

%}

%union {
	int int_val;
	float float_val;
	char *string_val;
}

%token DECVAR ENDDEC
%token ENTERO REAL STRING

%token WHILE IF

%right OP_ASIG
%left AND OR NOT

%left OP_SUMA OP_RESTA
%left OP_MULT OP_DIV

%token MENOR_IGUAL MAYOR_IGUAL MENOR MAYOR 
%token IGUAL DISTINTO

%token COMA PUNTO_COMA DOS_PUNTOS
%token PARA PARC LLA LLC

%right READ
%right WRITE

%token <string_val>ID
%token <float_val>CTE_REAL
%token <int_val>CTE_ENTERA
%token <string_val>CTE_STRING

%start inicio
%nonassoc NO_ELSE 
%nonassoc ELSE

%%		

inicio: 
	programa 	 								{printf("termino compilacion\n");};
 
programa:
	seccion_declaracion bloque_cod 	            {printf("regla 1\n");}
	|	bloque_cod								{printf("regla 2\n");};

 /* Declaracion de variables */

seccion_declaracion:
	DECVAR bloque_dec ENDDEC 					{printf("regla 3\n");};        

bloque_dec:
	bloque_dec declaracion						{printf("regla 4\n");}        
	| declaracion							    {printf("regla 5\n");};

declaracion:
	lista_id DOS_PUNTOS t_dato					{printf("regla 6\n");};

lista_id:	
	ID											{printf("Dec---%s---\n",yylval.string_val);printf("regla 7\n");}
	| lista_id COMA ID							{printf("Dec---%s---\n",yylval.string_val);printf("regla 8\n");};
	
t_dato:
	ENTERO										{printf("regla 9\n");}
	| REAL										{printf("regla 10\n");}
	| STRING									{printf("regla 11\n");};

 /* codigo */

bloque_cod:
	bloque_cod sentencia						{printf("bloque_cod sentencia regla 12\n");}
	| sentencia									{printf("sentencia regla 13\n");};

sentencia:
	asignacion									{printf("asignacion regla 14\n");}
	| seleccion									{printf("seleccion regla 15\n");}
	| iteracion									{printf("iteracion regla 16\n");}
	| salida									{printf("salida regla 17\n");}
	| entrada									{printf("entrada regla 18\n");};
	
asignacion:
	ID OP_ASIG expresion						{printf("regla 19\n");}
	| ID OP_ASIG asignacion						{printf("regla 20\n");};
	
 seleccion:
	bloque_if 				%prec NO_ELSE		{printf("regla 21\n");}
	| bloque_if bloque_else						{printf("regla 22\n");};

bloque_if:
	IF PARA condicion PARC sentencia			{printf("regla 23\n");}
	| IF PARA condicion PARC LLA bloque_cod LLC	{printf("regla 24\n");};

bloque_else:
	ELSE sentencia								{printf("regla 25\n");}
	| ELSE LLA bloque_cod LLC					{printf("regla 26\n");};

iteracion:
	WHILE PARA condicion PARC sentencia				{printf("regla 27\n");}
	| WHILE PARA condicion PARC LLA bloque_cod LLC	{printf("regla 28\n");};
	
condicion:
	comparacion									{printf("regla 29\n");}
	| comparacion AND comparacion				{printf("AND regla 30\n");}
	| comparacion OR comparacion				{printf("OR regla 31\n");}
	| NOT comparacion							{printf("NOT regla 32\n");};
	
comparacion:
	expresion comparador expresion				{printf("comparacion regla 33\n");};

comparador:
	MENOR_IGUAL									{printf("MENOR_IGUAL regla 34\n");}
	| MAYOR_IGUAL 								{printf("MAYOR_IGUAL regla 35\n");}
	| MENOR 									{printf("MENOR regla 36\n");}
	| MAYOR 									{printf("MAYOR regla 37\n");}
	| IGUAL										{printf("IGUAL regla 38\n");}
	| DISTINTO									{printf("DISTINTO regla 39\n");};
	
expresion:
	expresion OP_SUMA termino					{printf("regla 40\n");}
	| expresion OP_RESTA termino				{printf("regla 41\n");}
	| termino									{printf("regla 42\n");};
	
termino:
	termino OP_MULT factor						{printf("regla 43\n");}
	| termino OP_DIV factor						{printf("regla 44\n");}
	| factor									{printf("regla 45\n");};
	
factor:
	PARA expresion PARC							{printf("Parentesis regla 46\n");}
	| ID										{printf("Prog---%s---\n",yylval.string_val);printf("ID regla 47\n");}
	| CTE_ENTERA								{
												
												// strcpy(d.clave, guion_cadena(yytext));
												strcpy(dato.nombre, yytext);
												strcpy(dato.valor, yytext);
												strcpy(dato.tipodato, "const_Integer");
												dato.longitud = strlen(yytext);

												insertar_en_ts(&lista_ts, &dato);
												printf("CTE_ENTERA regla 48\n");}

	| CTE_REAL									{printf("CTE_REAL regla 49\n");}
	| CTE_STRING								{

												// Una funcion que agregue un guion bajo en los espacios al nombre y quitar las comillas
												
												dato.longitud = strlen(yytext)-2;
												strcpy(dato.valor, yytext);
												reemplazar_blancos_por_guiones_y_quitar_comillas(yytext);
												strcpy(dato.nombre, yytext);												
												strcpy(dato.tipodato, "const_String");
												
												insertar_en_ts(&lista_ts, &dato);
												printf("CTE_STRING regla 50\n");};
	
salida:
	WRITE ID									{printf("regla 51\n");}
	| WRITE CTE_STRING							{
												
												// Una funcion que agregue un guion bajo en los espacios al nombre y quitar las comillas
												dato.longitud = strlen(yytext)-2;
												strcpy(dato.valor, yytext);
												reemplazar_blancos_por_guiones_y_quitar_comillas(yytext);
												strcpy(dato.nombre, yytext);												
												strcpy(dato.tipodato, "const_String");												
												
												insertar_en_ts(&lista_ts, &dato);
												printf("regla 52\n");};
	
entrada:
	READ ID										{printf("regla 53\n");};

%%

int main(int argc,char *argv[])
{
  if ((yyin = fopen(argv[1], "rt")) == NULL)
  {
	printf("\nNo se puede abrir el archivo: %s\n", argv[1]);
  }
  else
  {
	crear_ts(&lista_ts);

	yyparse();

	grabar_lista(&lista_ts);
  	fclose(yyin);
  }
  return 0;
}

int yyerror(char* mensaje)
 {
	printf("Error sintactico: %s\n", mensaje );
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

    while(*pl && (cmp=comparar(d, &(*pl)->info))>0)
        pl=&(*pl)->pSig;
    if(cmp==0)
        return DUPLICADO;
    nuevo=(t_nodo*)malloc(sizeof(t_nodo));
    if(!nuevo)
        return SIN_MEMORIA;
    nuevo->info=*d;
    nuevo->pSig=*pl;
    *pl=nuevo;

    return 1;
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