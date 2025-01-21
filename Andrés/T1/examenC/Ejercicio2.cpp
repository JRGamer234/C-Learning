#include <stdio.h>
#include <math.h>

void contarprimos(){
    int contador = 0;
    char primos[] = "1,2,5,7";
    char num[15];
    while (num[i] != '\0') {
        for (int j = 0; primos[j] != '\0'; j++) {
            if (num[i] == primos[j]) {
                contador++;
                break;
            }
        }
        i++;
    }
}

int main(){
    int num_primos = contarprimos(num);
    printf("Numero de primos: %d\n", num_primos);

}