#include <stdio.h>
#include <stdlib.h>

int obtenerLongitud(char palabra[]) {
    int longitud = 0;
    while(palabra[longitud] != '\0') {
        longitud++;
    }
    return longitud;
}

void invertida(char *palabra) {
    int longitud = obtenerLongitud(palabra);
    for(int i = 0; i < longitud/2; i++) {
        char temp = palabra[i];
        palabra[i] = palabra[longitud - 1 - i];
        palabra[longitud - 1 - i] = temp;
    }
}

void mayuscula(char *palabra) {
    int i = 0;
    while(palabra[i] != '\0') {
        if(palabra[i] >= 'a' && palabra[i] <= 'z') {
            palabra[i] = palabra[i] - 32;
        }
        i++;
    }
}

void vocales(char *palabra) {
    int i = 0;
    printf("Vocales encontradas: ");
    while(palabra[i] != '\0') {
        char c = palabra[i];
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
           c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            printf("%c ", c);
        }
        i++;
    }
    printf("\n");
}

int main() {
    char palabra[100];
    int opcion;
    
    printf("Ingrese una palabra: ");
    scanf("%s", palabra);
    
    printf("\nSeleccione una opcion:\n");
    printf("1. Invertir palabra\n");
    printf("2. Convertir a mayusculas\n");
    printf("3. Mostrar vocales\n");
    scanf("%d", &opcion);
    
    switch (opcion) {
    case 1:
        printf("Palabra original: %s\n", palabra);
        invertida(palabra);
        printf("Palabra invertida: %s\n", palabra);
        break;
    case 2:
        printf("Palabra original: %s\n", palabra);
        mayuscula(palabra);
        printf("Palabra en mayusculas: %s\n", palabra);
        break;
    case 3:
        vocales(palabra);
        break;
    default:
        printf("¡¡ERROR!!\n");
        break;
    }
    
    return 0;
}