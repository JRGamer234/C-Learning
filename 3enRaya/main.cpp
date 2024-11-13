#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char tablero[3][3] = {{' ',' ',' '}, {' ',' ',' '}, {' ',' ',' '}};
char jugadorActual = 'X';
int partidasJugadas = 0;
int victoriasJugador = 0;
int victoriasCPU = 0;
int empates = 0;

void limpiarTablero() {
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            tablero[i][j] = ' ';
}

void dibujarTablero() {
    printf("\n    1   2   3\n");
    printf("  +---+---+---+\n");
    for(int i = 0; i < 3; i++) {
        printf("%d ", i + 1);
        for(int j = 0; j < 3; j++) {
            printf("| %c ", tablero[i][j]);
        }
        printf("|\n");
        printf("  +---+---+---+\n");
    }
    printf("\n");
}

bool hayGanador() {
    for(int i = 0; i < 3; i++) {
        if(tablero[i][0] == jugadorActual && tablero[i][1] == jugadorActual && tablero[i][2] == jugadorActual) return true;
        if(tablero[0][i] == jugadorActual && tablero[1][i] == jugadorActual && tablero[2][i] == jugadorActual) return true;
    }
    if(tablero[0][0] == jugadorActual && tablero[1][1] == jugadorActual && tablero[2][2] == jugadorActual) return true;
    if(tablero[0][2] == jugadorActual && tablero[1][1] == jugadorActual && tablero[2][0] == jugadorActual) return true;
    return false;
}

bool tableroLleno() {
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(tablero[i][j] == ' ') return false;
    return true;
}

void movimientoCPU() {
    // Primero intenta ganar si puede
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(tablero[i][j] == ' ') {
                tablero[i][j] = 'O';
                if(hayGanador()) return;
                tablero[i][j] = ' ';
            }
        }
    }

    // Si no puede ganar, busca un movimiento aleatorio válido
    int fila, columna;
    do {
        fila = rand() % 3;
        columna = rand() % 3;
    } while(tablero[fila][columna] != ' ');
    
    tablero[fila][columna] = 'O';
}

void mostrarEstadisticas() {
    printf("\n=== ESTADÍSTICAS ===\n");
    printf("Partidas jugadas: %d\n", partidasJugadas);
    printf("Victorias jugador: %d\n", victoriasJugador);
    printf("Victorias CPU: %d\n", victoriasCPU);
    printf("Empates: %d\n", empates);
    printf("==================\n\n");
}

void jugarContraCPU() {
    bool juegoTerminado = false;
    int fila, columna;

    while(!juegoTerminado) {
        dibujarTablero();
        
        if(jugadorActual == 'X') {
            printf("Tu turno (X)\n");
            do {
                printf("Fila (1-3): ");
                scanf("%d", &fila);
                printf("Columna (1-3): ");
                scanf("%d", &columna);
                fila--; columna--;
                
                if(fila < 0 || fila > 2 || columna < 0 || columna > 2 || tablero[fila][columna] != ' ') {
                    printf("ERROR.\n");
                }
            } while(fila < 0 || fila > 2 || columna < 0 || columna > 2 || tablero[fila][columna] != ' ');
            
            tablero[fila][columna] = 'X';
        } else {
            printf("Turno de la CPU (O)\n");
            movimientoCPU();
        }

        if(hayGanador()) {
            dibujarTablero();
            if(jugadorActual == 'X') {
                printf("¡Has ganado!\n");
                victoriasJugador++;
            } else {
                printf("¡La CPU ha ganado!\n");
                victoriasCPU++;
            }
            juegoTerminado = true;
        } else if(tableroLleno()) {
            dibujarTablero();
            printf("¡Empate!\n");
            empates++;
            juegoTerminado = true;
        }

        if (jugadorActual == 'X') {
    		jugadorActual = 'O';
		} else {
   	 		jugadorActual = 'X';
		}
    }
    partidasJugadas++;
}

void jugarContraJugador() {
    bool juegoTerminado = false;
    int fila, columna;

    while(!juegoTerminado) {
        dibujarTablero();
        printf("Turno del jugador %c\n", jugadorActual);
        
        do {
            printf("Fila (1-3): ");
            scanf("%d", &fila);
            printf("Columna (1-3): ");
            scanf("%d", &columna);
            fila--; columna--;
            
            if(fila < 0 || fila > 2 || columna < 0 || columna > 2 || tablero[fila][columna] != ' ') {
                printf("Movimiento inválido. Intenta de nuevo.\n");
            }
        } while(fila < 0 || fila > 2 || columna < 0 || columna > 2 || tablero[fila][columna] != ' ');

        tablero[fila][columna] = jugadorActual;

        if(hayGanador()) {
            dibujarTablero();
            printf("¡El jugador %c ha ganado! \n", jugadorActual);
            juegoTerminado = true;
        } else if(tableroLleno()) {
            dibujarTablero();
            printf("¡Empate!\n");
            empates++;
            juegoTerminado = true;
        }

        jugadorActual = (jugadorActual == 'X') ? 'O' : 'X';
    }
    partidasJugadas++;
}

int main() {
    srand(time(NULL));  // números aleatorios
    int opcion;
    
    do {
    	printf("\n======================\n");
        printf("\n==== TRES EN RAYA ====\n");
        printf("\n======================\n");
        printf("1. Jugar contra CPU\n");
        printf("2. Jugar contra jugador\n");
        printf("3. Ver estadísticas\n");
        printf("4. Salir\n");
        printf("Elige una opción: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                limpiarTablero();
                jugadorActual = 'X';
                printf("\nJugando contra CPU...\n");
                jugarContraCPU();
                break;
            case 2:
                limpiarTablero();
                jugadorActual = 'X';
                printf("\nJugando contra otro jugador...\n");
                jugarContraJugador();
                break;
            case 3:
                mostrarEstadisticas();
                break;
            case 4:
                printf("\n¡Gracias por jugar!\n");
                break;
            default:
                printf("\nERROR.\n");
        }
    } while(opcion != 4);

    return 0;
}
