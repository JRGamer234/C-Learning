#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	/*
		Realizar un programa que pida al usuario dos números por teclado y después solicite que se escoja de entre 4 operaciones: sumar, restar, multiplicar o dividir.
		En función de lo elegido se mostrará por pantalla el resultado de la operación.
		Se debe permitir la repetición del programa, dando opción por pantalla al usuario de si "desea volver a hacer otra operación".
		Se debe vigilar que si el usuario mete como segundo número un cero y además elige una división el programa le permita informarle en vez de fallar.
	*/
	int opcion, num1 = 0, num2 = 0, suma, resta, multi, divis;
	float resultado;
	
	do{
		
		
	printf("**********************************\n");
    printf("*         CALCULADORA            *\n");
    printf("**********************************\n");
    printf("*  1. Sumar                      *\n");
    printf("*  2. Restar                     *\n");
    printf("*  3. Multiplicar                *\n");
    printf("*  4. Dividir                    *\n");
    printf("*  5. Salir                      *\n");
    printf("**********************************\n");
    
    printf("Selecciona una opcion: \n");
    scanf("%d", &opcion);
	
	if (opcion == 5) {
        printf("Saliendo de la calculadora...\n");
        break;
	}
	if (opcion > 5){
		printf("ERROR");
		break;
	}
	
	printf("Introduce un número:");
	scanf("%d", &num1);
	printf("Introduce otro número:");		
	scanf("%d", &num2);
	
	suma = num1 + num2;
	resta = num1 - num2;
	multi = num1 * num2;
	divis = num1 / num2;
	
	switch(opcion){
		case 1:
			printf("El resultado de la suma es: %d\n", suma);
			break;
		case 2:
			printf("El resultado de la resta es: %d\n", resta);
			break;
		case 3:
			printf("El resultado de la multiplicacion es: %d\n", multi);
			break;
		case 4:
			if (num2 != 0) {
                    resultado = num1 / num2;
                    printf("El resultado de la división es: %.2f\n", resultado);
                } else {
                    printf("Error: No se puede dividir entre cero.\n");
                }
			break;
		default:
			printf("ERROR\n No has sellecionado algo válido.");
	}
    
	}
	while(opcion != 5);
	
	return 0;
}
