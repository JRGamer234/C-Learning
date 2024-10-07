#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	/*	Programa que nos muestre el siguiente menu:
	
	1.Convertir de mayus a minus
	2.Convertir de minus a mayus
	3.Sumas 2 numeros
	4.Restar 2 numeros
	5.Dividir 2 numeros
	6.Multiplicar 2 numeros
	7.Salir
	
	*/
	
    int opcion;
    char letra;
    int num1, num2;

    do {
        printf("\nMenu:\n");
        printf("1. Convertir de mayus a minus\n");
        printf("2. Convertir de minus a mayus\n");
        printf("3. Sumar 2 numeros\n");
        printf("4. Restar 2 numeros\n");
        printf("5. Dividir 2 numeros\n");
        printf("6. Multiplicar 2 numeros\n");
        printf("7. Salir\n");
        printf("Elige una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Introduce una letra: ");
                scanf(" %c", &letra); 
                if (letra >= 'A' && letra <= 'Z') {
                    printf("Conversion a minuscula: %c\n", letra + 32);
                } else {
                    printf("ERROR: No es una letra mayuscula.\n");
                }
                break;

            case 2:
                printf("Introduce una letra: ");
                scanf(" %c", &letra); 
                if (letra >= 'a' && letra <= 'z') {
                    printf("Conversion a mayuscula: %c\n", letra - 32);
                } else {
                    printf("ERROR: No es una letra minuscula.\n");
                }
                break;

            case 3:
                printf("Introduce un numero: ");
                scanf("%d", &num1);
                printf("Introduce otro numero: ");
                scanf("%d", &num2);
                printf("El resultado es: %d\n", num1 + num2);
                break;

            case 4:
                printf("Introduce un numero: ");
                scanf("%d", &num1);
                printf("Introduce otro numero: ");
                scanf("%d", &num2);
                printf("El resultado es: %d\n", num1 - num2);
                break;

            case 5:
                printf("Introduce un numero: ");
                scanf("%d", &num1);
                printf("Introduce otro numero: ");
                scanf("%d", &num2);
                if (num2 != 0) {
                    printf("El resultado es: %.2f\n", (float)num1 / num2);
                } else {
                    printf("ERROR: No se puede dividir entre 0.\n");
                }
                break;

            case 6:
                printf("Introduce un numero: ");
                scanf("%d", &num1);
                printf("Introduce otro numero: ");
                scanf("%d", &num2);
                printf("El resultado es: %d\n", num1 * num2);
                break;

            case 7:
                printf("Saliendo...\n");
                break;

            default:
                printf("ERROR: Opcion no valida.\n");
                break;
        }

    } while (opcion != 7);

    return 0;
}


