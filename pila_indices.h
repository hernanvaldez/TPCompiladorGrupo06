#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct s_indice{
             int indice;
             int tipo;
           }t_indice;

typedef struct nodo_indice{
             t_indice info;
             struct nodo_indice *ant;
           }t_nodo_pila;

typedef struct pila{
            t_nodo_pila *prim;
           }t_pila;
		   
//Declaracion de funciones
void iniciarPila(t_pila *p);
int pilaVacia(t_nodo_pila *p);
t_nodo_pila *pilaLLena();
void apilar(t_pila *p, int indice, int tipo);
int sacarDePila(t_pila *p);
int verTipoTope(t_pila *p);
int verIndiceTope(t_pila *p);

//Desarrollo de funciones

void iniciarPila(t_pila *p)
{
 p->prim = NULL;

}

int pilaVacia(t_nodo_pila *p)
{
 if(p==NULL)
  return 1;
 else
  return 0;
}

t_nodo_pila *pilaLLena()
{
 t_nodo_pila *q;
 q=(t_nodo_pila*)malloc(sizeof(t_nodo_pila));
 return q;
}

void apilar(t_pila *p, int indice, int tipo)
{
   t_nodo_pila *nuevo;
   if((nuevo=pilaLLena())==NULL)
   {
    printf("Pila de indices llena");
	exit(1);
   }else{
        nuevo->info.tipo = tipo;
		nuevo->info.indice = indice;

        if(pilaVacia(p->prim))
         nuevo->ant=NULL;
        else{
             nuevo->ant= p->prim;
            }
        p->prim = nuevo;
    }

}
int sacarDePila(t_pila *p)
{
 t_nodo_pila *aux;
 int indice;
 if(pilaVacia(p->prim))
 {
	printf("Pila vacia sacarDePila\n");
	return 0;
 }
 else
     {
      indice = p->prim->info.indice;
      aux = p->prim;
      p->prim = p->prim->ant;
      free(aux);
	  return indice;
     }
}

int verTipoTope(t_pila *p)
{
	if(pilaVacia(p->prim))
 {
	printf("Pila vacia verTipoTope\n");
	return 0;
 }
 return  (p->prim->info.tipo);
}

int verIndiceTope(t_pila *p)
{
	if(pilaVacia(p->prim))
 {
	printf("Pila vacia verIndiceTope\n");
	return 0;
 }
 return  (p->prim->info.indice);
}