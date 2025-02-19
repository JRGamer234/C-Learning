#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ARBOL '#'
#define FUEGO 'X'
#define CENIZA '.'
#define FONDO '*'
#define MAX_DIM 20

void imprimirMapa(char mapa[][MAX_DIM], int x, int y) {
    system("cls");
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            printf("%c ", mapa[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void generarMapa(char mapa[][MAX_DIM], int x, int y) {
    srand(time(NULL));
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            mapa[i][j] = (rand() % 4 == 0) ? ARBOL : FONDO;
        }
    }
}


int main(){
    int x, y;
    char mapa[MAX_DIM][MAX_DIM];
    
    printf("Introduce el número de columnas (X): ");
    scanf("%d", &x);
    printf("Introduce el número de filas (Y): ");
    scanf("%d", &y);
    
    if (x > MAX_DIM || y > MAX_DIM) {
        printf("Error: dimensiones máximas %dx%d\n", MAX_DIM, MAX_DIM);
        return 1;
    }
    generarMapa(mapa, x, y);
    imprimirMapa(mapa, x, y);

}