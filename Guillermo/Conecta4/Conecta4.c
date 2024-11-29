#include <stdio.h>
#include <stdlib.h>

void tablero() {
    for(int i = 0; i < 6; i++) { //vertical
        for (int j = 0; j < 8; j++) { //horizontal
            printf("* ");
        }
        printf("\n");
    }
}

int main() {
    tablero();
    
    return 0;
}