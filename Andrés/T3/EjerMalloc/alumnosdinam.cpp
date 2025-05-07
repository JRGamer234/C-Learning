/*struct alumno{
    char *nombre;
    int notaC;
    int notaJava;
}
printf("Que quieres hacer? \n");
printf("1. Agregar alumno\n");
printf("2. Mostrar alumnos\n");
printf("3. Media de la clase\n");
printf("4. Eliminar alumno por nombre\n");*/

#include <stdio.h>
#include <conio.h>

struct alumno{
    char *nombre;
    int notaC;
    int notaJava;
    struct alumno *sig; //para hacer referencia
}

struct alumno *primero = NULL; //NO hay que tocarlo

void agregarAlumno(){
    struct alumno *actual = primero; //Cuando se trabaja con struct hay que duplicar el puntero 
    struct alumno *nuevo;

    char buffer[50];

    while(actual != NULL && actual->sig != NULL){
        actual = actual->sig;
    }

    //struct alumno nuevo
    nuevo = (struct alumno *) malloc(sizeof(struct alumno));

    printf("Introduce el nombre de un alumno: ");
    scanf("%s", buffer);
    printf("\nIntroduce la nota de C: ");
    scanf("%d", &nuevo->notaC);
    printf("\nIntroduce la nota de JAVA: ");
    scanf("%d", &nuevo->notaJava);

    nuevo->nombre = (char *) malloc(sizeof(char) * (strlen(buffer)+ 1));
    strcpy(nuevo->nombre, buffer)

    if(primero == NULL){
        primero = nuevo;
    }else{
        actual->sig = nuevo;
    }
}


int main(){
    int option  = 1;
    while(option != 0){
        printf("Que quieres hacer? \n");
    printf("1. Agregar alumno\n");
    printf("2. Mostrar alumnos\n");
    printf("3. Media de la clase\n");
    printf("4. Eliminar alumno por nombre\n");
    }

}