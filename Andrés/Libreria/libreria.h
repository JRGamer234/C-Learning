#include <stdio.h>

// strlen - Obtener la longitud de una cadena
int strlen(char *palabra) {
    int i = 0;
    for (i = 0; palabra[i] != '\0'; i++);
    return i;
}

// strcpy - Copiar una cadena
void strcpy(char *dest, char *src) {
    int i = 0;
    for (i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
}

// strcmp - Comparar dos cadenas
int strcmp(char *str1, char *str2) {
    int i = 0;
    for (i = 0; str1[i] != '\0' && str1[i] == str2[i]; i++);
    return str1[i] - str2[i];
}

// Invertir palabra
void invertir_palabra(char *palabra, char *resultado) {
    int len = strlen(palabra);
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
