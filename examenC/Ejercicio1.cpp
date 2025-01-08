#include <stdio.h>

int contarVocales(char* palabra) {
    // Contador para identificar las vocales
    char vocalesa[] = "aA";
    char vocalese[] = "eE";
    char vocalesi[] = "iI";
    char vocaleso[] = "oO";
    char vocalesu[] = "uU";
    int contadora = 0;
    int contadore = 0;
    int contadori = 0;
    int contadoro = 0;
    int contadoru = 0;
    int i = 0;

    while (palabra[i] != '\0') {
        for (int j = 0; vocalesa[j] != '\0'; j++) {
            if (palabra[i] == vocalesa[j]) {
                contadora++;
                break;
            }
        }
        i++;
    }
    while (palabra[i] != '\0') {
        for (int j = 0; vocalese[j] != '\0'; j++) {
            if (palabra[i] == vocalese[j]) {
                contadore++;
                break;
            }
        }
        i++;
    }
    while (palabra[i] != '\0') {
        for (int j = 0; vocalesi[j] != '\0'; j++) {
            if (palabra[i] == vocalesi[j]) {
                contadori++;
                break;
            }
        }
        i++;
    }
    while (palabra[i] != '\0') {
        for (int j = 0; vocaleso[j] != '\0'; j++) {
            if (palabra[i] == vocaleso[j]) {
                contadoro++;
                break;
            }
        }
        i++;
    }
     while (palabra[i] != '\0') {
        for (int j = 0; vocalesu[j] != '\0'; j++) {
            if (palabra[i] == vocalesu[j]) {
                contadoru++;
                break;
            }
        }
        i++;
    }

    return contadora, contadore, contadori, contadoro, contadoru;
}

int main(){
    char palabra[100];

    printf("Ingrese una palabra: ");
    scanf("%s", &palabra);

    int num_vocalesa = contarVocales(vocalesa);
    int num_vocalese = contarVocales(vocalese);
    int num_vocalesi = contarVocales(vocalesi);
    int num_vocaleso = contarVocales(vocaleso);
    int num_vocalesu = contarVocales(vocalesu);
    printf("Numero de vocales: %d\n", num_vocalesa);
    printf("Numero de vocales: %d\n", num_vocalese);
    printf("Numero de vocales: %d\n", num_vocalesi);
    printf("Numero de vocales: %d\n", num_vocaleso);
    printf("Numero de vocales: %d\n", num_vocalesu);

}