#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <libreria.h>

/*Pedir por teclado una palabra de mínimo 10 letras, tenemos
que escoger aleatoriamente una de las letras de la palabra (no la enseñamos), el
usuario tiene que introducir letras hasta adivinar cual es la letra (10 minutos)*/

void ejer1(){

    char palabra[20];
    char letra;
    int i, aleatorio, aciertos;

    srand(time(NULL));

    printf("Introduce una palabra de al menos 10 letras: ");
    scanf("%s", palabra);

    aleatorio = rand() % mi_strlen(palabra);

    do {
        printf("Introduce una letra: ");
        scanf(" %c", &letra);

        aciertos = 0;

        for (i = 0; i < mi_strlen(palabra); i++) {
            if (palabra[i] == letra) {
                aciertos++;
            }
        }

        if (aciertos > 0) {
            printf("Has acertado %d letras\n", aciertos);
        } else {
            printf("No has acertado ninguna letra\n");
        }

    } while (aciertos == 0);

    printf("La palabra era: %s\n", palabra);
    printf("La letra aleatoria era: %c (posición %d)\n", palabra[aleatorio], aleatorio);

}


/*Menú que pida al usuario (30 minutos):


                -Crear vehículos
(modelo, velocidad)


                -Calcular
cuánto tiempo tardaría cada vehículo en hacer un recorrido de X km (pidiendo
por teclado los km)


                -Eliminar
vehículos
*/

 


/*Pedir por teclado 10 palabras y 10 números (cada palabra va
relacionada con un numero), tenemos que ordenar de mayor a menor todas las
palabras usando como criterio la suma del valor ascii de cada una de sus letras
EN MINUSCULA + el numero que tenia asociada la palabra (30 minutos)*/


 


/*Tenemos que desarrollar un simulador de combates con
monstruos, al principio el simulador tiene que pedir nuestras estadísticas (ataque,
defensa y vida) (ataque y defensa puede ser de 1 a 100 y la vida de 100 a 1000)
y luego generar 10 monstruos con estadísticas aleatorias, el daño del combate
se determina restándole a la defensa del atacado el ataque del que ataca y al
que primero se le acabe la vida pierde. El simulador tiene que empezar a
simular cada combate empezando por el monstruo más débil (el que la suma de si
ataque y defensa sea más baja) y nos dirá los monstruos que nuestro personaje ha
logrado derrotar (la vida se reinicia en cada combate)*/







int main(){
    ejer1();
}