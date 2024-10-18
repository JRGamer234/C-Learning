
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int print_map(int robot_i, int robot_j, int gas_i, int gas_j, int map_size);
int move_robot(char direction, int *robot_i, int *robot_j, int *gasoline, int map_size, int gas_cost);

int main() {
    int robot_i, robot_j;
    int gas_i, gas_j;
    int gasoline;

    const int map_size = 10;
    const int max_gas = 100;
    const int gas_cost = 10;

    printf("Dime una posicion fila (0-%d): ", map_size - 1);
    scanf("%d", &robot_i);
    printf("Dime una posicion columna (0-%d): ", map_size - 1);
    scanf("%d", &robot_j);

    gasoline = max_gas;
    
	gas_i = rand() % map_size;
    gas_j = rand() % map_size;
    
	while (gas_i == robot_i && gas_j == robot_j) {
        gas_i = rand() % map_size;
        gas_j = rand() % map_size;
    }

    while (gasoline > 0) {
        if (print_map(robot_i, robot_j, gas_i, gas_j, map_size) != 0) {
            printf("Error al imprimir el mapa.\n");
            return 1;
        }
        
        printf("Posicion actual: (%d, %d)\n", robot_i, robot_j);
        printf("Gasolina restante: %d\n", gasoline);
        printf("Moverse (n= norte, s= sur, e= este, o= oeste, q= salir): ");
        char move;
        scanf(" %c", &move);

        if (move == 'q') {
            printf("Saliendo del juego.\n");
            break;
        }

        if (move_robot(move, &robot_i, &robot_j, &gasoline, map_size, gas_cost) != 0) {
            printf("Movimiento no valido.\n");
            continue;
        }

        if (robot_i == gas_i && robot_j == gas_j) {
            printf("¡Has encontrado un bidón de gasolina! Gasolina recargada a %d.\n", max_gas);
            gasoline = max_gas;
            
			gas_i = rand() % map_size;
            gas_j = rand() % map_size;
            while (gas_i == robot_i && gas_j == robot_j) {
                gas_i = rand() % map_size;
                gas_j = rand() % map_size;
            }
        }
        if (gasoline <= 0) {
            printf("¡Te has quedado sin gasolina! Fin del juego.\n");
            break;
        }
    }

    return 0;
}

int print_map(int robot_i, int robot_j, int gas_i, int gas_j, int map_size) {
    for (int i = 0; i < map_size; i++) {
        for (int j = 0; j < map_size; j++) {
            if (i == robot_i && j == robot_j) {
                printf(" R"); 
            } else if (i == gas_i && j == gas_j) {
                printf(" G"); 
            } else {
                printf(" -"); 
            }
        }
        printf("\n");
    }
    return 0;
}

int move_robot(char direction, int *robot_i, int *robot_j, int *gasoline, int map_size, int gas_cost) {
    switch (direction) {
        case 'n':
            *robot_i = (*robot_i - 1 + map_size) % map_size;
            break;
        case 's':
            *robot_i = (*robot_i + 1) % map_size;
            break;
        case 'e':
            *robot_j = (*robot_j + 1) % map_size;
            break;
        case 'o':
            *robot_j = (*robot_j - 1 + map_size) % map_size;
            break;
        default:
            return 1;
    }
    *gasoline -= gas_cost;
    return 0;
}
