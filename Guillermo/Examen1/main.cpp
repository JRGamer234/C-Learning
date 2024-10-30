#include <iostream>
#include <string.h>

int main(int argc, char** argv) {
	/*Ejercicio 1
		Poner un nombre y que salga asi:
		########
		#nombre#
		########
	*/
	char nombre[20];
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
    printf("\n");
    
    /*Ejercicio 2
    	Pedir 10 numeros al usuario y comprobar si los numeros son la secuencia 0-9 incluyendo si están desordenados.
    */
    int numero = 0;
    
    for( int i= 0; i < 10; i++){
    	printf("Introduce un numero: ");
    	scanf("%d", &numero);
	}
    
    
	
	return 0;
}
