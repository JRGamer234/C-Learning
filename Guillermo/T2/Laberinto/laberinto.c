#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*Vamos ha desarrollar un programa que sea capaz de:
-Generar laberintos
-Editar laberintos
-Guardar en ficheros de texto dichos laberintos
-Cargar laberintos guardados
-Comprobar si un laberinto tiene solución
-Resolver laberintos con algoritmos devolviendo una ruta

La estructura de un laberinto debe contener un array bidimensional de caracteres cuyas celdas puedan tener valores: Pasillo (' '), Muro ('#'), una entrada ('E') y una salida ('S')
Tener en cuenta dentro de la estructura el tamaño de filas y columnas así como agregar un campo booleano llamado 'Modo Circular' que al activarse hace que el mapa actúe como un "mundo circular" (atravesar la fila del norte te saca por la sur, la columna del este te saca por el oeste, etc.)

La estructura de Ruta tiene que ser capaz de almacenar una colección de coordenadas de celdas que digan por donde han pasado desde la Entrada hasta la salida de un laberinto.*/

#define MAX 100

typedef struct {
    int x, y;
} Coordenada;

typedef struct {
    Coordenada coordenadas[MAX];
    int numCoordenadas;
} Ruta;

typedef struct {
    char **celdas;
    int filas, columnas;
    Coordenada entrada, salida;
    int modoCircular;
} Laberinto;

Laberinto *crearLaberinto(int filas, int columnas) {
    Laberinto *laberinto = (Laberinto *)malloc(sizeof(Laberinto));
    laberinto->filas = filas;
    laberinto->columnas = columnas;
    laberinto->celdas = (char **)malloc(filas * sizeof(char *));
    for (int i = 0; i < filas; i++) {
        laberinto->celdas[i] = (char *)malloc(columnas * sizeof(char));
        for (int j = 0; j < columnas; j++) {
            laberinto->celdas[i][j] = ' ';
        }
    }
    laberinto->modoCircular = 0;
    return laberinto;
}

void destruirLaberinto(Laberinto *laberinto) {
    for (int i = 0; i < laberinto->filas; i++) {
        free(laberinto->celdas[i]);
    }
    free(laberinto->celdas);
    free(laberinto);
}

void imprimirLaberinto(Laberinto *laberinto) {
    for (int i = 0; i < laberinto->filas; i++) {
        for (int j = 0; j < laberinto->columnas; j++) {
            printf("%c", laberinto->celdas[i][j]);
        }
        printf("\n");
    }
}

void guardarLaberinto(Laberinto *laberinto, char *nombreFichero) {
    FILE *fichero = fopen(nombreFichero, "w");
    fprintf(fichero, "%d %d\n", laberinto->filas, laberinto->columnas);
    for (int i = 0; i < laberinto->filas; i++) {
        for (int j = 0; j < laberinto->columnas; j++) {
            fprintf(fichero, "%c", laberinto->celdas[i][j]);
        }
        fprintf(fichero, "\n");
    }
    fclose(fichero);
}

Laberinto *cargarLaberinto(char *nombreFichero) {
    FILE *fichero = fopen(nombreFichero, "r");
    int filas, columnas;
    fscanf(fichero, "%d %d\n", &filas, &columnas);
    Laberinto *laberinto = crearLaberinto(filas, columnas);
    for (int i = 0; i < laberinto->filas; i++) {
        for (int j = 0; j < laberinto->columnas; j++) {
            fscanf(fichero, "%c", &laberinto->celdas[i][j]);
        }
        fscanf(fichero, "\n");
    }
    fclose(fichero);
    return laberinto;
}

int esCoordenadaValida(Laberinto *laberinto, Coordenada coordenada) {
    return coordenada.x >= 0 && coordenada.x < laberinto->filas && coordenada.y >= 0 && coordenada.y < laberinto->columnas;
}

int esPasillo(Laberinto *laberinto, Coordenada coordenada) {
    return laberinto->celdas[coordenada.x][coordenada.y] == ' ';
}

int esSalida(Laberinto *laberinto, Coordenada coordenada) {
    return coordenada.x == laberinto->salida.x && coordenada.y == laberinto->salida.y;
}

int esEntrada(Laberinto *laberinto, Coordenada coordenada) {
    return coordenada.x == laberinto->entrada.x && coordenada.y == laberinto->entrada.y;
}

int esMuro(Laberinto *laberinto, Coordenada coordenada) {
    return laberinto->celdas[coordenada.x][coordenada.y] == '#';
}

int esCoordenadaEnRuta(Ruta *ruta, Coordenada coordenada) {
    for (int i = 0; i < ruta->numCoordenadas; i++) {
        if (ruta->coordenadas[i].x == coordenada.x && ruta->coordenadas[i].y == coordenada.y) {
            return 1;
        }
    }
    return 0;
}

void anadirCoordenadaARuta(Ruta *ruta, Coordenada coordenada) {
    ruta->coordenadas[ruta->numCoordenadas] = coordenada;
    ruta->numCoordenadas++;
}

void quitarUltimaCoordenadaDeRuta(Ruta *ruta) {
    ruta->numCoordenadas--;
}

int resolverLaberinto(Laberinto *laberinto, Coordenada coordenada, Ruta *ruta) {
    if (!esCoordenadaValida(laberinto, coordenada) || esMuro(laberinto, coordenada) || esCoordenadaEnRuta(ruta, coordenada)) {
        return 0;
    }
    anadirCoordenadaARuta(ruta, coordenada);
    if (esSalida(laberinto, coordenada)) {
        return 1;
    }
    Coordenada norte = {coordenada.x - 1, coordenada.y};
    Coordenada sur = {coordenada.x + 1, coordenada.y};
    Coordenada este = {coordenada.x, coordenada.y + 1};
    Coordenada oeste = {coordenada.x, coordenada.y - 1};
    if (laberinto->modoCircular) {
        if (norte.x < 0) {
            norte.x = laberinto->filas - 1;
        }
        if (sur.x == laberinto->filas) {
            sur.x = 0;
        }
        if (este.y == laberinto->columnas) {
            este.y = 0;
        }
        if (oeste.y < 0) {
            oeste.y = laberinto->columnas - 1;
        }
    }
    if (resolverLaberinto(laberinto, norte, ruta) || resolverLaberinto(laberinto, sur, ruta) || resolverLaberinto(laberinto, este, ruta) || resolverLaberinto(laberinto, oeste, ruta)) {
        return 1;
    }
    quitarUltimaCoordenadaDeRuta(ruta);
    return 0;
}

int main() {
    Laberinto *laberinto = crearLaberinto(10, 10);
    laberinto->entrada.x = 0;
    laberinto->entrada.y = 0;
    laberinto->salida.x = 9;
    laberinto->salida.y = 9;
    laberinto->celdas[0][1] = '#';
    laberinto->celdas[1][1] = '#';
    laberinto->celdas[2][1] = '#';
    laberinto->celdas[3][1] = '#';
    laberinto->celdas[4][1] = '#';
    laberinto->celdas[5][1] = '#';
    laberinto->celdas[6][1] = '#';
    laberinto->celdas[7][1] = '#';
    laberinto->celdas[8][1] = '#';
    laberinto->celdas[9][1] = '#';
    Ruta ruta;
    ruta.numCoordenadas = 0;
    resolverLaberinto(laberinto, laberinto->entrada, &ruta);
    for (int i = 0; i < ruta.numCoordenadas; i++) {
        printf("(%d, %d)\n", ruta.coordenadas[i].x, ruta.coordenadas[i].y);
    }
    destruirLaberinto(laberinto);
    return 0;
}

