#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//DEFINES
#define OK 0
#define WARNING 2
#define ERROR -1
//ESTRUCTURAS y TYPEDEFs
//Sintaxis
//typedef <Objeto/estructura a definir> <Nombre nuevo>;
typedef struct coordenada
{
    float longitud;
    float latitud;
   
} Coord;

typedef struct logros
{
    char nombre[50];
    char descripcion[1000];
    bool desbloqueado;
} Logro;

typedef struct personaje
{
    char nombre[20];
    int nivel;
    int exp;
    int hp;
    int mp;
    Coord spawn;
    Logro lista_logros[10];
   
} Personaje;


//FUNCIONES
void InicializarPersonaje(Personaje *p,
                          char *nombre_inicial,
                          int nivel_inicial,
                          int exp_inicial,
                          int hp_inicial,
                          int mp_inicial,
                          char *nombre_logro_inicial,
                          char *desc_logro_inicial)
{
    strcpy(p->nombre,nombre_inicial);
    p->nivel = nivel_inicial;
    p->hp = hp_inicial;
    p->mp = mp_inicial;
    p->exp =  exp_inicial;
   
    p->spawn.latitud = 0.0;
    p->spawn.longitud = 0.0;
   
    strcpy(p->lista_logros[0].nombre, nombre_logro_inicial);
    strcpy(p->lista_logros[0].descripcion, desc_logro_inicial);
}



int main() {

    Personaje pj;
   
    strcpy(pj.nombre,"Link");
    pj.nivel = 1;
    pj.hp = 100;
    pj.mp = 60;
    pj.spawn.longitud = 30.76757;
    pj.spawn.latitud = 25.12345;
    strcpy(pj.lista_logros[0].nombre, "Kolegccionista");
    strcpy(pj.lista_logros[0].descripcion, "Consigue todos los kolog");
    pj.lista_logros[0].desbloqueado = false;
   
    printf("PERSONAJE: %s\nNivel: %d\nVida: %d\nMagia: %d\nCoordenadas spawn: %f %f\n Logro: %s - %s Desbloqueado: %d\n",
    pj.nombre,
    pj.nivel,
    pj.hp,
    pj.mp,
    pj.spawn.longitud,
    pj.spawn.latitud,
    pj.lista_logros[0].nombre,
    pj.lista_logros[0].descripcion,
    pj.lista_logros[0].desbloqueado
    );
   
    InicializarPersonaje(&pj,"McQueen",1,0,600,10,"Campeon impecable","Gana la Copa Piston sin tocar a otros corredores");
   
    printf("PERSONAJE: %s\nNivel: %d\nVida: %d\nMagia: %d\nCoordenadas spawn: %f %f\n Logro: %s - %s Desbloqueado: %d\n",
        pj.nombre,
        pj.nivel,
        pj.hp,
        pj.mp,
        pj.spawn.longitud,
        pj.spawn.latitud,
        pj.lista_logros[0].nombre,
        pj.lista_logros[0].descripcion,
        pj.lista_logros[0].desbloqueado
    );
               
    return OK;
}