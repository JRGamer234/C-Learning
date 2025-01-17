#include <stdio.h>
#include <stdlib.h>



#define OK 0

// estructuras

typedef struct coordenada
{
    float longitud;
    float latitud;
} Coord;

typedef struct personaje
{
    char nombre[30];
    int nivel;
    int exp;
    int hp;
    Coord spawn;
} Personaje;

int main(){
    struct coordenada posicion;

    Personaje pj;

    strcpy(pj.nombre, "Link");

    pj.nivel = 1;
    pj.hp = 100;
    pj.hp = 60;
    pj.spawn.longitud = 30.76757;
    pj.spawn.latitud = 25.12345;

    printf("Personaje: %s\nNivel: %d\nVida: %d\nMagia: %d\nCoordenadas spawn: %f %f\n", pj.nombre, pj.nivel, pj.hp, pj.spawn.latitud, pj.spawn.longitud);

    return OK;
}

