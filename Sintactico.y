%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <conio.h>
	#include <string.h>
	#include <math.h>
	#include "y.tab.h"
	#include "pila_indices.h"
	#include "indice_compatible.h"
	
	#define TAM 35
	#define DUPLICADO 2
	#define SIN_MEMORIA 3
	#define ID_EN_LISTA 4
	
	#define VAR_INTEGER 1
	#define CONST_INTEGER 2
	#define VAR_FLOAT 3
	#define CONST_FLOAT 4
	#define VAR_STRING 5
	#define CONST_STRING 6
	#define COMPARACION 7
	#define ES_AND 1
	#define ES_INLIST 9
	
	int yyerror(char* mensaje);

	extern int yylineno;
	extern char * yytext;

	FILE  *yyin;
	FILE * pfArchivoDataAsm;

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
	
	// Variables auxiliares para insertar el tipo de datos a las variables.
	int contadorVariablesDeclaradas;
	char tipoDeDato[20];
	void insertarTipoDeDato(t_lista *pl, int *cant);

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

	// Variables auxiliares para tercetos //
	int _flagAnd = 0;
	int _aux;

	// +++++++++++++++++ Indices +++++++++++++++++ //

	// Expresion //

	t_pila expresionIndice;
	t_pila terminoIndice;
	t_pila factorIndice;
	t_pila asignacionIndice;
	
	// Iteracion //
	t_pila iteracionIndice;

	// Seleccion //

	t_pila sentenciaIndice;
	t_pila seleccionIndice;
	t_pila bloqueIfIndice;
	t_pila condicionIndice;
	t_pila comparacionIndice;
	t_pila comparadorIndice;

	t_pila pilaDeNumerosDeTercetos;

	// INLIST //
	t_pila expInlistIndice;
	t_pila compInListInd;
	char idAux[20];

	char varAssembleAux[10];

	// INLIST
	char id_inList[TAM];
	
	// Declaracion funciones segunda entrega //

	// Lista

	void crear_lista_terceto(t_lista_terceto *p);
	int	insertar_en_lista_terceto(t_lista_terceto *p, const t_info_terceto *d);
	int buscarEnListaDeTercetosOrdenada(t_lista_terceto *pl, int indiceTerceto, int);

	// Tercetos

	char* crearIndice(int); //Recibe un numero de terceto y lo convierte en un indice
	int crearTerceto(char*, char*, char*); //Se mandan los 3 strings, y se guarda el terceto creado en la lista
										   //La posicion en la lista se lo da contadorTercetos. Variable que aumenta en 1
  	void guardarTercetosEnArchivo(t_lista_terceto *);
	char* negarBranch(char*);	//Recibe el tipo de BRANCH y lo invierte  	
	int verCompatible(char *,int, int);


	// Declaracion funciones tercera entrega //
	void generarCodigoAssembler(t_lista *);
	void generarCodigoAsmCabecera(void);
	void generarCodigoAsmDeclaracionVariables(t_lista *);
	void generarCodigoAsm(void);							   

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
	programa                                    {printf("Compilacion Exitosa\n"); generarCodigoAssembler(&lista_ts);};
 
programa:
	seccion_declaracion bloque_cod              {printf("Regla 1: programa -> seccion_declaracion bloque_cod\n");}
	|	bloque_cod                              {printf("Regla 2: programa -> bloque_cod\n");};

 /* Declaracion de variables */

seccion_declaracion:
	DECVAR bloque_dec ENDDEC                    {printf("Regla 3: seccion_declaracion -> DECVAR bloque_dec ENDDEC\n");}
	| DECVAR ENDDEC                    			{
													printf("Error sintactico en linea %d: DECVAR ENDDEC no puede estar vacio\n", yylineno );
													system ("Pause");
													exit (1);
												};

bloque_dec:
	bloque_dec declaracion                      {printf("Regla 4: bloque_dec -> bloque_dec declaracion\n");}        
	| declaracion                               {printf("Regla 5: bloque_dec -> declaracion\n");};

