#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    /*Guardar 5 nombres y notas de 5 alumnos usando malloc */

    char *nombres;
    int *notas;

    nombres = (char **)malloc(NUM_ALUMNOS * sizeof(char *));

    for(int i = 0; i < 5; i++){
        printf("Introduce el nombre del alumno ", (i+1), ": ");
        scanf("%s", nombres[i]);
        printf("Introduce la nota: ");
        scanf("%s", notas[i]);
    }

    for(int i = 0; i < 5; i++){
        printf("Nombre del alumno: %s", nombres[i], " -->  Nota: %d", notas[i]);
    }
    
}
