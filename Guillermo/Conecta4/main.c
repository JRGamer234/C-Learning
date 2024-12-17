#include <stdio.h>

#define ROWS 6
#define COLUMNS 7

void initializeBoard(char board[ROWS][COLUMNS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            board[i][j] = '.';
        }
    }
}

void displayBoard(char board[ROWS][COLUMNS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    for (j = 0; j < COLUMNS; j++) {
        printf("%d ", j);
    }
    printf("\n");
}

int dropDisc(char board[ROWS][COLUMNS], int column, char disc) {
    int i;
    for (i = ROWS - 1; i >= 0; i--) {
        if (board[i][column] == '.') {
            board[i][column] = disc;
            return 1;
        }
    }
    return 0;
}

int checkWin(char board[ROWS][COLUMNS], char disc) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            if (board[i][j] == disc) {
                if ((i + 3 < ROWS && board[i + 1][j] == disc && board[i + 2][j] == disc && board[i + 3][j] == disc) ||
                    (j + 3 < COLUMNS && board[i][j + 1] == disc && board[i][j + 2] == disc && board[i][j + 3] == disc) ||
                    (i + 3 < ROWS && j + 3 < COLUMNS && board[i + 1][j + 1] == disc && board[i + 2][j + 2] == disc && board[i + 3][j + 3] == disc) ||
                    (i + 3 < ROWS && j - 3 >= 0 && board[i + 1][j - 1] == disc && board[i + 2][j - 2] == disc && board[i + 3][j - 3] == disc)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int isBoardFull(char board[ROWS][COLUMNS]) {
    int j;
    for (j = 0; j < COLUMNS; j++) {
        if (board[0][j] == '.') {
            return 0;
        }
    }
    return 1;
}

int main() {
    char board[ROWS][COLUMNS];
    char currentPlayer;
    int gameWon;
    int column;

    initializeBoard(board);

    currentPlayer = 'X';
    gameWon = 0;

    printf("Bienvenido a Conecta 4!\n\n");

    while (1) {
        displayBoard(board);
        printf("Turno del jugador %c. Elige una columna (0-%d): ", currentPlayer, COLUMNS - 1);

        if (scanf("%d", &column) != 1) {
            printf("Entrada no válida. Por favor, introduce un número.\n");
            while (getchar() != '\n'); // Limpiar el buffer de entrada
            continue;
        }

        if (column < 0 || column >= COLUMNS) {
            printf("Columna fuera de rango. Por favor, elige una columna entre 0 y %d.\n", COLUMNS - 1);
            continue;
        }

        if (!dropDisc(board, column, currentPlayer)) {
            printf("Columna llena. Intenta con otra.\n");
            continue;
        }

        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            printf("\n¡Jugador %c gana!\n", currentPlayer);
            gameWon = 1;
            break;
        }

        if (isBoardFull(board)) {
            displayBoard(board);
            printf("\nEl juego termina en empate.\n");
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    if (!gameWon) {
        printf("Gracias por jugar.\n");
    }

    return 0;
}