declaracion:
	lista_id DOS_PUNTOS t_dato                  {
												insertarTipoDeDato(&lista_ts, &contadorVariablesDeclaradas);
												printf("Regla 6: declaracion -> lista_id DOS_PUNTOS t_dato\n");
												};

lista_id:	
	lista_id COMA ID                            {
	                                            strcpy(dato.nombre, yylval.string_val);
	                                            strcpy(dato.valor, "");
	                                            strcpy(dato.tipodato, "");
	                                            dato.longitud = 0;
	                                            if( DUPLICADO == insertar_en_ts(&lista_ts, &dato))
												{
													printf("Error semantico en linea %d: variable duplicada %s\n", yylineno, dato.nombre );
													system ("Pause");
													exit (1);
												}
												contadorVariablesDeclaradas++;
	                                            printf("Declaracion: %s\n",yylval.string_val );printf("Regla 7: lista_id -> lista_id COMA ID\n");}
	| ID                                        {
	                                            strcpy(dato.nombre, yylval.string_val);
	                                            strcpy(dato.valor, "");
	                                            strcpy(dato.tipodato, "");
	                                            dato.longitud = 0;
	                                            if( DUPLICADO == insertar_en_ts(&lista_ts, &dato))
												{
													printf("Error semantico en linea %d: variable duplicada %s\n", yylineno, dato.nombre );
													system ("Pause");
													exit (1);
												}
												contadorVariablesDeclaradas=1;
	                                            printf("Declaracion: %s\n",yylval.string_val);printf("Regla 8: lista_id -> ID\n");};
	
t_dato:
	ENTERO                                      {
												strcpy(tipoDeDato,"Integer");
												printf("Regla 9: t_dato -> ENTERO\n");
												}
	| REAL                                      {strcpy(tipoDeDato,"Float");
												printf("Regla 10: t_dato -> REAL\n");
												}
	| STRING                                    {
												strcpy(tipoDeDato,"String");
												printf("Regla 11: t_dato -> STRING\n");
												};

 /* codigo */

bloque_cod:
	bloque_cod sentencia                        {printf("Regla 12: bloque_cod -> bloque_cod sentencia\n");}
	| sentencia                                 {printf("Regla 13: bloque_cod -> sentencia\n");};

sentencia:
	asignacion                                  {printf("Regla 14: sentencia -> asignacion\n");
												apilar( &sentenciaIndice , sacarDePila(&asignacionIndice), verTipoTope(&asignacionIndice));}
	| seleccion                                 {printf("Regla 15: sentencia -> seleccion\n");}
	| iteracion                                 {printf("Regla 16: sentencia -> iteracion\n");}
	| salida                                    {printf("Regla 17: sentencia -> salida\n");}
	| entrada                                   {printf("Regla 18: sentencia -> entrada\n");};
	
asignacion:
	ID OP_ASIG expresion                        {printf("Regla 19: asignacion -> ID OP_ASIG expresion\n");
												// verTipoTope mando expresionIndice para completar la funcion
												apilar( &asignacionIndice, crearTerceto("=",$1,crearIndice(_aux=sacarDePila(&expresionIndice))), verCompatible("=",BuscarEnLista(&lista_ts, $1 ),verTipoTope(&expresionIndice)) );
												
													}
	| ID OP_ASIG asignacion                     {printf("Regla 20: asignacion -> ID OP_ASIG asignacion\n");
												// verTipoTope si esta bien
												apilar( &asignacionIndice, crearTerceto("=",$1,crearIndice(_aux)),  verCompatible("=",BuscarEnLista(&lista_ts, $1 ),verTipoTope(&asignacionIndice)) );
												};
	
 seleccion:	
 	bloque_if 	%prec NO_ELSE      				 {
													printf("Regla 21: seleccion -> bloque_if\n");
												}
	| bloque_if bloque_else                     {
													printf("Regla 22: seleccion -> bloque_if bloque_else\n");
												};

