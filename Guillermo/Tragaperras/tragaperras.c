#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*
    Programar una sencilla tragaperras que comience con un saldo de 100€.
        - Al pedirle tirada que saque 3 caracteres aleatorios.
        - Si esos caracteres son iguales, bonificar con 5€.
        - Cada tirada debe restar 2€ antes del calculo de las casillas.
        - Caracteres posibles: ('P')latano, ('C')iruela, ('L')imon y '7'.
        - Si el jugador decide salir (Cash Out) imprimir el dinero de saldo restante.
*/
void tragaperras(int *dinero){
    srand(time(NULL));
    char ale[]={'P','L','C','7'};
    int numcar = sizeof(ale) / sizeof(ale[0]);
    char c1, c2, c3;
    
    // Verificar si aún hay dinero para jugar
    if (*dinero < 2) {
        printf("No tienes suficiente dinero para jugar.\n");
        return;
    }

    // Restar 2€
    *dinero -= 2;

    c1 = ale[rand() % numcar];
    c2 = ale[rand() % numcar];
    c3 = ale[rand() % numcar];
    
    printf("=====================================\n");
    printf("|         MÁQUINA TRAGAPERRAS       |\n");
    printf("=====================================\n");
    printf("|   ___________   ___________   ___________   |\n");
    printf("|  |           | |           | |           |  |\n");
    printf("|  |     %c     | |    %c      | |    %c      |  |\n", c1, c2, c3);
    printf("|  |___________| |___________| |___________|  |\n");
    printf("=====================================\n");

    // Comprobar si ha ganado
    if (c1 == c2 && c2 == c3) {
        printf("¡PREMIO! Has ganado 10 euros\n");
        *dinero += 5;
    } else {
        printf("Lo siento, no has ganado esta vez.\n");
    }

    printf("Saldo actual: %d euros\n", *dinero);
}
int main(){
    int opcion, dinero = 100;
    
    printf("Bienvenido a la Máquina Tragaperras!\n");
    
    do {
        printf("Quieres jugar? (-2 euros)\n");
        printf("1) Si\n2) No\n");
        printf("Saldo actual: %d euros\n", dinero);
        scanf("%d", &opcion);

        if (opcion == 1) {
            tragaperras(&dinero);
        }

        // No hay dinero
        if (dinero < 2) {
            printf("No tienes suficiente dinero para seguir jugando.\n");
            break;
        }

    } while (opcion == 1);

    printf("Gracias por jugar. Saldo final: %d euros\n", dinero);
    return 0;
}