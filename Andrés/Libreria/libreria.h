#include <stdio.h>

// strlen - Obtener la longitud de una cadena
int mi_strlen(char *palabra) {
    int i = 0;
    for (i = 0; palabra[i] != '\0'; i++);
    return i;
}

// strcpy - Copiar una cadena
void mi_strcpy(char *dest, char *src) {
    int i = 0;
    for (i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
}

// strcmp - Comparar dos cadenas (comprueba caracteres ASCII)
int mi_strcmp(char *str1, char *str2) {
    int i = 0;
    for (i = 0; str1[i] != '\0' && str1[i] == str2[i]; i++);
    return str1[i] - str2[i];
}

// Invertir palabra
void invertir_palabra(char *palabra, char *resultado) {
    int len = mi_strlen(palabra);
    int i = 0;
    for (i = 0; i < len; i++) {
        resultado[i] = palabra[len - i - 1];
    }
    resultado[len] = '\0';
}

// Mayúscula a minúscula (char)
char mayuscula_a_minuscula(char c) {
    if (c >= 'A' && c <= 'Z') {
        c += 32;
    }
    return c;
}

// Minúscula a mayúscula (char)
char minuscula_a_mayuscula(char c) {
    if (c >= 'a' && c <= 'z') {
        c -= 32;
    }
    return c;
}

// Obtener vocales de una cadena
void obtener_vocales(char *cadena, char *vocales) {
    int i = 0, j = 0;
    for (i = 0; cadena[i] != '\0'; i++) {
        if (cadena[i] == 'a' || cadena[i] == 'e' || cadena[i] == 'i' || cadena[i] == 'o' || cadena[i] == 'u' ||
            cadena[i] == 'A' || cadena[i] == 'E' || cadena[i] == 'I' || cadena[i] == 'O' || cadena[i] == 'U') {
            vocales[j] = cadena[i];
            j++;
        }
    }
    vocales[j] = '\0';
}

// Obtener consonantes de una cadena
void obtener_consonantes(char *cadena, char *consonantes) {
    int i = 0, j = 0;
    for (i = 0; cadena[i] != '\0'; i++) {
        if ((cadena[i] >= 'a' && cadena[i] <= 'z') || (cadena[i] >= 'A' && cadena[i] <= 'Z')) {
            if (!(cadena[i] == 'a' || cadena[i] == 'e' || cadena[i] == 'i' || cadena[i] == 'o' || cadena[i] == 'u' ||
                  cadena[i] == 'A' || cadena[i] == 'E' || cadena[i] == 'I' || cadena[i] == 'O' || cadena[i] == 'U')) {
                consonantes[j] = cadena[i];
                j++;
            }
        }
    }
    consonantes[j] = '\0';
}

// Convertir de int a char
char int_a_char(int num) {
    return num + '0';
}

// Convertir de char a int
int char_a_int(char c) {
    return c - '0';
}

// Contar palabras
int contar_palabras(char *cadena) {
    int palabras = 0, en_palabra = 0, i = 0;
    for (i = 0; cadena[i] != '\0'; i++) {
        if (cadena[i] != ' ' && en_palabra == 0) {
            en_palabra = 1;
            palabras++;
        } else if (cadena[i] == ' ') {
            en_palabra = 0;
        }
    }
    return palabras;
}

// Cifrado César
void cifrado_cesar(char *texto, int clave, char *resultado) {
    int i = 0;
    for (i = 0; texto[i] != '\0'; i++) {
        if ((texto[i] >= 'a' && texto[i] <= 'z') || (texto[i] >= 'A' && texto[i] <= 'Z')) {
            char base = (texto[i] >= 'a') ? 'a' : 'A';
            resultado[i] = ((texto[i] - base + clave) % 26) + base;
        } else {
            resultado[i] = texto[i];
        }
    }
    resultado[i] = '\0';
}

// Descifrado César
void descifrado_cesar(char *texto, int clave, char *resultado) {
    cifrado_cesar(texto, -clave, resultado);
}

// Alternar letras entre mayúsculas y minúsculas
void alternar_mayus_minus(char *cadena, char *resultado) {
    int i = 0;
    for (i = 0; cadena[i] != '\0'; i++) {
        if (cadena[i] >= 'a' && cadena[i] <= 'z') {
            resultado[i] = cadena[i] - 32; // Convertir a mayúscula
        } else if (cadena[i] >= 'A' && cadena[i] <= 'Z') {
            resultado[i] = cadena[i] + 32; // Convertir a minúscula
        } else {
            resultado[i] = cadena[i];
        }
    }
    resultado[i] = '\0';
}

// Buscar si una subcadena pertenece a una palabra más larga
int contiene_subcadena(char *palabra, char *subcadena) {
    int i = 0, j = 0;
    for (i = 0; palabra[i] != '\0'; i++) {
        // Comprobar si la subcadena coincide a partir de la posición actual
        for (j = 0; subcadena[j] != '\0' && palabra[i + j] == subcadena[j]; j++);
        // Si se recorrió toda la subcadena, significa que se encontró
        if (subcadena[j] == '\0') {
            return 1; // Subcadena encontrada
        }
    }
    return 0; // Subcadena no encontrada
}