bloque_if:
	IF PARA condicion PARC sentencia            {
													if(verTipoTope(&comparacionIndice) == ES_AND)
													{
														buscarEnListaDeTercetosOrdenada(&lista_terceto, sacarDePila(&comparacionIndice), contadorTercetos);
														//_flagAnd=0;
													}																										
													buscarEnListaDeTercetosOrdenada(&lista_terceto, sacarDePila(&comparacionIndice), contadorTercetos);
													printf("Regla 23: bloque_if -> IF PARA condicion PARC sentencia\n");
												}
	| IF PARA condicion PARC LLA bloque_cod LLC {	if(verTipoTope(&comparacionIndice) == ES_AND)
													{
														buscarEnListaDeTercetosOrdenada(&lista_terceto, sacarDePila(&comparacionIndice), contadorTercetos);
														//_flagAnd=0;
													}																										
													buscarEnListaDeTercetosOrdenada(&lista_terceto, sacarDePila(&comparacionIndice), contadorTercetos);
													printf("Regla 24: bloque_if -> IF PARA condicion PARC LLA bloque_cod LLC\n");
												};

bloque_else:
	ELSE 										{ apilar(&comparacionIndice,crearTerceto("BI","" ,""), 0);}
		sentencia                               {
													// Actualizo terceto con BI
													buscarEnListaDeTercetosOrdenada(&lista_terceto, sacarDePila(&comparacionIndice), contadorTercetos);
													printf("Regla 25: bloque_else -> ELSE sentencia\n");
													}
	| ELSE 										{ apilar(&comparacionIndice,crearTerceto("BI","" ,""), 0);}
		LLA bloque_cod LLC                   {
													// Actualizo terceto con BI
													buscarEnListaDeTercetosOrdenada(&lista_terceto, sacarDePila(&comparacionIndice), contadorTercetos);
													printf("Regla 26: bloque_else -> ELSE LLA bloque_cod LLC\n");
													};

// Cambie la regla por conflictos reduce/reduce
iteracion:
	WHILE 											{ apilar( &iteracionIndice , crearTerceto("ET","",""),0);} // Crea una etiqueta, y apila indice para BI al final del while
			bloque_while							;           	
//// Agregue una regla para evitar conflictos en el while
bloque_while:
	PARA condicion PARC sentencia          			{	
														crearTerceto("BI",crearIndice(sacarDePila(&iteracionIndice)),"");
														if(verTipoTope(&comparacionIndice) == ES_AND)
														{
															buscarEnListaDeTercetosOrdenada(&lista_terceto, sacarDePila(&comparacionIndice), contadorTercetos);
															//_flagAnd=0;
														}
														buscarEnListaDeTercetosOrdenada(&lista_terceto, sacarDePila(&comparacionIndice), contadorTercetos);
														printf("Regla 27: iteracion -> WHILE PARA condicion PARC sentencia\n");
													}
	| PARA condicion PARC LLA bloque_cod LLC  		{
														crearTerceto("BI",crearIndice(sacarDePila(&iteracionIndice)),"");
														if(verTipoTope(&comparacionIndice) == ES_AND)
														{
															buscarEnListaDeTercetosOrdenada(&lista_terceto, sacarDePila(&comparacionIndice), contadorTercetos);
															//_flagAnd=0;
														}
														buscarEnListaDeTercetosOrdenada(&lista_terceto, sacarDePila(&comparacionIndice), contadorTercetos);
														printf("Regla 28: iteracion -> WHILE PARA condicion PARC LLA bloque_cod LLC\n");
													};	
