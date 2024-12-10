#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    /*-Programa que reciba dos palabras y saque una tercera alternando sus letras. Si las palabras tienen diferente longitud, la cadena más larga se imprimirá hasta el final tras agotar las letras de la palabra corta.
    Ej: "poblado" y "ciudadela" traen a la salida: "pcoibuldaaddoela"
    */

    int i, j;
    char palabra1[100], palabra2[100], palabra3[200]

        printf("Introduce una palabra: \n");
    scanf("%s", palabra1);
    printf("Introduce otra palabra: \n");
    scanf("%s", palabra2);

    for (i = 0; i < length(palabra1); i++)
    {
        if (palabra1[i] != '\0')
        {
            palabra3[j] = palabra1[i];
            j++;
        }
        if (palabra2[i] != '\0')
        {
            {
                palabra3[j] = palabra2[i];
                j++;
            }
        }

        /*
        -Programa que pida introducir dos valores de la clásica ecuación Espacio = Tiempo x Velocidad. Dándole a elegir al usuario que dos variables va a leer, y calcular la tercera.
        Solicitar la repetición del programa, teniendo en cuenta que los valores calculados anteriormente sean almacenados de alguna forma y se vaya actualizando una media de las tres variables por separado. Mostrar dichas medias cada iteración.
        */

        double espacio = 0, tiempo = 0, velocidad = 0;             // Variables de la ecuación
        double sumaEspacio = 0, sumaTiempo = 0, sumaVelocidad = 0; // Acumuladores para las medias
        int iteraciones = 0;                                       // Contador de iteraciones
        char repetir;

        do
        {
            // Incrementamos el contador de iteraciones
            iteraciones++;

            // Mostramos opciones al usuario
            printf("Seleccione las dos variables que desea ingresar para calcular la tercera:\n");
            printf("1. Espacio y Tiempo (calcular Velocidad)\n");
            printf("2. Espacio y Velocidad (calcular Tiempo)\n");
            printf("3. Tiempo y Velocidad (calcular Espacio)\n");
            int opcion;
            scanf("%d", &opcion);

            switch (opcion)
            {
            case 1: // Calcular Velocidad
                printf("Ingrese el Espacio (m): ");
                scanf("%lf", &espacio);
                printf("Ingrese el Tiempo (s): ");
                scanf("%lf", &tiempo);
                velocidad = espacio / tiempo;
                printf("La Velocidad calculada es: %.2lf m/s\n", velocidad);
                break;
            case 2: // Calcular Tiempo
                printf("Ingrese el Espacio (m): ");
                scanf("%lf", &espacio);
                printf("Ingrese la Velocidad (m/s): ");
                scanf("%lf", &velocidad);
                tiempo = espacio / velocidad;
                printf("El Tiempo calculado es: %.2lf s\n", tiempo);
                break;
            case 3: // Calcular Espacio
                printf("Ingrese el Tiempo (s): ");
                scanf("%lf", &tiempo);
                printf("Ingrese la Velocidad (m/s): ");
                scanf("%lf", &velocidad);
                espacio = tiempo * velocidad;
                printf("El Espacio calculado es: %.2lf m\n", espacio);
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
                iteraciones--;
                continue;
            }

            // Actualizamos los acumuladores
            sumaEspacio += espacio;
            sumaTiempo += tiempo;
            sumaVelocidad += velocidad;

            // Mostramos las medias
            printf("Medias actuales:\n");
            printf("Espacio: %.2lf m\n", sumaEspacio / iteraciones);
            printf("Tiempo: %.2lf s\n", sumaTiempo / iteraciones);
            printf("Velocidad: %.2lf m/s\n", sumaVelocidad / iteraciones);

            // Preguntar si desea repetir
            printf("¿Desea repetir el programa? (s/n): ");
            scanf(" %c", &repetir); // Espacio antes de %c para eliminar cualquier carácter sobrante

        } while (repetir == 's' || repetir == 'S');

        printf("Gracias por usar el programa.\n");

        /*
        -Divisor de cadenas:
        Programa que pida una palabra y un numero. A la salida se debe dividir la palabra en dos cadenas diferentes por la posición indicada en el número
        Ej: "ecosistema" y el número 4
        A la salida imprimo dos cadenas "ecos" y "istema"
        */
        char palabra[100]; // Arreglo para almacenar la palabra
        int posicion;

        // Pedir al usuario la palabra
        printf("Ingrese una palabra: ");
        scanf("%s", palabra); // Leer palabra

        // Pedir la posición para dividir
        printf("Ingrese un numero para dividir la palabra: ");
        scanf("%d", &posicion);

        // Calcular la longitud manualmente
        int longitud = 0;
        while (palabra[longitud] != '\0')
        {
            longitud++;
        }

        // Validar que la posición esté dentro del rango
        if (posicion < 0 || posicion > longitud)
        {
            printf("La posición debe estar entre 0 y %d.\n", longitud);
            return 1;
        }

        // Crear las dos cadenas divididas manualmente
        char parte1[100] = {0}; // Inicializar con ceros
        char parte2[100] = {0};

        // Llenar la primera parte
        for (int i = 0; i < posicion; i++)
        {
            parte1[i] = palabra[i];
        }

        // Llenar la segunda parte
        for (int i = posicion; i < longitud; i++)
        {
            parte2[i - posicion] = palabra[i];
        }

        // Mostrar las partes resultantes
        printf("La primera parte es: \"%s\"\n", parte1);
        printf("La segunda parte es: \"%s\"\n", parte2);

        return 0;
    }
}