#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	/*
	En un mundo circular y bidimensional de 10 x 10, un robot comienza en una posición dada por el usuario.
	-El robot, puede moverse en las direcciones: norte, sur, este y oeste.
	-El robot comienza con 100 unidades de gasolina.
	-Cada vez que se mueve una casilla gasta 10 unidades de gasolina.
	-Aleatoriamente, aparece en otra posición del mapa, un bidón de gasolina. Cada vez que el robot tome el bidón, recarga a 100 su depósito de gasolina.
	-Se debe imprimir un mapa en caracteres ASCII indicando la posición del robot, así como una interfaz rudimentaria que muestre la posición, la gasolina restante y las opciones de movimiento al usuario.
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
