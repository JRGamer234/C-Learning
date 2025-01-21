#include <stdio.h>
#include <string.h>

/*1-Procedimiento que pinte un mensaje por pantalla enmarcado en asteriscos*/
int pintarMensaje()
{
    char nombre[50];
    printf("Introduce tu nombre: ");
    scanf("%s", nombre);

    // Arriba
    for (int i = 0; i < strlen(nombre) + 2; i++)
    {
        printf("#");
    }
    printf("\n");

    // Nombre
    printf("#%s#\n", nombre);

    // Abajo
    for (int i = 0; i < strlen(nombre) + 2; i++)
    {
        printf("#");
    }
    printf("\n");
}
/*2-Función que devuelva la media de dos números.*/
void Media(float n1, float n2, float *r)
{
    *r = (n1 + n2) / 2;
}

/*3-Función que devuelva la media de un array de números (quizás necesites un parámetro que diga cuantos números de ese array intervengan en esa media)*/
float calcularMedia(int array[], int cantidad){
    if (cantidad <= 0)
    {
        return 0; // Evitar división por cero
    }
    int suma = 0;

    // Sumar
    for (int i = 0; i < cantidad; i++)
    {
        suma += array[i];
    }

    return (float)suma / cantidad;
}
/*4-Función que devuelva el último caracter de una palabra.*/

char UltimoCaracter(char palabra[]){
    return palabra[strlen(palabra) - 1];
}
/*5-Procedimiento que Imprima cualquier tablero de caracteres de un array doble (puedes especificar con parámetros de entrada aparte las filas/columnas del array).*/



/*6-Función que devuelva verdadero o falso si un número es divisible por otro.*/

/*7-Función que devuelva verdadero o falso si un número es primo.*/

/*8-Función que devuelva el menor número de un array.*/

/*9-Encapsula en una función el algoritmo del Palíndromo.*/

/*10-Procedimiento que reciba una palabra y se sustituyan sus vocales por otra letra pasada por parámetro.*/

/*11-Función/Procedimiento que ordene un array de números de menor a mayor*/


/* ================================== */
/* ====== Resultados con MAIN ======= */
/* ================================== */
void main(){
    // 1
    pintarMensaje();

    // 2
    float a, b, resultado;

    a = 7;
    b = 6;

    Media(a, b, &resultado);
    printf("%f", resultado);
    printf("\n");
    // 3
    int numeros[] = {10, 20, 30, 40, 50};
    int longitud = 5;

    // Calcular media
    float mediaTotal = calcularMedia(numeros, longitud);
    printf("Media de todos los números: %.2f\n", mediaTotal);

    printf("\n");
    // 4
    char palabra[100];
    
    printf("Introduce una palabra: ");
    scanf("%s", palabra);
    
    char ultimo = UltimoCaracter(palabra);
    
    printf("El ultimo caracter de %s es: %c\n", palabra, ultimo);
    
    //5


}
