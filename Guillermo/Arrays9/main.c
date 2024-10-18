#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	/*
	-Pide un número N y pinta los números desde N hasta 1000
	-Dado un número N por teclado imprimir todos los divisores que tiene. Por ejemplo, si N=12, debe imprimir 1,2,3,4,6 y 12
	
	*/
	int n = 0,aux;
	printf("Dime un numero: ");
	scanf("%d", &n);
	
    aux =n;
	while(aux <= 1000){
		printf("%d \n", aux);
		aux++;
	}
	printf("Los divisores de %d son: ", n);
	for(int i = 1; i <= n; i++) {
        if(n % i == 0) {
            printf("%d ", i);
        }
    }
    /*
	-Dada una cadena imprimir su longitud sin usar la función LONGITUD.
	-Dadas dos cadenas C y D indicar si son bifrontes (Por ejemplo, C=amor y D=roma son bifrontes)
	*/
	
	char palabra[100];
    int cuantas = 0;

    printf("\nDame una cadena: ");
    scanf("%s", palabra);  
    while (palabra[cuantas] != '\0') {
        cuantas++;
    }

    printf("\nLa cadena tiene %d caracteres.\n", cuantas);

	/*
	-Dada una cadena mostrar cuántas veces aparece en ella cada vocal
	-Dada una cadena mostrar cuántas veces aparece en ella cada consonante
	-Dada una cadena determinar si es un PANGRAMA (usa todas las vocales y consonantes aunque haya repeticiones)
	-Dada una cadena determinar si es un PANGRAMA  PERFECTO (usa todas las vocales y consonantes SIN repeticiones)
	-Dada una cadena C y un número N mostrar la cadena resultante de aplicar a C una codificación basada en cifrado César dedesplazamiento N
	*/
	
	
	return 0;
}