////
condicion:
	comparacion                                 {
													printf("Regla 29: condicion -> comparacion\n");
													// Si NO es una comp por INLIST crea el terceto
													// INLIST NO SOPORTA AND, OR y NOT !!!!
													if(!verTipoTope(&comparacionIndice) == ES_INLIST){
														crearTerceto(varAssembleAux,"" ,"");
														apilar(&comparacionIndice, contadorTercetos-1, 0);
														}
													}
	| comparacion 								{
													
													crearTerceto(varAssembleAux,"" ,"");
													apilar(&comparacionIndice, contadorTercetos-1, 0 ); 
													}
		AND comparacion              			{
													crearTerceto(varAssembleAux,"" ,"");
													apilar(&comparacionIndice, contadorTercetos-1, ES_AND ); //Uso el tipo de la pila en vez del flagAnd
													printf("Regla 30: condicion -> comparacion AND comparacion\n");
													}
	| comparacion 								{
													crearTerceto(varAssembleAux,"" ,"");
													apilar(&comparacionIndice, contadorTercetos-1, 0);
													crearTerceto("BI","" ,"");
													apilar(&comparacionIndice, contadorTercetos-1, 0);
													}
		OR comparacion                			{
													// Actualizo terceto con BI
													buscarEnListaDeTercetosOrdenada(&lista_terceto, sacarDePila(&comparacionIndice), contadorTercetos+1);
													// Actualizo terceto de la 1ra CMP del OR
													buscarEnListaDeTercetosOrdenada(&lista_terceto, sacarDePila(&comparacionIndice), contadorTercetos-1);
													crearTerceto(varAssembleAux,"" ,"");
													apilar(&comparacionIndice, contadorTercetos-1, 0);
													printf("Regla 31: condicion -> comparacion OR comparacion\n");}
	| NOT comparacion                           {
													crearTerceto(negarBranch(varAssembleAux),"" ,"");
													apilar(&comparacionIndice, contadorTercetos-1, 0);
													printf("Regla 32: condicion -> NOT comparacion\n");};
	
comparacion:
	expresion comparador expresion              {printf("Regla 33: comparacion -> expresion comparador expresion\n");
												// uso esta pila como auxiliar para poder comparar las dos expresiones
												apilar(&pilaDeNumerosDeTercetos, sacarDePila(&expresionIndice), verTipoTope(&expresionIndice));
												//Verifica que la comparacion sea compatible
												verCompatible(varAssembleAux,verTipoTope(&expresionIndice),verTipoTope(&pilaDeNumerosDeTercetos)); 
												//No apilo porque no le encontre uso
												crearTerceto("CMP",crearIndice(sacarDePila(&expresionIndice)),crearIndice(sacarDePila(&pilaDeNumerosDeTercetos)) ); 
												
												//Para el WHILE uso otra pila porque el comparador guarda mal el numero si se anidan sentencias de control
												//apilar(&comparadorIndice,crearTerceto("CMP",crearIndice(sacarDePila(&expresionIndice)),crearIndice(sacarDePila(&pilaDeNumerosDeTercetos)) ), 0);
												//crearTerceto("CMP",crearIndice(sacarDePila(&expresionIndice)),crearIndice(sacarDePila(&pilaDeNumerosDeTercetos)));
												} 
												
	| inlist                                    {
													while(!pilaVacia(compInListInd.prim))
													{
														buscarEnListaDeTercetosOrdenada(&lista_terceto, sacarDePila(&compInListInd), contadorTercetos);													
													}
													printf("Regla 34: comparacion -> inlist\n");};

inlist:
	INLIST PARA ID {strcpy(idAux,yylval.string_val);} 
	PUNTO_COMA CORCHA lista_expr CORCHC PARC	{	
													// Desapilo las expresiones del INLIST y armo las CMP creando por cada una un salto por Verdadero
													while(!pilaVacia(expInlistIndice.prim))
													{
														crearTerceto("CMP",idAux,crearIndice(sacarDePila(&expInlistIndice)));
														apilar(&compInListInd,crearTerceto("BEQ","",""),0);														
													}
													// Al terminar de desapilar creo salto por Falso
													apilar(&comparacionIndice,crearTerceto("BNE","",""),ES_INLIST);													
													printf("Regla 35: inlist -> INLIST PARA ID PUNTO_COMA CORCHA lista_expr CORCHC PARC\n");};
	
lista_expr:
	lista_expr PUNTO_COMA expresion             {	
													// Apilo todas las expresiones de la comparacion INLIST													
													apilar(&expInlistIndice, sacarDePila(&expresionIndice), verTipoTope(&expresionIndice));
													printf("Regla 36: lista_expr -> lista_expr PUNTO_COMA expresion\n");
													}
	| expresion                                 {
													apilar(&expInlistIndice, sacarDePila(&expresionIndice), verTipoTope(&expresionIndice));
													printf("Regla 37: lista_expr -> expresion\n");
													};

