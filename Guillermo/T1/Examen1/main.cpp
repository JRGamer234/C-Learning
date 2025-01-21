#include <iostream>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	/*Ejercicio 1
		Poner un nombre y que salga asi:
		########
		#nombre#
		########
	*/
/*	char nombre[20];
    printf("Introduce tu nombre: ");
    scanf("%s", nombre);

    //Arriba
    for (int i = 0; i < strlen(nombre) + 2; i++) {
        printf("#");
    }
    printf("\n");

    // Nombre
    printf("#%s#\n", nombre);

    //Abajo
    for (int i = 0; i < strlen(nombre) + 2; i++) {
        printf("#");
    }
    printf("\n");*/
    
    /*Ejercicio 2
    	Pedir 10 numeros al usuario y comprobar si los numeros son la secuencia 0-9 incluyendo si están desordenados.
    *//*
    int numero = 0;
    
    for( int i= 0; i < 10; i++){
    	printf("Introduce un numero: ");
    	scanf("%d", &numero);
	}
    */
    
    /*Ejercicio 3
    	Pedir 2 numeros y el tercero es aleatorio, poder hacer operaciones de "+" , "-", "/", "*" y poder salir.
    */
    
    int x, y, z, opcion=0;
    srand(time(NULL));
	z = rand() % 100;
   do{
    printf("\nIntroduce un numero x: ");
    scanf("%d", &x);
    printf("\nIntroduce un numero y: ");
    scanf("%d", &y);
    printf("\nLos numeros son x= %d, y= %d, z= %d \n",x ,y ,z);
    
    printf(" 1)Suma\n 2)Resta\n 3)Division\n 4)Multiplicacion\n 5)Salir\n");
    scanf("%d", &opcion);
	switch(opcion){
		case 1:{
			int suma = x + y + z;
			printf("La suma es = %d", suma);
			break;
		}
			
		case 2:{
			int resta = x - y - z;
			printf("La resta es = %d", resta);
			break;
		}
		case 3:{
			if (y == 0 || z == 0) {
                    printf("Error: División por cero.\n");
                } else {
                    float division = x / y / z;
                    printf("La division es = %.2f\n", division);
                }
                break;
		}
		case 4:{
			int multi = x * y * z;
			printf("La multiplicacion es = %d", multi);
			break;
		}
		case 5:{
			printf("Saliendo...");
			break;
		}
		default:{
			printf("Error");
			break;
		}
			
	}
}while(opcion != 5);
    
	
	return 0;
}
