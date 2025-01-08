#include <stdio.h>

int main(){

    char nombre[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int cantidad[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    float precio[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Bucle para nombre

    for (int i = 0; i < 10; i++){
        printf("Introduce el nombre: \n");
        scanf("%s", nombre);
    }
    // Bucle para cantidad
    for (int j = 0; j < 10; j++){
        printf("Introduce la cantidad de producto: \n");
        scanf("%d", cantidad);
    }
    // Bucle para precio
    for (int z = 0; z < 10; z++){
        printf("Introduce el precio del producto: \n");
        scanf("%f", precio);
    }
    
    // Bucle para imprimir todo
     mostrar();


    return 0;
}

void mostrar(){
    printf("Productos: %s", nombre[i]);
}