#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int dato;
    struct nodo *next;
} Nodo;

Nodo* AnadirNodo(Nodo *miLE, int d)
{
    Nodo *aux;
   
    aux = (Nodo*) malloc(sizeof(Nodo));
    aux->dato = d;
    aux->next = miLE;
    return aux;
}
void ImprimirLE(Nodo *miLE)
{
    Nodo *aux;
    aux = miLE;
   
    if(miLE == NULL)
    {
        printf("Lista vacia\n");
        return;
    }
    while(aux->next != NULL)
    {
        printf("%d -->",aux->dato);
        aux = aux->next;
    }
    printf("%d --> //",aux->dato);
   
}

int main(int argc, char *argv[])
{
    Nodo *listaE = NULL;
   
    listaE = AnadirNodo(listaE,9);
    listaE = AnadirNodo(listaE,7);
    listaE = AnadirNodo(listaE,5);
   
    ImprimirLE(listaE);
   
    return 0;
}