#include <stdio.h>
#include <libreria.h>

int main() {
    // Prueba de strlen
    char palabra1[] = "Jorge";
    printf("Longitud de '%s': %d\n", palabra1, mi_strlen(palabra1));

    // Prueba de strcpy
    char origen[] = "Piloto";
    char destino[50];
    mi_strcpy(destino, origen);
    printf("Copia de cadena: %s\n", destino);

    // Prueba de strcmp
    char str1[] = "Hola";
    char str2[] = "Holaaa";
    printf("Comparación de cadenas: %d\n", mi_strcmp(str1, str2));

    // Prueba de invertir_palabra
    char palabra2[] = "Mundo";
    char invertida[50];
    invertir_palabra(palabra2, invertida);
    printf("Palabra invertida: %s\n", invertida);

    // Prueba de mayuscula_a_minuscula
    char letra1 = 'Y';
    printf("Mayúscula '%c' a minúscula: '%c'\n", letra1, mayuscula_a_minuscula(letra1));

    // Prueba de minuscula_a_mayuscula
    char letra2 = 'z';
    printf("Minúscula '%c' a mayúscula: '%c'\n", letra2, minuscula_a_mayuscula(letra2));

    // Prueba de obtener_vocales
    char frase[] = "Jorge es un piloto";
    char vocales[50];
    obtener_vocales(frase, vocales);
    printf("Vocales en '%s': %s\n", frase, vocales);

    // Prueba de obtener_consonantes
    char consonantes[50];
    obtener_consonantes(frase, consonantes);
    printf("Consonantes en '%s': %s\n", frase, consonantes);

    // Prueba de int_a_char
    int numero = 5;
    printf("Número %d como carácter: '%c'\n", numero, int_a_char(numero));

    // Prueba de char_a_int
    char caracter = '5';
    printf("Carácter '%c' como número: %d\n", caracter, char_a_int(caracter));

    // Prueba de contar_palabras
    char frase2[] = "Hola mundo soy un programador";
    printf("Número de palabras en '%s': %d\n", frase2, contar_palabras(frase2));

    // Prueba de cifrado_cesar
    char texto[] = "PaquitoElChocolatero";
    char texto_cifrado[50];
    cifrado_cesar(texto, 3, texto_cifrado);
    printf("Texto cifrado: %s\n", texto_cifrado);

    // Prueba de descifrado_cesar
    char texto_descifrado[50];
    descifrado_cesar(texto_cifrado, 3, texto_descifrado);
    printf("Texto descifrado: %s\n", texto_descifrado);

    // Prueba de alternar_mayus_minus
    char cadena[] = "Me llamo Jorge";
    char resultado[50];
    alternar_mayus_minus(cadena, resultado);
    printf("Alternar mayúsculas y minúsculas: %s\n", resultado);

    // Prueba de contiene_subcadena
    char palabra[] = "Programador";
    char subcadena[] = "grama";

    if (contiene_subcadena(palabra, subcadena)) {
        printf("La subcadena '%s' está contenida en la palabra '%s'.\n", subcadena, palabra);
    } else {
        printf("La subcadena '%s' no está contenida en la palabra '%s'.\n", subcadena, palabra);
    }
    return 0;
}
