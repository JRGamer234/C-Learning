#include <stdio.h>
#include <stdlib.h>
#include <libreria.h>


/*1. Máximo Común Divisor y Mínimo Común Múltiplo:
o Solicitar dos números al usuario.
o Calcular y mostrar su máximo común divisor (MCD) y mínimo común múltiplo (MCM).
(0,5 puntos)*/
int mcd(int num1, int num2){
    while (num2 != 0){
        int temp = num2;
        num2 = num1 % num2;
        num1 = temp; 
    }
    return num1;
}
int mcm(int num1, int num2){
    return (num1 * num2) / mcd(num1 , num2);
}

void ejer1(){
    int num1, num2;
    printf("Ingrese el primer numero: ");
    scanf("%d", &num1);
    printf("\nIngrese el segundo numero: ");
    scanf("%d", &num1);

    printf("\nEl MCD es: %d", mcd(num1, num2));
    printf("\nEl MCM es: %d", mcm(num1, num2));
}

/*2. Manipulación de Cadenas:
o Solicitar una palabra.
o Mostrarla invertida.
o Convertirla y mostrarla en mayúsculas.
o Convertirla y mostrarla en minúsculas.
o Mostrarla con solo la primera letra en mayúscula y el resto en minúsculas.
(1 punto)*/

void ejer2(){
    char palabra[100], resultado[100];
    printf("Introduce una palabra: ");
    scanf("%s", palabra);
    
    invertir_palabra(palabra, resultado);
    printf("Palabra invertida: %s", resultado);

    for(int i = 0; palabra[i] != '\0'; i++){
        resultado[i] = minuscula_a_mayuscula(palabra[i]);
        resultado[mi_strlen(palabra)] = '\0';
        printf("Mayuscula: %s", resultado);
    }
    for(int i = 0; palabra[i] != '\0'; i++){
        resultado[i] = mayuscula_a_minuscula(palabra[i]);
        resultado[mi_strlen(palabra)] = '\0';
        printf("Minuscula: %s", resultado);
    }
    resultado[0] = minuscula_a_mayuscula(palabra[0]);
    for(int i = 1; palabra[i] != '\0'; i++){
        resultado[i] = mayuscula_a_minuscula(palabra[i]);
        resultado[mi_strlen(palabra)] = '\0';
        printf("Primera letra mayuscula: %s", resultado);
    }
    
}

/*3. Extracción de Vocales:
o Solicitar una palabra.
o Mostrar únicamente las letras que sean vocales.
(0,5 puntos)*/

void ejer3(){
    char palabra[100], vocales[100];
    printf("Introduce una palabra: ");
    scanf("%s", palabra);
    obtener_vocales(palabra, vocales);
    printf("Vocales: %s", vocales);
}

/*4. Extracción de Consonantes:
o Solicitar una palabra.
o Mostrar únicamente las letras que no sean vocales.
(0,5 puntos)*/

void ejer4(){
    char palabra[100], consonantes[100];
    printf("Introduce una palabra: ");
    scanf("%s", palabra);
    obtener_consonantes(palabra, consonantes);
    printf("Consonantes: %s", consonantes);
}

/*5. Vocal más Repetida:
o Solicitar una palabra.
o Determinar y mostrar cuál es la vocal que se repite con mayor frecuencia.
(0,5 puntos)*/

void ejer5(){
    char palabra[100];
    int contador[255];
    printf("Introduce una palabra: ");
    scanf("%s",palabra);

}

/*6. Dígito Primo Mayor:
o Solicitar un número.
o Mostrar el dígito que sea primo y, de ellos, el mayor.
(1 punto)*/
int primo(int x){
    if(x < 2){
        return 0;
    }
    for(int i = 2; i <= x/2; i++){
        if(x % i == 0){
            return 0;
        }
    }
    return 1;
}
void ejer6(){
    char numero[100];
    printf("Introduce un numero: ");
    scanf("%s", numero);
    int mayor = -1;
    for(int i = 0; numero[i] != '\0'; i++){
        int y = char_a_int(numero[i]);
        if(primo(y) && y > mayor){
            mayor = y;
        }
    }
    if(mayor != -1){
        printf("Mayor primo: %d", mayor);
    }else{
        printf("No hay primos");
    }
}

