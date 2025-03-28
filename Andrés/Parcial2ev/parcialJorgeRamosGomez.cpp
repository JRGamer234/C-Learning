#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Somos parte del equipo de desarrollo de software de la ESA (Agencia Espacial Europea). Nos han encargado crear
un programa que ayude a decidir cuál nave es la más apropiada para la próxima misión de envío de astronautas a
Marte. Para lograrlo, el software debe:
1. Crear naves con los siguientes datos (1,5 punto):
o Nombre
o Peso de la nave en la Tierra
• Cada nave puede tener máximo 3 astronautas

2. Crear astronautas con (1,5 punto):
o Nombre
o Edad
o Profesión
o Peso del astronauta en la Tierra
o Nave a la que pertenece

3. Mostrar todas las naves con sus pesos tanto en la Tierra como en Marte (2 punto).
o El peso se obtiene de multiplicar la masa por la gravedad.
o La gravedad en la Tierra es 9.2 m/s2 y en Marte es 3.71 m/s2.
o La masa se calcula dividiendo el peso entre la gravedad del planeta de origen.

Ejemplo: si un astronauta “pesa” 70 kg en la Tierra, su masa sería 70 / 9.2 ˜ 7.6 kg.
4. Ordenar y mostrar las naves junto con sus astronautas, de la que tenga el equipo menos pesado al más
pesado (2 punto).

• El uso de punteros EN TODAS LAS FUNCIONES (1 punto) (Solo si tenemos 3 de los 4 puntos hechos )
• Código limpio, uso de funciones y buenas prácticas vistas en clase (1 punto) (Solo si tenemos 3 de los 4
puntos hechos )
• Es posible que la ESA cambie de opinión con el tamaño de los equipos y pida aumentar el limite de 3 a 5
miembros, nuestro código debería permitirlo cambiando solo UNA VARIABLE (1 punto)*/

#define MAX_ASTRONAUTAS 3
#define GRAVEDAD_TIERRA 9.2
#define GRAVEDAD_MARTE 3.71

typedef struct Nave {
    char nombre[50];
    float pesoTierra;
    float pesoMarte;
    struct Astronauta* astronautas[5];
    int num_astronautas;
} Nave;

typedef struct Astronauta {
    char nombre[50];
    int edad;
    char profesion[50];   
    float pesoTierra;
    struct Nave* nave;
} Astronauta;

void crearNave(Nave* nave, const char* nombre, float peso_tierra) {
    strcpy(nave->nombre, nombre);
    nave->pesoTierra = peso_tierra;
    nave->num_astronautas = 0;
}

void crearAstronauta(Astronauta* astronauta, const char* nombre, int edad, const char* profesion, float peso_tierra, Nave* nave) {
    strcpy(astronauta->nombre, nombre);
    astronauta->edad = edad;
    strcpy(astronauta->profesion, profesion);
    astronauta->pesoTierra = peso_tierra;
    astronauta->nave = nave;
    nave->astronautas[nave->num_astronautas++] = astronauta;
}

void agregarAstronautaANave(Nave* nave, Astronauta* astronauta) {
    if (nave->num_astronautas < MAX_ASTRONAUTAS) {
        nave->astronautas[nave->num_astronautas++] = astronauta;
    } else {
        printf("La nave %s ya tiene el máximo de astronautas.\n", nave->nombre);
    }
}

float calcularMasa(float peso, float gravedad) {
    return peso / gravedad;
}

float calcularPesoMarte(float masa) {
    return masa * GRAVEDAD_MARTE;
}

void mostrarNaves(Nave* naves, int num_naves) {
    for (int i = 0; i < num_naves; i++) {
        Nave* nave = &naves[i];
        printf("Nave %s\n", nave->nombre);
        printf("Peso en la Tierra: %.2f kg\n", nave->pesoTierra);
        nave->pesoMarte = calcularPesoMarte(calcularMasa(nave->pesoTierra, GRAVEDAD_TIERRA));
        printf("Peso en Marte: %.2f kg\n", nave->pesoMarte);
        printf("Astronautas:\n");
        for (int j = 0; j < nave->num_astronautas; j++) {
            Astronauta* astronauta = nave->astronautas[j];
            printf("  %s\n", astronauta->nombre);
        }
        printf("\n");
    }
}

void ordenarNaves(Nave* naves, int num_naves) {
    for (int i = 0; i < num_naves - 1; i++) {
        for (int j = 0; j < num_naves - i - 1; j++) {
            if (naves[j].pesoTierra > naves[j + 1].pesoTierra) {
                Nave temp = naves[j];
                naves[j] = naves[j + 1];
                naves[j + 1] = temp;
            }
        }
    }
}

int main(){

    // naves
    int num_naves, num_astronautas;
    printf("Ingrese el número de naves: ");
    scanf("%d", &num_naves);
    Nave naves[num_naves];

    for (int i = 0; i < num_naves; i++) {
        char nombre_nave[50];
        float peso_tierra;
        printf("Ingrese el nombre de la nave %d: ", i + 1);
        scanf("%s", nombre_nave);
        printf("Ingrese el peso de la nave %d en la Tierra: ", i + 1);
        scanf("%f", &peso_tierra);
        crearNave(&naves[i], nombre_nave, peso_tierra);
    }
    //astronautas
    printf("Ingrese el número de astronautas: ");
    scanf("%d", &num_astronautas);
    Astronauta astronautas[num_astronautas];

    for (int i = 0; i < num_astronautas; i++) {
        char nombre_astronauta[50], profesion[50];
        int edad;
        float peso_tierra;
        int nave_i;
        printf("\n Introduce nombre del astronauta: ");
        scanf("%s", &nombre_astronauta);
        printf("\n Introduce edad: ");
        scanf("%d", &edad);
        printf("\n Introduce profesion: ");
        scanf("%s", &profesion);
        printf("\n Introduce peso en la tierra: ");
        scanf("%f", &peso_tierra);
		
		printf("Seleccione la nave a la que pertenece (0 - %d): ", num_naves - 1);
        scanf("%d", &nave_i);
        
        if (nave_i >= 0 && nave_i < num_naves) {
            crearAstronauta(&astronautas[i], nombre_astronauta, edad, profesion, peso_tierra, &naves[nave_i]);
        } else {
            printf("Número de nave inválido.\n");
        }
	}

    printf("\n--- Lista de Naves y Astronautas ---\n");
    mostrarNaves(naves, num_naves);
    ordenarNaves(naves, num_naves);
    printf("\n--- Naves Ordenadas por Peso ---\n");
    mostrarNaves(naves, num_naves);

    return 0;
	
	
}
