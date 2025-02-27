#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h> // Para usar Sleep()

#define ARBOL '#'
#define FUEGO 'X'
#define CENIZA '.'
#define FONDO '*'
#define MAX_DIM 20

void imprimirBosque(char bosque[][MAX_DIM], int x, int y) {
    system("cls");
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            printf("%c ", bosque[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void generarBosque(char bosque[][MAX_DIM], int x, int y) {
    srand(time(NULL));
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            bosque[i][j] = (rand() % 4 == 0) ? ARBOL : FONDO;
        }
    }
}

int hayArbolesAdyacentes(char bosque[][MAX_DIM], int x, int y, int i, int j) {
    for (int di = -1; di <= 1; di++) {
        for (int dj = -1; dj <= 1; dj++) {
            if (di == 0 && dj == 0) continue;
            
            int ni = i + di;
            int nj = j + dj;
            
            if (ni >= 0 && ni < y && nj >= 0 && nj < x) {
                if (bosque[ni][nj] == ARBOL) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

void propagarFuego(char bosque[][MAX_DIM], int x, int y) {
    char nuevoBosque[MAX_DIM][MAX_DIM];
    memcpy(nuevoBosque, bosque, sizeof(nuevoBosque));
    
    // Propagar el fuego
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            if (bosque[i][j] == FUEGO) {
                nuevoBosque[i][j] = CENIZA;
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        int ni = i + di;
                        int nj = j + dj;
                        
                        if (ni >= 0 && ni < y && nj >= 0 && nj < x) {
                            if (bosque[ni][nj] == ARBOL) {
                                nuevoBosque[ni][nj] = FUEGO;
                            }
                        }
                    }
                }
            }
        }
    }
    // Actualizar el bosque
    memcpy(bosque, nuevoBosque, sizeof(nuevoBosque));
}

int hayFuego(char bosque[][MAX_DIM], int x, int y) {
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            if (bosque[i][j] == FUEGO) {
                return 1;
            }
        }
    }
    return 0;
}

void iniciarIncendio(char bosque[][MAX_DIM], int x, int y) {
    // Iniciar el fuego
    while (1) {
        int i = rand() % y;
        int j = rand() % x;
        if (bosque[i][j] == ARBOL) {
            bosque[i][j] = FUEGO;
            break;
        }
    }
}

int main() {
    int x, y, velocidad;
    char bosque[MAX_DIM][MAX_DIM];
    
    printf("Introduce el número de columnas (X): \n");
    scanf("%d", &x);
    printf("Introduce el número de filas (Y): \n");
    scanf("%d", &y);
    printf("Velocidad de propagación del fuego: \n
        1) Rápida\n
        2) Media\n
        3) Lenta\n");
    scanf("%d", &velocidad);
    
    if (x > MAX_DIM || y > MAX_DIM) {
        printf("Error: dimensiones máximas %dx%d\n", MAX_DIM, MAX_DIM);
        return 1;
    }
    
    generarBosque(bosque, x, y);
    imprimirBosque(bosque, x, y);
    
    printf("Presiona Enter para iniciar el fuego...");
    getchar(); // Limpiar el buffer
    getchar(); // Esperar Enter
    iniciarIncendio(bosque, x, y);
    // propagación del fuego
    while (hayFuego(bosque, x, y)) {
        imprimirBosque(bosque, x, y);
        propagarFuego(bosque, x, y);
        Sleep(500); //esperar medio segundito
    }
    imprimirBosque(bosque, x, y);
    printf("La simulación ha terminado.\n");
    
    return 0;
}