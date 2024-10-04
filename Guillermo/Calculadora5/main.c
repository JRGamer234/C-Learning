#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	/*
		Realizar un programa que pida al usuario dos n�meros por teclado y despu�s solicite que se escoja de entre 4 operaciones: sumar, restar, multiplicar o dividir.
		En funci�n de lo elegido se mostrar� por pantalla el resultado de la operaci�n.
		Se debe permitir la repetici�n del programa, dando opci�n por pantalla al usuario de si "desea volver a hacer otra operaci�n".
		Se debe vigilar que si el usuario mete como segundo n�mero un cero y adem�s elige una divisi�n el programa le permita informarle en vez de fallar.
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
	
	printf("Introduce un n�mero:");
	scanf("%d", &num1);
	printf("Introduce otro n�mero:");		
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
                    printf("El resultado de la divisi�n es: %.2f\n", resultado);
                } else {
                    printf("Error: No se puede dividir entre cero.\n");
                }
			break;
		default:
			printf("ERROR\n No has sellecionado algo v�lido.");
	}
    
	}
	while(opcion != 5);
	
	return 0;
}
