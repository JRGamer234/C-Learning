#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	bool mazo[52]; //0..12 Picas
				   //13..25 Corazones
				   //26..38 Diamantes
				   //39..51 Treboles

	int cartasJ1[15]; //Valores: 1=AS .... 11 = J  12 = Q  13 = k
	int cartasJ2[15];	  
	int max_cartasCPU[]
	 
	// Inicializar el mazo (Todo dentro)
	
	for (int i = 0; i < 52; i++){
		mazo[i] = false;
	}
	
	for(int i = 0; i<52; i++){
		cartasJ1[i] = 0;
		cartasJ2[i] = 0;
	}
	
	printf("Bienvenido al BlackJack\n");
	
	// La cpu saca dos cartas
	
	do{
	carta = aleatorio(0,51);
	}while(mazo[carta]);
	mazo[carta] = true;
	cartasCPU[0] = carta % 13;
	max_cartasCPU++;

	printf("Cartas CPU: ");
	for(int i = 0; i < max_cartasCPU; i++){
		printf("%d", cartasJ1[i]);
	}
	
	do{
	carta = aleatorio(0,51);
	}while(mazo[carta]);
	mazo[carta] = true;
	cartasCPU[1] = carta % 13;
	max_cartasCPU++;

	printf("Cartas Jugador: ");
	for(int i = 0; i < max_cartasCPU; i++){
		printf("%d", cartasJ1[i]);
	}
	
	
	
	return 0;
}
