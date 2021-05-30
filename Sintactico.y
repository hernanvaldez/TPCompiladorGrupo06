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
%token INLIST

%token COMA PUNTO_COMA DOS_PUNTOS
%token CORCHA CORCHC PARA PARC LLA LLC

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
	programa                                    {printf("Compilacion Exitosa\n");};
 
programa:
	seccion_declaracion bloque_cod              {printf("Regla 1: programa -> seccion_declaracion bloque_cod\n");}
	|	bloque_cod                              {printf("Regla 2: programa -> bloque_cod\n");};

 /* Declaracion de variables */

seccion_declaracion:
	DECVAR bloque_dec ENDDEC                    {printf("Regla 3: seccion_declaracion -> DECVAR bloque_dec ENDDEC\n");};        

bloque_dec:
	bloque_dec declaracion                      {printf("Regla 4: bloque_dec -> bloque_dec declaracion\n");}        
	| declaracion                               {printf("Regla 5: bloque_dec -> declaracion\n");};

declaracion:
	lista_id DOS_PUNTOS t_dato                  {printf("Regla 6: declaracion -> lista_id DOS_PUNTOS t_dato\n");};

lista_id:	
	lista_id COMA ID                            {
	                                            strcpy(dato.nombre, yylval.string_val);
	                                            strcpy(dato.valor, "");
	                                            strcpy(dato.tipodato, "");
	                                            dato.longitud = 0;
	                                            insertar_en_ts(&lista_ts, &dato);
	                                            printf("Declaracion: %s\n",yylval.string_val );printf("Regla 7: lista_id -> lista_id COMA ID\n");}
	| ID                                        {
	                                            strcpy(dato.nombre, yylval.string_val);
	                                            strcpy(dato.valor, "");
	                                            strcpy(dato.tipodato, "");
	                                            dato.longitud = 0;
	                                            insertar_en_ts(&lista_ts, &dato);
	                                            printf("Declaracion: %s\n",yylval.string_val);printf("Regla 8: lista_id -> ID\n");};
	
t_dato:
	ENTERO                                      {printf("Regla 9: t_dato -> ENTERO\n");}
	| REAL                                      {printf("Regla 10: t_dato -> REAL\n");}
	| STRING                                    {printf("Regla 11: t_dato -> STRING\n");};

 /* codigo */

bloque_cod:
	bloque_cod sentencia                        {printf("Regla 12: bloque_cod -> bloque_cod sentencia\n");}
	| sentencia                                 {printf("Regla 13: bloque_cod -> sentencia\n");};

sentencia:
	asignacion                                  {printf("Regla 14: sentencia -> asignacion\n");}
	| seleccion                                 {printf("Regla 15: sentencia -> seleccion\n");}
	| iteracion                                 {printf("Regla 16: sentencia -> iteracion\n");}
	| salida                                    {printf("Regla 17: sentencia -> salida\n");}
	| entrada                                   {printf("Regla 18: sentencia -> entrada\n");};
	
asignacion:
	ID OP_ASIG expresion                        {printf("Regla 19: asignacion -> ID OP_ASIG expresion\n");}
	| ID OP_ASIG asignacion                     {printf("Regla 20: asignacion -> ID OP_ASIG asignacion\n");};
	
 seleccion:
	bloque_if 				%prec NO_ELSE       {printf("Regla 21: seleccion -> bloque_if\n");}
	| bloque_if bloque_else                     {printf("Regla 22: seleccion -> bloque_if bloque_else\n");};

bloque_if:
	IF PARA condicion PARC sentencia            {printf("Regla 23: bloque_if -> IF PARA condicion PARC sentencia\n");}
	| IF PARA condicion PARC LLA bloque_cod LLC {printf("Regla 24: bloque_if -> IF PARA condicion PARC LLA bloque_cod LLC\n");};

bloque_else:
	ELSE sentencia                              {printf("Regla 25: bloque_else -> ELSE sentencia\n");}
	| ELSE LLA bloque_cod LLC                   {printf("Regla 26: bloque_else -> ELSE LLA bloque_cod LLC\n");};

iteracion:
	WHILE PARA condicion PARC sentencia             {printf("Regla 27: iteracion -> WHILE PARA condicion PARC sentencia\n");}
	| WHILE PARA condicion PARC LLA bloque_cod LLC  {printf("Regla 28: iteracion -> WHILE PARA condicion PARC LLA bloque_cod LLC\n");};
	
condicion:
	comparacion                                 {printf("Regla 29: condicion -> comparacion\n");}
	| comparacion AND comparacion               {printf("Regla 30: condicion -> comparacion AND comparacion\n");}
	| comparacion OR comparacion                {printf("Regla 31: condicion -> comparacion OR comparacion\n");}
	| NOT comparacion                           {printf("Regla 32: condicion -> NOT comparacion\n");};
	
