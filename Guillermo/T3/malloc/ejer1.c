#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int dato;
    struct nodo *next;
} Nodo;

Nodo* AnadirNodoFinal(Nodo *miLE, int d);
Nodo* BorrarPrimerNodo(Nodo *miLE);
void ImprimirLista(Nodo *miLE);

int main(){
    Nodo *lista = NULL;

    lista = AnadirNodoFinal(lista, 1);
    lista = AnadirNodoFinal(lista, 2);
    lista = AnadirNodoFinal(lista, 3);

    printf("Lista original:\n");
    ImprimirLista(lista);

    lista = BorrarPrimerNodo(lista);

    printf("Después de borrar el primer nodo:\n");
    ImprimirLista(lista);

    return 0;
}

Nodo* AnadirNodoFinal(Nodo *miLE, int d){
    Nodo *aux;

    if(miLE == NULL){
        miLE = (Nodo*)malloc(sizeof(Nodo));
        miLE->dato = d;
        miLE->next = NULL;
        return miLE;
    }

    aux = miLE;

    while(aux->next != NULL){
        aux = aux->next;
	}
    aux->next = (Nodo*)malloc(sizeof(Nodo));
    aux->next->dato = d;
    aux->next->next = NULL;

    return miLE;
}

Nodo* BorrarPrimerNodo(Nodo *miLE){
    if (miLE == NULL){
        return NULL;
	}
    Nodo* temp = miLE;
    miLE = miLE->next;
    free(temp);

    return miLE;
}

void ImprimirLista(Nodo *miLE){
    Nodo* aux = miLE;
    while (aux != NULL){
        printf("%d -> ", aux->dato);
        aux = aux->next;
    }
    printf("NULL\n");
}