/*7. Registro de Alumno:
o Permitir dar de alta a un alumno solicitando:
▪ Nombre
▪ DNI
▪ Nota en C
▪ Nota en Web
▪ Nota en Entornos
(1 punto)*/
typedef struct{
    char nombre[50];
    char dni[9];
    float notaC;
    float notaWeb;
    float notaEntornos;
}Alumno;

void ejer7(){
    Alumno alumnos[100];
    int total_alumnos = 0;
    printf("Nombre: ");
    scanf("%s", alumnos[total_alumnos].nombre);
    printf("DNI: ");
    scanf("%s", alumnos[total_alumnos].dni);
    printf("Nota en C: ");
    scanf("%f", alumnos[total_alumnos].notaC);
    printf("Nota en Web: ");
    scanf("%f", alumnos[total_alumnos].notaWeb);
    printf("Nota en Entornos: ");
    scanf("%f", alumnos[total_alumnos].notaEntornos);
    total_alumnos++;
    /*8. Listado de Alumnos:
    o Mostrar todos los alumnos que hayan sido registrados.
    (1 punto)*/
    for(int i = 0; i < total_alumnos; i++){
        printf("Alumno %d: ", (i+1));
        printf("Nombre: %s, DNI: %s, Nota en C: %f, Nota en Web: %f, Nota en Entornos: %f\n", alumnos[i].nombre, alumnos[i].dni, alumnos[i].notaC, alumnos[i].notaWeb, alumnos[i].notaEntornos);
    }
}



/*9. Eliminación de Alumno:
o Permitir eliminar un alumno ingresando su nombre.
o (2 puntos, o 1 punto si se realiza sin aritmética de punteros).*/
void ejer9(){
    char EliminarAlumno;
    printf("Que alumno quieres eliminar?");
    scanf("%s", &EliminarAlumno);
    
}

/*10. Ordenación de Alumnos:
o Ordenar los alumnos según su nota media de mayor a menor.
o (2 puntos, o 1 punto si se implementa sin aritmética de punteros).*/

float media(Alumno alumnos[]){
    for(int i = 0; i < 100;i++){
        float suma = alumnos[i].notaC + alumnos[i].notaWeb + alumnos[i].notaEntornos;
        float media = suma / 100;
    }
}
 void ejer10(){
    
 }


void menu(){
    int opcion;
    do {
        printf("1. Máximo Común Divisor y Mínimo Común Múltiplo\n");
        printf("2. Manipulación de Cadenas\n");
        printf("3. Extracción de Vocales\n");
        printf("4. Extracción de Consonantes\n");
        printf("5. Vocal más Repetida\n");
        printf("6. Dígito Primo Mayor\n");
        printf("7. Registro de Alumno\n");
        printf("8. Listado de Alumnos\n");
        printf("9. Eliminación de Alumno\n");
        printf("10. Ordenación de Alumnos\n");
        printf("11. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                ejer1();
                break;
            case 2:
                ejer2();
                break;
            case 3:
                ejer3();
                break;
            case 4:
                ejer4();
                break;
            case 5:
                ejer5();
                break;
            case 6:
                ejer6();
                break;
            case 7:
                ejer7();
                break;
            case 8:
                printf("Listado de alumnos:\n");
                break;
            case 9:
                ejer9();
                break;
            case 10:
                ejer10();
                break;
            case 11:
                printf("Saliendo...\n");
                break;
            default:
                printf("ERROR\n");
                break;
        }
    } while (opcion != 11);
}

int main(){
    menu();
}