#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	/*
	En un mundo circular y bidimensional de 10 x 10, un robot comienza en una posici�n dada por el usuario.
	-El robot, puede moverse en las direcciones: norte, sur, este y oeste.
	-El robot comienza con 100 unidades de gasolina.
	-Cada vez que se mueve una casilla gasta 10 unidades de gasolina.
	-Aleatoriamente, aparece en otra posici�n del mapa, un bid�n de gasolina. Cada vez que el robot tome el bid�n, recarga a 100 su dep�sito de gasolina.
	-Se debe imprimir un mapa en caracteres ASCII indicando la posici�n del robot, as� como una interfaz rudimentaria que muestre la posici�n, la gasolina restante y las opciones de movimiento al usuario.
	*/
	
	int posi= 0, posj = 0;

	printf("Dime una posicion fila: ");
	scanf("%d", &posi);
	printf("Dime una posicion columna: ");
	scanf("%d", &posj);
	
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
		
			if(i == posi && j == posj){
				printf(" R");
			}else{
				printf(" -");
			}
		}
		printf("\n");
	}
	
	
	return 0;
}
