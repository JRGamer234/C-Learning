#include <iostream>
#include <stdio.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	/* H o l a \0*/
	char palabra[5] = "Hola";
	char letra = 'c';
	int i = 0;
	
	printf("%s", palabra);
	scanf("%s", &palabra);
	
	printf("\n");
	
	while(palabra[i] != '\0'){
		printf("%c", palabra[i]);
		i++;
	}
	
	printf("\n");
	
	for(i = 0; i < strlen(palabra); i++){
		printf("%c", palabra[i]);
	}
	
	
	/*programa que pida una palabra por teclado y convierta cada letra de mayuscula a minuscula o minuscula a mayuscula (letra por letra)

	ejemplo:

	hoLA

	HOLA
	*/

	/*Programa que pida una palabra por teclado y te diga cuantas vocales tiene la palabra en total*/

	/*Programa que pida una palabra por teclado y te diga cuantas veces aparece CADA vocal*/

	/*Programa que pida 2 palabras por teclado y solo muestre las letras que aparecen en las 2 palabras*/
	
	
	
	return 0;
}
