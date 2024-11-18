#include <stdio.h>
#include <stdlib.h>

int main(){

// Programa que solicite dos arrays de 10 posiciones numericas
// y sea capaz de almacenar en un tercer array la suma de sus celdas
// EJ:            9573162310
//                 0413734235
//                 9986896545
    int i;
    int numeros1[10], numeros2[10], suma[10];

    printf("Cadena1: \n");
    for (i = 0; i < 10; i++) {
        printf("Introduce número: \n");
        scanf("%d", &numeros1[i]);
    }
    printf("Cadena2: \n");
    for (i = 0; i < 10; i++) {
        printf("Introduce número: \n");
        scanf("%d", &numeros2[i]);
    }


    // Opcional: Mostrar los números introducidos
    printf("Números introducidos cadena1:\n");
    for (i = 0; i < 10; i++) {
        printf("%d -", numeros1[i]);
    }
    printf("\n");
    printf("Números introducidos cadena2:\n");
    for (i = 0; i < 10; i++) {
        printf("%d -", numeros1[i]);
    }
    printf("\n");
    printf("Suma:\n");
    for (i = 0; i < 10; i++) {
        suma[i] = numeros1[i] + numeros2[i];
        printf("%d -", suma[i]);
    }
    printf("\n");

    

// Programa que sea capaz de detectar la secuencia 1 2 3
// en un array numerico de 10 posiciones
// Ej: 9595123234 --->Por pantalla se devuelve: SI, ESTA LA SECUENCIA
// Ej: 9595023234 --->Por pantalla se devuelve: NO, ESTA LA SECUENCIA

// Hacer un programa parecido al anterior, donde se detecte
// la secuencia 123 pero esta vez en un numero entero
// Ej: 91235 --->Por pantalla se devuelve: SI, ESTA LA SECUENCIA
// Ej: 21379 --->Por pantalla se devuelve: NO, ESTA LA SECUENCIA


return 0;
}