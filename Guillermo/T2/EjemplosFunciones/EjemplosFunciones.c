#include <stdio.h>

int main(){
    /*
    -Función que devuelva el triple de un número
    -Procedimiento que pinte por pantalla un nombre pasado por parámetro seguido de la expresión “buen amigo, mejor persona.” 
    -Función a la que le pases peso y altura y te devuelva el IMC (índice de masa corporal)
    -Convierte en un procedimiento el problema de la pirámide de asteriscos (Pasa su altura por parámetro)
    -Realiza tu propia función LONGITUD, que devuelva el número de caracteres de una cadena.
    -Función que devuelva true o false, dependiendo de si el parámetro que le has pasado es una vocal o no lo es.
    */

//Función que devuelva el triple de un número

    triple();
    
}

int triple(int num){
    printf("Ingrese un número: ");
    scanf("%d", &num);
    printf("El triple de %d es: %d\n", num, num*3);
}