comparacion:
	expresion comparador expresion              {printf("Regla 33: comparacion -> expresion comparador expresion\n");}
	| inlist                                    {printf("Regla 34: comparacion -> inlist\n");};

inlist:
	INLIST PARA ID PUNTO_COMA CORCHA lista_expr CORCHC PARC         {printf("Regla 35: inlist -> INLIST PARA ID PUNTO_COMA CORCHA lista_expr CORCHC PARC\n");};
	
lista_expr:
	lista_expr PUNTO_COMA expresion             {printf("Regla 36: lista_expr -> lista_expr PUNTO_COMA expresion\n");}
	| expresion                                 {printf("Regla 37: lista_expr -> expresion\n");};

comparador:
	MENOR_IGUAL                                 {printf("Regla 38: comparador -> MENOR_IGUAL\n");}
	| MAYOR_IGUAL                               {printf("Regla 39: comparador -> MAYOR_IGUAL\n");}
	| MENOR                                     {printf("Regla 40: comparador -> MENOR\n");}
	| MAYOR                                     {printf("Regla 41: comparador -> MAYOR\n");}
	| IGUAL                                     {printf("Regla 42: comparador -> IGUAL\n");}
	| DISTINTO                                  {printf("Regla 43: comparador -> DISTINTO\n");};
	
expresion:
	expresion OP_SUMA termino                   {printf("Regla 44: expresion -> expresion OP_SUMA termino\n");}
	| expresion OP_RESTA termino                {printf("Regla 45: expresion -> expresion OP_RESTA termino\n");}
	| termino                                   {printf("Regla 46: expresion -> termino\n");}
	| OP_RESTA termino                          {printf("Regla 47: expresion -> OP_RESTA termino\n");};
	
termino:
	termino OP_MULT factor                      {printf("Regla 48: termino -> termino OP_MULT factor\n");}
	| termino OP_DIV factor                     {printf("Regla 49: termino -> termino OP_DIV factor\n");}
	| factor                                    {printf("Regla 50: termino -> factor\n");};
	
factor:
	PARA expresion PARC                         {printf("Regla 51: factor -> PARA expresion PARC\n");}
	| ID                                        {
	                                            BuscarEnLista(&lista_ts, yylval.string_val);
	                                            printf("factor ID: %s\n",yylval.string_val);printf("Regla 52: factor -> ID\n");}
												
	| CTE_ENTERA                                {
	                                            // strcpy(d.clave, guion_cadena(yytext));
	                                            strcpy(dato.nombre, yytext);
	                                            strcpy(dato.valor, yytext);
	                                            strcpy(dato.tipodato, "const_Integer");
	                                            dato.longitud = 0;
	                                            insertar_en_ts(&lista_ts, &dato);
	                                            printf("Regla 53: factor -> CTE_ENTERA\n");}
												
	| CTE_REAL                                  {
	                                            strcpy(dato.nombre, yytext);
	                                            strcpy(dato.valor, yytext);
	                                            strcpy(dato.tipodato, "const_Float");
	                                            dato.longitud = 0;
	                                            insertar_en_ts(&lista_ts, &dato);
	                                            printf("Regla 54: factor -> CTE_REAL\n");}
	
	| CTE_STRING                                {				
	                                            dato.longitud = strlen(yytext)-2;
	                                            strcpy(dato.nombre, yytext);
	                                            reemplazar_blancos_por_guiones_y_quitar_comillas(yytext);
	                                            strcpy(dato.valor, yytext);												
	                                            strcpy(dato.tipodato, "const_String");												
	                                            insertar_en_ts(&lista_ts, &dato);
	                                            printf("Regla 55: factor -> CTE_STRING\n");};
	
salida:
	WRITE ID                                    {
	                                            BuscarEnLista(&lista_ts, yylval.string_val);
	                                            printf("Regla 56: salida -> WRITE ID\n");}
	| WRITE CTE_STRING                          {
	                                            dato.longitud = strlen(yytext)-2;
	                                            strcpy(dato.nombre, yytext);
	                                            reemplazar_blancos_por_guiones_y_quitar_comillas(yytext);
	                                            strcpy(dato.valor, yytext);												
	                                            strcpy(dato.tipodato, "const_String");
	                                            insertar_en_ts(&lista_ts, &dato);
	                                            printf("Regla 57: salida -> WRITE CTE_STRING\n");};
	
entrada:
	READ ID                                     {
	                                            BuscarEnLista(&lista_ts, yylval.string_val);
	                                            printf("Regla 58: entrada -> READ ID\n");};

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