comparador:										// Utilice un charAux para guardar su respectivo branch
	MENOR_IGUAL                                 {printf("Regla 38: comparador -> MENOR_IGUAL\n");
												strcpy(varAssembleAux, "BGT");}
	| MAYOR_IGUAL                               {printf("Regla 39: comparador -> MAYOR_IGUAL\n");
												strcpy(varAssembleAux, "BLT");}
	| MENOR                                     {printf("Regla 40: comparador -> MENOR\n");
												strcpy(varAssembleAux, "BGE");}
	| MAYOR                                     {printf("Regla 41: comparador -> MAYOR\n");
												strcpy(varAssembleAux, "BLE");} 
	| IGUAL                                     {printf("Regla 42: comparador -> IGUAL\n");
												strcpy(varAssembleAux, "BNE");}
	| DISTINTO                                  {printf("Regla 43: comparador -> DISTINTO\n");
												strcpy(varAssembleAux, "BEQ");};
	
expresion:
	expresion OP_SUMA termino                   {
													printf("Regla 44: expresion -> expresion OP_SUMA termino\n");
													apilar( &expresionIndice , crearTerceto("+",crearIndice(sacarDePila(&expresionIndice)),crearIndice(sacarDePila(&terminoIndice))), verCompatible("+",verTipoTope(&expresionIndice),verTipoTope(&terminoIndice)) );
													//expresionIndice = crearTerceto("+",crearIndice(expresionIndice),crearIndice(terminoIndice));
												}
	| expresion OP_RESTA termino                {
													printf("Regla 45: expresion -> expresion OP_RESTA termino\n");
													apilar( &expresionIndice , crearTerceto("-",crearIndice(sacarDePila(&expresionIndice)),crearIndice(sacarDePila(&terminoIndice))), verCompatible("-",verTipoTope(&expresionIndice),verTipoTope(&terminoIndice)));
													//expresionIndice = crearTerceto("-",crearIndice(expresionIndice),crearIndice(terminoIndice));
												}
	| termino                                   {
													printf("Regla 46: expresion -> termino\n");
													apilar( &expresionIndice , sacarDePila(&terminoIndice), verTipoTope(&terminoIndice));
													//expresionIndice = terminoIndice;
												}
	| OP_RESTA termino                          {
													printf("Regla 47: expresion -> OP_RESTA termino\n");
													apilar( &expresionIndice , crearTerceto("*",crearIndice(sacarDePila(&terminoIndice)),"-1"), verCompatible("-",verTipoTope(&factorIndice),CONST_INTEGER));
													//expresionIndice = crearTerceto("-",crearIndice(terminoIndice),"");
												};
	
termino:
	termino OP_MULT factor                      {
													printf("Regla 48: termino -> termino OP_MULT factor\n");
													apilar( &terminoIndice , crearTerceto("*",crearIndice(sacarDePila(&terminoIndice)),crearIndice(sacarDePila(&factorIndice))), verCompatible("*",verTipoTope(&terminoIndice),verTipoTope(&factorIndice)));
													//terminoIndice = crearTerceto("*",crearIndice(terminoIndice),crearIndice(factorIndice));
												}
	| termino OP_DIV factor                     {
													printf("Regla 49: termino -> termino OP_DIV factor\n");
													apilar( &terminoIndice , crearTerceto("/",crearIndice(sacarDePila(&terminoIndice)),crearIndice(sacarDePila(&factorIndice))), verCompatible("/",verTipoTope(&terminoIndice),verTipoTope(&factorIndice)));
													//terminoIndice = crearTerceto("/",crearIndice(terminoIndice),crearIndice(factorIndice));
												}
	| factor                                    {
													printf("Regla 50: termino -> factor\n");
													apilar( &terminoIndice , sacarDePila(&factorIndice), verTipoTope(&factorIndice));
													//terminoIndice = factorIndice;
												};
	
