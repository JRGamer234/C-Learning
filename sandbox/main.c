#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	//Haz un programa que escriba los 10 primeros números naturales.
	int i = 1;
	
	while(i <= 10){
		printf("Numero: %i \n", i );
		i++;
	}
	
	//Haz un programa que pida un número entero al usuario y desde ESE número, que escriba los 10 siguientes números naturales.
	
	int num;
	
	printf("Dime un numero: ");
	scanf("%i", &num);
	int suma = num +10;
	
	while(num <= suma){
		printf("Numero: %i \n", num);
		num++;
	}
	
	//Haz un programa que imprima los 10 primeros números pares.
	int num1;
    for(num1 = 0; num1 <= 18; num1 += 2) {
        printf("%i\n", num1);
    }
	//Haz un programa que imprima los 10 primeros números impares
	
	
	//Haz un programa que pida un número positivo y escriba todos los números hasta llegar a cero.
	int num3;
		printf("Introduce un numero para llegar a 0: ");
		scanf("%i", &num3);
		if(num3 < 0){
			printf("ERROR");
		}else{
			while(numero3 >= 0){
				printf("Numero: %i", num3);
				--num3;
			}
	
		}
		
	//Modifica el programa de la historia interactiva de manera que cada vez que el personaje enuentre un final “malo” pierda una vida. Si se queda a 0 vidas, decreta final de programa lamentando su final.

	
	
	
	
	return 0;
}
