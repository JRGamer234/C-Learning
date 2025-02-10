#include <stdio.h>

int main(){

    int numero = 4;
    int *numero1;

    numero1 = &numero;

    printf("%d %d %d\n", *numero1, numero, &numero); // contenido direccion de memoria, contenido del numero, direccion de memoria donde se almacena.

    *numero1 = 6;

    printf("%d %d %d\n", *numero1, numero, numero1); 

}