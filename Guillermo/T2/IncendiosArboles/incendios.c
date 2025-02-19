#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> // Para usar sleep()

#define ARBOL '#'
#define FUEGO 'X'
#define CENIZA '.'
#define FONDO '*'

void imprimirBosque(char bosque[][20], int x, int y) {
    system("cls");
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            printf("%c ", bosque[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void generarBosque(char bosque[][20], int x, int y) {
    srand(time(NULL));
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            bosque[i][j] = (rand() % 4 == 0) ? ARBOL : FONDO;
        }
    }
}
int hayArbolesAdyacentes(char bosque[][20], int x, int y, int i, int j) {
    for (int d i = -1; di <= 1; di++) {
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

void propagarFuego(char bosque[][20], int x, int y) {
    char nuevoBosque[20][20];
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            nuevoBosque[i][j] = bosque[i][j];
        }
    }
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
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            bosque[i][j] = nuevoBosque[i][j];
        }
    }
}

int hayFuego(char bosque[][20], int x, int y) {
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            if (bosque[i][j] == FUEGO) {
                return 1;
            }
        }
    }
    return 0;
}

void iniciarIncendio(char bosque[][20], int x, int y) {
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
    int x, y;
    char bosque[20][20];
    
    printf("Introduce el número de columnas (X): ");
    scanf("%d", &x);
    printf("Introduce el número de filas (Y): ");
    scanf("%d", &y);
    
    if (x > 20 || y > 20) {
        printf("Error: dimensiones máximas 20x20\n");
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
        usleep(500000); //esperar medio segundito
    }
    imprimirBosque(bosque, x, y);
    printf("La simulación ha terminado.\n");
    
    return 0;
}