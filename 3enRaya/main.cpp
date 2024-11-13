#include <stdio.h>

char tablero[3][3] = {{' ',' ',' '}, {' ',' ',' '}, {' ',' ',' '}};
char jugadorActual = 'X';

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

int main() {
    int fila, columna;
    bool juegoTerminado = false;

    printf("\n=== TRES EN RAYA ===\n");
    printf("Instrucciones:\n");
    printf("- Jugador 1 usa 'X'\n");
    printf("- Jugador 2 usa 'O'\n");
    printf("- Elige una posición indicando fila y columna\n");
    printf("=====================\n\n");

    while(!juegoTerminado) {
        dibujarTablero();
        printf("Es el turno del jugador %c\n", jugadorActual);
        
        do {
            printf("¿En qué fila quieres poner tu ficha? (1-3): ");
            scanf("%d", &fila);
            printf("¿En qué columna quieres poner tu ficha? (1-3): ");
            scanf("%d", &columna);
            fila--; columna--;

            if(fila < 0 || fila > 2 || columna < 0 || columna > 2) {
                printf("\n¡Error! Por favor, elige números entre 1 y 3.\n\n");
            }
            else if(tablero[fila][columna] != ' ') {
                printf("\n¡Esta casilla ya está ocupada! Elige otra.\n\n");
            }
        } while(fila < 0 || fila > 2 || columna < 0 || columna > 2 || tablero[fila][columna] != ' ');

        tablero[fila][columna] = jugadorActual;

        if(hayGanador()) {
            dibujarTablero();
            printf("\n¡FELICIDADES! ¡El jugador %c ha ganado la partida!\n\n", jugadorActual);
            juegoTerminado = true;
        }
        else if(tableroLleno()) {
            dibujarTablero();
            printf("\n¡EMPATE! La partida ha terminado sin ganador.\n\n");
            juegoTerminado = true;
        }
        else {
            jugadorActual = (jugadorActual == 'X') ? 'O' : 'X';
        }
    }

    printf("¿Quieres jugar otra partida? Ejecuta el programa de nuevo!\n");
    return 0;
}