factor:
	PARA expresion PARC                         {
													printf("Regla 51: factor -> PARA expresion PARC\n");
													// CrearTerceto
												}

	| ID                                        {
	                                            //BuscarEnLista(&lista_ts, yylval.string_val);
	                                            printf("factor ID: %s\n",yylval.string_val);
												printf("Regla 52: factor -> ID\n");
												apilar( &factorIndice, crearTerceto(yylval.string_val,"",""), BuscarEnLista(&lista_ts, yylval.string_val) );
												//factorIndice = crearTerceto($1,"","");
												}

	| CTE_ENTERA                                {
	                                            // strcpy(d.clave, guion_cadena(yytext));
												char aux [50];
	                                            strcpy(dato.nombre, yytext);
	                                            strcpy(dato.valor, yytext);
	                                            strcpy(dato.tipodato, "const_Integer");
	                                            dato.longitud = 0;
	                                            insertar_en_ts(&lista_ts, &dato);
	                                            printf("Regla 53: factor -> CTE_ENTERA\n");
												apilar( &factorIndice, crearTerceto(yytext,"",""), CONST_INTEGER );
												}

	| CTE_REAL                                  {
												char aux [50];
	                                            strcpy(dato.nombre, yytext);
	                                            strcpy(dato.valor, yytext);
	                                            strcpy(dato.tipodato, "const_Float");
	                                            dato.longitud = 0;
	                                            insertar_en_ts(&lista_ts, &dato);
	                                            printf("Regla 54: factor -> CTE_REAL\n");
												apilar( &factorIndice , crearTerceto(yytext,"",""), CONST_FLOAT);
												// factorIndice = crearTerceto($1,"",""); //Falta pasar $1 a char*
												}

	| CTE_STRING                                {				
	                                            dato.longitud = strlen(yytext)-2;
	                                            strcpy(dato.nombre, yytext);
	                                            reemplazar_blancos_por_guiones_y_quitar_comillas(yytext);
	                                            strcpy(dato.valor, yytext);												
	                                            strcpy(dato.tipodato, "const_String");												
	                                            insertar_en_ts(&lista_ts, &dato);
	                                            printf("Regla 55: factor -> CTE_STRING\n");
												apilar( &factorIndice , crearTerceto(yytext,"",""), CONST_STRING);
												};
	
salida:
	WRITE ID                                    {
	                                            BuscarEnLista(&lista_ts, yylval.string_val);
	                                            printf("Regla 56: salida -> WRITE ID\n");
												crearTerceto("WRT",yylval.string_val,"");}
	| WRITE CTE_STRING                          {
	                                            dato.longitud = strlen(yytext)-2;
	                                            strcpy(dato.nombre, yytext);
	                                            reemplazar_blancos_por_guiones_y_quitar_comillas(yytext);
	                                            strcpy(dato.valor, yytext);												
	                                            strcpy(dato.tipodato, "const_String");
	                                            insertar_en_ts(&lista_ts, &dato);
	                                            printf("Regla 57: salida -> WRITE CTE_STRING\n");
												crearTerceto("WRT",yytext,"");};
	
entrada:
	READ ID                                     {
	                                            BuscarEnLista(&lista_ts, yylval.string_val);
	                                            printf("Regla 58: entrada -> READ ID\n");
												crearTerceto("READ",yylval.string_val,"");};

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
	crear_lista_terceto(&lista_terceto);
	iniciarPila(&expresionIndice);
	iniciarPila(&terminoIndice);
	iniciarPila(&factorIndice);
	iniciarPila(&asignacionIndice);

	iniciarPila(&sentenciaIndice);
	iniciarPila(&seleccionIndice);
	iniciarPila(&bloqueIfIndice);
	iniciarPila(&condicionIndice);
	iniciarPila(&comparacionIndice);
	iniciarPila(&iteracionIndice);
	iniciarPila(&comparadorIndice);

	iniciarPila(&expInlistIndice);
	iniciarPila(&compInListInd);
	
	iniciarPila(&pilaDeNumerosDeTercetos);

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
	return insertarEnListaEnOrdenSinDuplicados(l_ts, d, compararPorNombre);
	
	// Un reinicio de la estructura dato para que vuelva a ser reutilizada sin problemas (quizas no hace falta) .
	//strcpy(d->nombre,"\0");
	//strcpy(d->tipodato,"\0");
	//strcpy(d->valor,"\0");	
	//d->longitud=0;
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

