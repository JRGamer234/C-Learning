#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Hacer una funcion que reciba un array de numeros enteros y devuelva la suma y resta alterna de sus celdas.
    Ejemplo: En el array 120 9 5 2 66 4 se operaria 120 - 9 + 5 - 2 + 66 - 4 = 176
    La funcion devuelve 176
*/

int sumaResta(int *array, int size){
    int result = 0;
    for(int i = 0; i < size; i++){
        if(i % 2 == 0){
            result += array[i];
        }else{
            result -= array[i];
        }
    }
    return result;
}

/*
    Funcion que reciba un mapa de caracteres 
*/
int main(){
    int array[6];
    printf("Introduce 6 numeros del array: ");
    for(int i = 0; i < 6; i++){
        scanf("%d", &array[i]);
    }
    int size = sizeof(array) / sizeof(array[0]);
    printf("Resultado: %d\n", sumaResta(array, size));
    return 0;
}