#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){

/*-Programa que reciba dos palabras y saque una tercera alternando sus letras. Si las palabras tienen diferente longitud, la cadena más larga se imprimirá hasta el final tras agotar las letras de la palabra corta.
Ej: "poblado" y "ciudadela" traen a la salida: "pcoibuldaaddoela"
*/

int i, j;
char palabra1[100], palabra2[100], palabra3[200]

printf("Introduce una palabra: \n");
scanf("%s", palabra1);
printf("Introduce otra palabra: \n");
scanf("%s", palabra2);

for (i = 0; i < length(palabra1); i++)
{
    if(palabra1[i] != '\0'){
        palabra3[j] = palabra1[i];
        j++;
    }
    if (palabra2[i] != '\0'){
    {
        palabra3[j] = palabra2[i];
        j++;
    }
        
}



/*
-Programa que pida introducir dos valores de la clásica ecuación Espacio = Tiempo x Velocidad. Dándole a elegir al usuario que dos variables va a leer, y calcular la tercera.
Solicitar la repetición del programa, teniendo en cuenta que los valores calculados anteriormente sean almacenados de alguna forma y se vaya actualizando una media de las tres variables por separado. Mostrar dichas medias cada iteración.
*/


/*
-Divisor de cadenas:
Programa que pida una palabra y un numero. A la salida se debe dividir la palabra en dos cadenas diferentes por la posición indicada en el número
Ej: "ecosistema" y el número 4
A la salida imprimo dos cadenas "ecos" y "istema"
*/




}