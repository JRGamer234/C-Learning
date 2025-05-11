#include <stdlib.h>
#include <stdio.h>

void ejer1(){
    int num[10];
    int sum = 0;
    for(int i =0 ; i < 10 ; i++){
        printf("Introduce un numero (%d): ", (i+1));
        scanf("%d", &num[i]);
        sum += num[i];
    }
    printf("La suma de los numeros es: %d\n", sum);
}

void ejer2(){
    int num2[20];
    int mayor=0,menor=0;
    for(int i =0 ; i < 20 ; i++){
        printf("Introduce un numero (%d): ", (i+1));
        scanf("%d", &num2[i]);
    }
    for(int i =1; i<20;i++){
        if(num2[i]>mayor){
            mayor=num2[i];
        }
        if(num2[i]<menor){
            menor=num2[i];
        }
    }
    printf("El mayor es: %d\n", mayor);
    printf("El menor es: %d\n", menor);
}

void ejer3(){
    int nota[30];
    int promedio = 0;
    int suma = 0;
    int est = 0;
    for(int i = 0; i < 30 ; i++){
        printf("Introduce una nota (%d): ", (i+1));
        scanf("%d", &nota[i]);
        suma += nota[i];
    }
    promedio = suma / 30;
    for (int i = 0; i < 30; i++){
        if(nota[i] > promedio){
            est++;
        }
    }
    printf("El promedio de las notas es: %d\n", promedio);
    printf("El numero de estudiantes que superaron el promedio es: %d\n", est);

}

void ejer4(){
    char vocal[] = "aeiouAEIOU";
    int cont = 0;
    char palabra[100];
    printf("Introduce una palabra: ");
    scanf("%s", palabra);
    while (palabra[i] != '\0'){{
        for(int j = 0; vocales[j] != '\0'; j++){
            if(palabra[i] == vocal[j]){
                cont++;
            }
        }
    }
    printf("La palabra que has introducido tiene %d vocalles.", cont);
    
}


int main(){
    ejer4();

}