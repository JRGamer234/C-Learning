#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdio.h>

// Tablero
const int FILAS = 10;
const int COLUMNAS = 10;

// Posición inicial *
int posX = 0;
int posY = 0;

// limpiar la pantalla
void limpiarPantalla() {
    system("cls");
}

// Dibujar el tablero
void dibujarTablero() {
    // Borde superior
    printf("  ");
    for(int i = 0; i < COLUMNAS + 2; i++) {
        printf("-");
    }
    printf("\n");

    // Todo lo demás
    for(int i = 0; i < FILAS; i++) {
        printf("| ");
        for(int j = 0; j < COLUMNAS; j++) {
            if(i == posY && j == posX) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf(" |\n");
    }

    // Borde inferior
    printf("  ");
    for(int i = 0; i < COLUMNAS + 2; i++) {
        printf("-");
    }
    printf("\n");
}

int main() {
    char tecla;
    bool jugando = true;

    while(jugando) {
        limpiarPantalla();
        dibujarTablero();
        
        // Pulsacion del user
        tecla = _getch();
        
        // Para las teclas de flechas
        if(tecla == -32) {
            tecla = _getch();
            
            // Actualiza la posición según pulsas la tecla
            switch(tecla) {
                case 72: // Arriba
                    if(posY > 0) posY--;
                    break;
                case 80: // Abajo
                    if(posY < FILAS - 1) posY++;
                    break;
                case 75: // Izquierda
                    if(posX > 0) posX--;
                    break;
                case 77: // Derecha
                    if(posX < COLUMNAS - 1) posX++;
                    break;
            }
        }
        if(tecla == 27){
            jugando = false;
        }
    }

    return 0;
}
