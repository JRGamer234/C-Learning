#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <libreria.h>

/*Pedir por teclado una palabra de mínimo 10 letras, tenemos
que escoger aleatoriamente una de las letras de la palabra (no la enseñamos), el
usuario tiene que introducir letras hasta adivinar cual es la letra (10 minutos)*/

void ejer1()
{
    char palabra[100];
    char letra;
    int aleatorio;
    int acertado = 0;

    srand(time(NULL));

    // Pedir palabra de al menos 10 letras
    do
    {
        printf("Introduce una palabra de mínimo 10 letras: ");
        scanf("%s", palabra);
        if (mi_strlen(palabra) < 10)
        {
            printf("La palabra tiene menos de 10 letras.\n");
        }
    } while (mi_strlen(palabra) < 10);

    // Elegir letra aleatoria
    aleatorio = rand() % mi_strlen(palabra);
    char letra_secreta = palabra[aleatorio];

    // Bucle hasta que adivine
    while (!acertado)
    {
        printf("Adivina la letra secreta: ");
        scanf(" %c", &letra);

        if (letra == letra_secreta)
        {
            acertado = 1;
            printf("CORRECTO \nLa letra secreta era '%c'.\n", letra_secreta);
        }
        else
        {
            printf("INCORRECTO. Intenta otra vez.\n");
        }
    }

    printf("La palabra era: %s\n", palabra);
}

/*Menú que pida al usuario (30 minutos):


-Crear vehículos (modelo, velocidad)

-Calcular cuánto tiempo tardaría cada vehículo en hacer un recorrido de X km (pidiendo
por teclado los km)

-Eliminar vehículos*/

void ejer2()
{

    char vehiculos[10][20];
    int velocidad[10];
    int opcion;
    int n = 0;
    do
    {
        printf("1) Crear vehiculos\n");
        printf("2) Calcular tiempo de recorrido\n");
        printf("3) Eliminar vehiculos\n");
        printf("4) Mostrar lista\n");
        printf("5) Salir\n");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
        {
            printf("\n¿Cuántos vehículos quieres añadir? (máx 10): ");
            int cantidad;
            scanf("%d", &cantidad);
            if (n + cantidad > 10)
            {
                printf("¡No puedes añadir tantos vehículos!\n");
                break;
            }

            for (int i = 0; i < cantidad; i++)
            {
                printf("\nIntroduce el modelo %d: ", (n + 1));
                scanf("%s", vehiculos[n]);

                printf("Introduce la velocidad de %s: ", vehiculos[n]);
                scanf("%d", &velocidad[n]);
                n++;
            }
        }
        break;
        case 2:
        {
            int distancia, coche;
            printf("Introduce los kms para calcular el tiempo que tarda el vehiculo: ");
            scanf("%d", &distancia);
            printf("Introduce que vehiculo quieres que haga el recorrido (1-%d): ", n);
            scanf("%d", &coche);
            float tiempo = (float)distancia / velocidad[coche - 1];
            printf("Tiempo: %f", tiempo);
        }
        break;
        case 3:
        {
            char vehiculoEliminar[20];
            printf("Introduce el nombre del vehiculo a eliminar: ");
            scanf("%s", vehiculoEliminar);

            // Buscar posición
            int pos = -1;
            for (int i = 0; i < n; i++)
            {
                if (mi_strcmp(vehiculos[i], vehiculoEliminar) == 0)
                {
                    pos = i;
                    break;
                }
            }

            if (pos != -1)
            {
                // Mover todos hacia la izquierda
                for (int i = pos; i < n - 1; i++)
                {
                    mi_strcpy(vehiculos[i], vehiculos[i + 1]);
                    velocidad[i] = velocidad[i + 1];
                }
                n--;
                printf("Vehiculo eliminado.\n");
            }
            else
            {
                printf("Vehiculo no encontrado.\n");
            }
        }
        break;
        case 4:
        {
            printf("\nLista de vehículos:\n");
            for (int i = 0; i < n; i++)
            {
                printf("%s: %d km/h\n", vehiculos[i], velocidad[i]);
            }
        }
        break;
        case 5:
        {
            printf("Saliendo...");
        }
        break;
        default:
            printf("ERROR");
            break;
        }
    } while (opcion != 5);
}

/*Pedir por teclado 10 palabras y 10 números (cada palabra va
relacionada con un numero), tenemos que ordenar de mayor a menor todas las
palabras usando como criterio la suma del valor ascii de cada una de sus letras
EN MINUSCULA + el numero que tenia asociada la palabra (30 minutos)*/

void ejer3(){
    
}


/*Tenemos que desarrollar un simulador de combates con
monstruos, al principio el simulador tiene que pedir nuestras estadísticas (ataque,
defensa y vida) (ataque y defensa puede ser de 1 a 100 y la vida de 100 a 1000)
y luego generar 10 monstruos con estadísticas aleatorias, el daño del combate
se determina restándole a la defensa del atacado el ataque del que ataca y al
que primero se le acabe la vida pierde. El simulador tiene que empezar a
simular cada combate empezando por el monstruo más débil (el que la suma de si
ataque y defensa sea más baja) y nos dirá los monstruos que nuestro personaje ha
logrado derrotar (la vida se reinicia en cada combate)*/

int main()
{
    ejer2();
}