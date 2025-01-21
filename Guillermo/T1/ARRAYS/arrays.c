#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Función para imprimir números desde N hasta 1000
void imprimirHastaMil(int n) {
    printf("\nNúmeros desde %d hasta 1000:\n", n);
    for(int i = n; i <= 1000; i++) {
        printf("%d ", i);
    }
    printf("\n");
}

// Función para imprimir divisores
void imprimirDivisores(int n) {
    printf("\nDivisores de %d:\n", n);
    for(int i = 1; i <= n; i++) {
        if(n % i == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

// Función para calcular longitud de cadena
int longitudCadena(char *str) {
    int count = 0;
    while(str[count] != '\0') {
        count++;
    }
    return count;
}

// Función para verificar si son bifrontes
bool sonBifrontes(char *c1, char *c2) {
    int len1 = longitudCadena(c1);
    int len2 = longitudCadena(c2);
    
    if(len1 != len2) return false;
    
    for(int i = 0; i < len1; i++) {
        if(tolower(c1[i]) != tolower(c2[len1-1-i])) {
            return false;
        }
    }
    return true;
}

// Función para contar vocales
void contarVocales(char *str) {
    int a = 0, e = 0, i = 0, o = 0, u = 0;
    
    for(int j = 0; str[j] != '\0'; j++) {
        char c = tolower(str[j]);
        switch(c) {
            case 'a': a++; break;
            case 'e': e++; break;
            case 'i': i++; break;
            case 'o': o++; break;
            case 'u': u++; break;
        }
    }
    
    printf("\nFrecuencia de vocales:\n");
    printf("a: %d\ne: %d\ni: %d\no: %d\nu: %d\n", a, e, i, o, u);
}

// Función para contar consonantes
void contarConsonantes(char *str) {
    int freq[26] = {0};
    
    printf("\nFrecuencia de consonantes:\n");
    for(int i = 0; str[i] != '\0'; i++) {
        if(isalpha(str[i])) {
            char c = tolower(str[i]);
            if(c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u') {
                freq[c - 'a']++;
            }
        }
    }
    
    for(int i = 0; i < 26; i++) {
        char c = 'a' + i;
        if(c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' && freq[i] > 0) {
            printf("%c: %d\n", c, freq[i]);
        }
    }
}

// Función para verificar si es pangrama
bool esPangrama(char *str) {
    bool letras[26] = {false};
    
    for(int i = 0; str[i] != '\0'; i++) {
        if(isalpha(str[i])) {
            letras[tolower(str[i]) - 'a'] = true;
        }
    }
    
    for(int i = 0; i < 26; i++) {
        if(!letras[i]) return false;
    }
    return true;
}

// Función para verificar si es pangrama perfecto
bool esPangramaPerfecto(char *str) {
    int letras[26] = {0};
    
    for(int i = 0; str[i] != '\0'; i++) {
        if(isalpha(str[i])) {
            letras[tolower(str[i]) - 'a']++;
            if(letras[tolower(str[i]) - 'a'] > 1) return false;
        }
    }
    
    for(int i = 0; i < 26; i++) {
        if(letras[i] != 1) return false;
    }
    return true;
}

// Función para cifrado César
void cifradoCesar(char *str, int n) {
    printf("\nCadena cifrada (desplazamiento %d):\n", n);
    for(int i = 0; str[i] != '\0'; i++) {
        if(isalpha(str[i])) {
            char base = isupper(str[i]) ? 'A' : 'a';
            printf("%c", (str[i] - base + n) % 26 + base);
        } else {
            printf("%c", str[i]);
        }
    }
    printf("\n");
}

int main() {
    int n;
    char str1[100], str2[100];
    
    // Test para números hasta 1000
    printf("Ingrese un número N para imprimir hasta 1000: ");
    scanf("%d", &n);
    imprimirHastaMil(n);
    
    // Test para divisores
    printf("\nIngrese un número para encontrar sus divisores: ");
    scanf("%d", &n);
    imprimirDivisores(n);
    
    // Limpiar el buffer
    getchar();
    
    // Test para longitud de cadena
    printf("\nIngrese una cadena para calcular su longitud: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0;
    printf("Longitud: %d\n", longitudCadena(str1));
    
    // Test para bifrontes
    printf("\nIngrese la primera cadena para verificar si son bifrontes: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0;
    
    printf("Ingrese la segunda cadena: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = 0;
    
    printf("¿Son bifrontes? %s\n", sonBifrontes(str1, str2) ? "Sí" : "No");
    
    // Test para contar vocales y consonantes
    printf("\nIngrese una cadena para contar vocales y consonantes: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0;
    
    contarVocales(str1);
    contarConsonantes(str1);
    
    // Test para pangrama
    printf("\nIngrese una cadena para verificar si es pangrama: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0;
    
    printf("¿Es pangrama? %s\n", esPangrama(str1) ? "Sí" : "No");
    printf("¿Es pangrama perfecto? %s\n", esPangramaPerfecto(str1) ? "Sí" : "No");
    
    // Test para cifrado César
    printf("\nIngrese una cadena para cifrar: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0;
    
    printf("Ingrese el desplazamiento: ");
    scanf("%d", &n);
    
    cifradoCesar(str1, n);
    
    return 0;
}