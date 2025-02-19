#include<stdio.h>
#include<conio.h>
#include<string.h>

#define longitud 10

struct persona{
    int telefono;
    char nombre[50];
    int notaMedia;
};

void agregarAlumno(struct persona *alumnos, int *contadorAlumnos) {
    if(*contadorAlumnos >= longitud) {
        printf("No hay espacio para mas alumnos\n");
        return;
    }
    
    printf("Introduce el nombre: ");
    scanf("%s", alumnos[*contadorAlumnos].nombre);
    printf("Introduce el telefono: ");
    scanf("%d", &alumnos[*contadorAlumnos].telefono);
    printf("Introduce la nota media: ");
    scanf("%d", &alumnos[*contadorAlumnos].notaMedia);
    
    (*contadorAlumnos)++;
}

void mostrarAlumnos(struct persona *alumnos, int *contadorAlumnos) {
    if(*contadorAlumnos == 0) {
        printf("No hay alumnos registrados\n");
        return;
    }
    
    for(int i = 0; i < *contadorAlumnos; i++) {
        printf("\nAlumno %d:\n", i+1);
        printf("Nombre: %s\n", alumnos[i].nombre);
        printf("Telefono: %d\n", alumnos[i].telefono);
        printf("Nota Media: %d\n", alumnos[i].notaMedia);
    }
}

void eliminarPorNombre(struct persona *alumnos, int *contadorAlumnos, char *nombre) {
    int encontrado = 0;
    
    for(int i = 0; i < *contadorAlumnos; i++) {
        if(strcmp(alumnos[i].nombre, nombre) == 0) {
            encontrado = 1;
            // Mover todos los elementos una posición hacia atrás
            for(int j = i; j < *contadorAlumnos - 1; j++) {
                alumnos[j] = alumnos[j + 1];
            }
            (*contadorAlumnos)--;
            printf("Alumno eliminado\n");
            break;
        }
    }
    
    if(!encontrado) {
        printf("No se encontro ningun alumno con ese nombre\n");
    }
}

void mayorAmenor(struct persona *alumnos, int *contadorAlumnos) {
    struct persona temp;
    
    for(int i = 0; i < *contadorAlumnos - 1; i++) {
        for(int j = 0; j < *contadorAlumnos - i - 1; j++) {
            if(alumnos[j].notaMedia < alumnos[j + 1].notaMedia) {
                temp = alumnos[j];
                alumnos[j] = alumnos[j + 1];
                alumnos[j + 1] = temp;
            }
        }
    }
}

void menorAmayor(struct persona *alumnos, int *contadorAlumnos) {
    struct persona temp;
    
    for(int i = 0; i < *contadorAlumnos - 1; i++) {
        for(int j = 0; j < *contadorAlumnos - i - 1; j++) {
            if(alumnos[j].notaMedia > alumnos[j + 1].notaMedia) {
                temp = alumnos[j];
                alumnos[j] = alumnos[j + 1];
                alumnos[j + 1] = temp;
            }
        }
    }
}

int main(){
    int contadorAlumnos = 0;
    int option = 0;
    struct persona alumnos[longitud];
    char aux[50];
    
    while(option != 6){
        printf("\nQue quieres hacer? \n");
        printf("1. Agregar alumno\n");
        printf("2. Mostrar alumnos\n");
        printf("3. Eliminar alumno por nombre\n");
        printf("4. Ordenar por nota (mayor a menor)\n");
        printf("5. Ordenar por nota (menor a mayor)\n");
        printf("6. Salir\n");
        
        option = getch();
        option = option - '0';
        
        switch(option){
            case 1:
                agregarAlumno(alumnos, &contadorAlumnos);
                break;
                
            case 2:
                mostrarAlumnos(alumnos, &contadorAlumnos);
                break;
                
            case 3: 
                printf("Introduce el nombre que quieres eliminar: ");
                scanf("%s", aux);
                eliminarPorNombre(alumnos, &contadorAlumnos, aux);
                break;
                
            case 4:
                mayorAmenor(alumnos, &contadorAlumnos);
                mostrarAlumnos(alumnos, &contadorAlumnos);
                break;
                
            case 5:
                menorAmayor(alumnos, &contadorAlumnos);
                mostrarAlumnos(alumnos, &contadorAlumnos);
                break;
        }
    }
    return 0;
}