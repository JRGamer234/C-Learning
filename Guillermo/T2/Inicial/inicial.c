#include <stdio.h>
#include <string.h>

// Función que devuelve la inicial de un nombre.
char obtenerInicial(char nombre[]) {
    return nombre[0];
}

// Función que modifica el nombre para que contenga solo la inicial.
void inicialConReferencia(char nombre[]) {
    nombre[1] = '\0'; // Termina el string después del primer carácter.
}

int main() {
    char nombre[50]; // Arreglo para almacenar el nombre.
    char letra_inicial; // Variable para almacenar la inicial.

    // Asignar un nombre al arreglo.
    strcpy(nombre, "Jorge");

    // Obtener y mostrar la inicial con la función obtenerInicial().
    letra_inicial = obtenerInicial(nombre);
    printf("La inicial es %c\n", letra_inicial);

    // Modificar el nombre para que contenga solo la inicial.
    inicialConReferencia(nombre);
    printf("El nombre ahora es: %s\n", nombre);

    return 0;
}
