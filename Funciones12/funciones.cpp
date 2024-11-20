#include <iostream>
#include <cctype>
#include <stdio.h>
#include <cstdio>

/*  programa que nos muestre el siguiente menú:
        1. Convertir de mayúscula a minúscula
        2. Convertir de minúscula a mayúscula
        3. Sumas 2 números
        4. Restar 2 números
        5. Dividir 2 números
        6. Multiplicar 2 números
        7. Salir
        Cada vez que ejecutemos una opción tiene que limpiar pantalla y volver
        al menú hasta que el usuario introduzca un 7 para terminar el programa
    */
void mayuminu(){
    char letra;
            printf("Introduce una letra mayúscula: ");
            scanf(" %c", &letra); 
            if (isupper(letra)) {
                letra = tolower(letra);
                printf("En minúscula: %c\n", letra);
            } else {
                printf("ERROR, no es mayúscula\n");
            }
}
void minumayus(){
    char letra;
            printf("Introduce una letra minúscula: ");
            scanf(" %c", &letra);
            if (islower(letra)) {
                letra = toupper(letra);
                printf("En mayúscula: %c\n", letra);
            } else {
                printf("ERROR, no es minúscula\n");
            }
}

void suma(){
    double num1, num2;
            printf("Introduce dos números para sumar: ");
            scanf("%lf %lf", &num1, &num2);
            printf("La suma es: %.2lf\n", num1 + num2);
}

void resta(){
    double num1, num2;
            printf("Introduce dos números para restar: ");
            scanf("%lf %lf", &num1, &num2);
            printf("La resta es: %.2lf\n", num1 - num2);
}

void dividir(){
    double num1, num2;
            printf("Introduce dos números para dividir: ");
            scanf("%lf %lf", &num1, &num2);
            if (num2 != 0) {
                printf("La división es: %.2lf\n", num1 / num2);
            } else {
                printf("Error: No se puede dividir entre cero.\n");
            }
}
void multiplicar(){
    double num1, num2;
            printf("Introduce dos números para multiplicar: ");
            scanf("%lf %lf", &num1, &num2);
            printf("La multiplicación es: %.2lf\n", num1 * num2);
}

int main(){
    int opcion;
    do {
        printf("===== MENU =====\n");
        printf("1. Convertir de mayúscula a minúscula\n");
        printf("2. Convertir de minúscula a mayúscula\n");
        printf("3. Sumar 2 números\n");
        printf("4. Restar 2 números\n");
        printf("5. Dividir 2 números\n");
        printf("6. Multiplicar 2 números\n");
        printf("7. Salir\n");
        printf("Selecciona una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
        case 1: {
            mayuminu();
            break;
        }
        case 2: {
            minumayus();
            break;
        }
        case 3: {
            suma();
            break;
        }
        case 4: {
            resta();
            break;
        }
        case 5: {
            dividir();
            break;
        }
        case 6: {
            multiplicar();
            break;
        }
        case 7:
            printf("Saliendo...\n");
            break;
        default:
            printf("ERROR\n");
        }
        printf("\n");
    } while (opcion != 7);

    return 0;
}