// Inserta el tipo de dato a las variables en la declaracion.
// Recibe la tabla de simbolos, y la cantidad de variables que se insertaron.
// Usa una variable global "char* tipoDeDato", para pasar el tipo de dato que corresponde.
void insertarTipoDeDato(t_lista *pl, int *cant)
{
	if( (*pl)->pSig != NULL )
        insertarTipoDeDato( &(*pl)->pSig , cant);
	if( (*cant) > 0)
	strcpy((*pl)->info.tipodato,tipoDeDato);
	(*cant)--;
}

// Recibe la lista de tabla de simbolos y un id.
// Busca el id si esta devuelve un int que representa el tipo de dato, y si no esta, termina la compilacion por variable sin declarar
int BuscarEnLista(t_lista *pl, char* cadena )
{
    int cmp;

    while(*pl && (cmp=strcmp(cadena,(*pl)->info.nombre))!=0)
        pl=&(*pl)->pSig;
    if(cmp==0)
	{
		if((strcmp("Integer",(*pl)->info.tipodato))==0)
		{
			return VAR_INTEGER;
		}
		if((strcmp("Float",(*pl)->info.tipodato))==0)
		{
			return VAR_FLOAT;
		}
		if((strcmp("String",(*pl)->info.tipodato))==0)
		{
			return VAR_STRING;
		}
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
	strcpy(nuevo.primerElemento,primero);
	strcpy(nuevo.segundoElemento,segundo);
	strcpy(nuevo.tercerElemento,tercero);
	nuevo.numeroTerceto = contadorTercetos;
	//printf("%d %s %s %s\n",nuevo.numeroTerceto,nuevo.primerElemento,nuevo.segundoElemento,nuevo.tercerElemento);
	insertar_en_lista_terceto(&lista_terceto,&nuevo);
  	contadorTercetos++;
  	return nuevo.numeroTerceto;
}

int buscarEnListaDeTercetosOrdenada(t_lista_terceto *pl, int indiceTerceto, int indiceAColocar)
{
    int cmp;
    t_nodo_terceto *aux;
	char segundoElem[TAM];
	printf("-----------------INDICE TERCETO: %d\n",indiceTerceto);

    while(*pl && (cmp = indiceTerceto - (*pl)->info.numeroTerceto) >0)
        pl=&(*pl)->pSig;
    if(*pl && cmp==0)
    {
		// Modifico terceto		
        aux=*pl;        
		strcpy(aux->info.segundoElemento, crearIndice(indiceAColocar));    

        return 1;
    }

    return 0;
}

void guardarTercetosEnArchivo(t_lista_terceto *pl){
  FILE * pf = fopen("intermedia.txt","wt");

  while(*pl) {
		fprintf(pf,"%d (%s,%s,%s) \n", (*pl)->info.numeroTerceto, (*pl)->info.primerElemento, (*pl)->info.segundoElemento, (*pl)->info.tercerElemento);
		pl=&(*pl)->pSig;
  }
  
  fclose(pf);
} 


//Recibe un char* que representa una operacion, y dos int sacados normalmente de las pilas de indices, que representan los tipos de dato de dos operandos.
// Si la operacion es compatible ejemplo "int a = 5" devuelve un int que representa el tipo de dato resultado de la operacion,
// en este caso "int = const_int" devuelve VAR_INTEGER.
// Si la operacon no es compatible, ejemplo "string b = 4", termina la compilacion por tipos incompatibles.
int verCompatible(char *op,int izq, int der)
{
	int tipo=-1;
	if(strcmp(op, "+" ) == 0 )
	{
		tipo = MAT_SUMA[izq][der];
		
	}
	if(strcmp(op, "-" ) == 0 )
	{
		tipo = MAT_RESTA[izq][der];
	}
	if(strcmp(op, "*" ) == 0 )
	{
		tipo = MAT_MULT[izq][der];
	}
	if(strcmp(op, "/" ) == 0 )
	{
		tipo = MAT_DIV[izq][der];
	}
	if(strcmp(op, "=" ) == 0 )
	{
		tipo = MAT_ASIG[izq][der];
	}
	if(strcmp(op, "BEQ" ) == 0 || strcmp(op, "BNE" ) == 0 || strcmp(op, "BLT" ) == 0 || strcmp(op, "BGT" ) == 0 || strcmp(op, "BLE" ) == 0 || strcmp(op, "BGE" ) == 0)
	{
		tipo = MAT_CMP[izq][der];
	}
	
	if( tipo == 0 )
	{
		printf("Error semantico en linea %d: operacion %s con tipos incompatibles\n", yylineno, op );
		system ("Pause");
		exit (1);
	}	
	if( tipo == -1 )
	{
		printf("Error semantico en linea %d: operacion %s incompatible\n", yylineno, op );
		system ("Pause");
		exit (1);
	}	
	return tipo;
}

char* negarBranch(char *branch)
{
	char* branchNOT = (char*) malloc(sizeof(char)*10);;
	if(strcmp(branch,"BGT")==0)
	{
		strcpy(branchNOT,"BLE");
	}

	if(strcmp(branch,"BLT")==0)
	{
		strcpy(branchNOT,"BGE");
	}

	if(strcmp(branch,"BGE")==0)
	{
		strcpy(branchNOT,"BLT");
	}

	if(strcmp(branch,"BLE")==0)
	{
		strcpy(branchNOT,"BGT");
	}

	if(strcmp(branch,"BNE")==0)
	{
		strcpy(branchNOT,"BEQ");
	}

	if(strcmp(branch,"BEQ")==0)
	{
		strcpy(branchNOT,"BNE");
	}
	return branchNOT;
}


/////// ASSEMBLER /////////

void generarCodigoAssembler(t_lista *pl)
{
  generarCodigoAsmCabecera();
  generarCodigoAsmDeclaracionVariables(pl);
  generarCodigoAsm();    
}

// Coloca solo la cabecera en el archivo .ASM
void generarCodigoAsmCabecera(){
	pfArchivoDataAsm = fopen("./Final.asm","wt");
  	fprintf(pfArchivoDataAsm,".MODEL  LARGE \t\t;tipo de modelo de memoria usado\n");
  	fprintf(pfArchivoDataAsm,".386\n");
  	fprintf(pfArchivoDataAsm,".STACK 200h \t\t\t; bytes en el stack\n");
}


// Coloca las variables y constantes de la TS |||| FALTAN AGREGAR EN LA TS LAS VARIABLES AUXILIARES NUESTRAS
void generarCodigoAsmDeclaracionVariables(t_lista *pl){
	char cad_aux[30]="__";
	fprintf(pfArchivoDataAsm,".DATA \t\t\t\t; comienzo de la zona de datos\n"); //Comienza area de datos

	while(*pl){
		if (!strcmp((*pl)->info.tipodato,"const_Integer")||!strcmp((*pl)->info.tipodato,"const_Float")){
        	strcat(cad_aux,(*pl)->info.nombre);
			fprintf(pfArchivoDataAsm, "%-30s\tdd\t\t\t\t%s\n", cad_aux, (*pl)->info.valor);
      	}
		else{
			// Agregue esta condicion porque creo que las String se manejan distinto, pero no lo tengo claro todavia
			if (!strcmp((*pl)->info.tipodato,"const_String")){
        		fprintf(pfArchivoDataAsm, "%-30s\tdb\t\t\t\t%s\n", (*pl)->info.valor, (*pl)->info.nombre);
			}
			else{
				fprintf(pfArchivoDataAsm, "%-30s\tdd\t\t\t\t?\n", (*pl)->info.nombre);
			}
		}
		strcpy(cad_aux,"__");		
		pl=&(*pl)->pSig;
	}
}

void generarCodigoAsm(){
	fprintf(pfArchivoDataAsm, "\n.CODE \n");
	fclose(pfArchivoDataAsm);
}
