#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nombres[5];
    int notas[5];
} Alumnos;

int main() {
    Alumnos grupo;
    
    char aux[100];
    int auxNum;

    grupo.nombres = (char **)malloc(5 * sizeof(char *));
    grupo.notas = (int *)malloc(5 * sizeof(int));

    for (int i = 0; i < 5; i++) {
        printf("Introduce el nombre del alumno %d: ", i + 1);
        scanf("%s", aux);

        printf("Introduce la nota: ");
        scanf("%d", &auxNum);
        
        grupo.nombres[i] = (char *) malloc(sizeof(char)*strlen(aux));
        grupo.notas[i] = (int *) malloc(sizeof(int));
        
        *grupo.notas[i] = auxNum;
        strcpy(grupo.nombres[i], aux);
    }
    printf("\nResultados de los alumnos:\n");
    for (int i = 0; i < 5; i++) {
        printf("Nombre del alumno: %s --> Nota: %d\n", grupo.nombres[i], grupo.notas[i]);
    }
    for (int i = 0; i < 5; i++) {
        free(grupo.nombres[i]);
    }
    free(grupo.nombres);
    free(grupo.notas);

    return 0;
}

