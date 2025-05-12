#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int dato;
    struct nodo *next;
} Nodo;

Nodo* AnadirNodoFinal(Nodo *miLE, int d);
Nodo* BorrarPrimerNodo(Nodo *miLE);
Nodo* BorrarFinalNodo(Nodo *miLE);
Nodo* SustituirNodos(Nodo* miLE);
void ImprimirLista(Nodo *miLE);

int main(){
    Nodo *lista = NULL;

    lista = AnadirNodoFinal(lista, 1);
    lista = AnadirNodoFinal(lista, 2);
    lista = AnadirNodoFinal(lista, 3);
    lista = AnadirNodoFinal(lista, 4);

    printf("Lista original:\n");
    ImprimirLista(lista);

    lista = SustituirNodos(lista); // para borrar el último nodo hay que cambiar la funcion
    
    printf("Despu�s de borrar el primer nodo:\n");
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

Nodo* BorrarFinalNodo(Nodo *miLE){
    Nodo *aux;
    
    aux = miLE;
    while(aux->next->next != NULL){
        aux = aux->next;
    }
    free(aux->next);
    aux->next = NULL;

    return miLE;
}

Nodo* SustituirNodos(Nodo* miLE){
    Nodo* segundo = miLE->next;
    Nodo* aux = miLE;
    
    while (aux->next->next != NULL) {
        aux = aux->next;
    }
    Nodo* ultimo = aux->next;

    int temp = segundo->dato;
    segundo->dato = ultimo->dato;
    ultimo->dato = temp;

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

