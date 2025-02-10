#include <stdio.h>
#include <stdlib.h>


void solicitar(float *numero){
    printf("Introduce un numero: ");
    scanf("%f", numero);
}

/*Calculadora con funciones que usen paso por referencias*/
void sumar(float *resultado) {
    float num1, num2;
    solicitar(&num1);
    solicitar(&num2);
    *resultado = num1 + num2;
    printf("El resultado es: %f\n", *resultado);
}

/* Function to subtract two numbers */
void restar(float *resultado) {
    float num1, num2;
    solicitar(&num1);
    solicitar(&num2);
    *resultado = num1 - num2;
    printf("El resultado es: %.2f\n", *resultado);
}

/* Function to multiply two numbers */
void multiplicar(float *resultado) {
    float num1, num2;
    solicitar(&num1);
    solicitar(&num2);
    *resultado = num1 * num2;
    printf("El resultado es: %.2f\n", *resultado);
}

/* Function to divide two numbers */
void dividir(float *resultado) {
    float num1, num2;
    solicitar(&num1);
    solicitar(&num2);
    if(num2 != 0) {
        *resultado = num1 / num2;
        printf("El resultado es: %.2f\n", *resultado);
    } else {
        printf("ERRO. No se puede dividir por cero\n");
    }
}

void menu() {
    int opcion;
    float resultado;
    
    do {
        printf("\nMenu de calculadora:\n");
        printf("1) Sumar\n2) Restar\n3) Multiplicar\n4) Dividir\n5) Salir\n");
        printf("Selecciona una opcion: ");
        scanf("%d", &opcion);
        
        switch(opcion) {
            case 1:
                sumar(&resultado);
                break;
            case 2:
                restar(&resultado);
                break;
            case 3:
                multiplicar(&resultado);
                break;
            case 4:
                dividir(&resultado);
                break;
            case 5:
                printf("Saliendo ... \n");
                break;
            default:
                printf("ERROR\n");
        }
    } while(opcion != 5);
}


int main(){

     menu();

    return 0;



}