#include <stdio.h>

/*
Crea un programa en C que implemente una codificación basada en invertir las palabras de una frase. El programa debe:

Definir una variable palabra[50] =
"Hola mundo desde C";
Dividir la frase en palabras (considera los espacios como separadores).Invertir cada palabra individualmente.Mostrar la frase codificada con las palabras invertidas, pero en el mismo orden.

    palabra[50]: "Hola mundo desde C"
    Salida: "aloH odnum edsed C"
    Usa funciones para modularizar el código:
    Una función para invertir una palabra.
    Una función para dividir la frase en palabras y procesarlas.
*/
int main() {
    char palabra[50] = "Hola me llamo Jorge";
    
    // Manual string length calculation
    int length = 0;
    while (palabra[length] != '\0') {
        length++;
    }
    
    char reversed[50];
    
    // Reverse the string
    for (int i = 0; i < length; i++) {
        reversed[i] = palabra[length - 1 - i];
    }
    reversed[length] = '\0';
    
    // Print with the specific output format
    printf("%s", reversed);
    
    return 0;
}

