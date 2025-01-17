#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nombre[30];
    int vida;
} Dinosaurio;

void morder(Dinosaurio *victima) {
    (*victima).vida -= 10;
}

void mostrarEstado(Dinosaurio dino1, Dinosaurio dino2) {
    printf("\nEstado actual:\n");
    printf("%s: %d HP\n", dino1.nombre, dino1.vida);
    printf("%s: %d HP\n", dino2.nombre, dino2.vida);
}

void menuCombate(Dinosaurio *atacante, Dinosaurio *defensor) {
    int opcion;
    printf("\nTurno de %s\n", (*atacante).nombre);
    printf("1) Morder\n");
    printf("2) Huir\n");
    printf("Elige tu acción: ");
    scanf("%d", &opcion);

    switch(opcion) {
        case 1:
            morder(defensor);
            printf("%s muerde a %s!\n", (*atacante).nombre, (*defensor).nombre);
            break;
        case 2:
            printf("%s huye! %s gana!\n", (*atacante).nombre, (*defensor).nombre);
            (*atacante).vida = 0;
            break;
        default:
            printf("Opción inválida, pierdes el turno!\n");
    }
}

void menu() {
    int opcion;
    printf("============================\n");
    printf("=== Juego de Dinosaurios ===\n");
    printf("============================\n");
    printf("===   Quieres jugar ?    ===\n");
    printf("===  1) SI               ===\n");
    printf("===  2) NO               ===\n");
    printf("============================\n");
    scanf("%d", &opcion);

    if (opcion == 1) {
        Dinosaurio dino1, dino2;
        dino1.vida = 100;
        dino2.vida = 100;

        printf("Nombre del dinosaurio 1: ");
        scanf("%s", dino1.nombre);
        printf("Nombre del dinosaurio 2: ");
        scanf("%s", dino2.nombre);

        int turno = 1;
        while (dino1.vida > 0 && dino2.vida > 0) {
            mostrarEstado(dino1, dino2);
            
            if (turno % 2 == 1) {
                menuCombate(&dino1, &dino2);
            } else {
                menuCombate(&dino2, &dino1);
            }
            
            turno++;
        }

        mostrarEstado(dino1, dino2);
        if (dino1.vida <= 0) {
            printf("\n¡%s ha ganado!\n", dino2.nombre);
        } else {
            printf("\n¡%s ha ganado!\n", dino1.nombre);
        }
    } else if (opcion == 2) {
        printf("Saliendo...\n");
    } else {
        printf("ERROR: Opción inválida\n");
    }
}

int main() {
    menu();
    return 0;
}