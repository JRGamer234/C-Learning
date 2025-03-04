#include <stdio.h>

typedef struct coordenadas
{
    int longitud;
    int latitud;
} COORD;

void SumarALongitud(COORD *coo, int desp)
{
    coo->longitud += desp;    //(*coo).longitud += desp;
   
}
void CopiarCoordenadas(COORD *lista_destino, COORD *lista_origen)
{
    int i;
    COORD *lista_origen_inicio;
    COORD *lista_destino_inicio;
   
    for(i=0;i<5;i++)
    {
        lista_destino[i].longitud = lista_origen[i].longitud;
        lista_destino[i].latitud = lista_origen[i].latitud;
    }
   
    /*        //NOTACION TEORICA CLASICA DE PUNTEROS
    lista_origen_inicio = lista_origen;
    lista_destino_inicio = lista_destino;
   
    for(i=0;i<5;i++)
    {
        lista_destino->longitud = lista_origen->longitud;
        lista_destino->latitud = lista_origen->latitud;
        lista_destino++;
        lista_origen++;
    }
    lista_destino = lista_destino_inicio;
    lista_origen = lista_origen_inicio;
    */
   
}

void main()
{
    int i;
    int desplazamiento;
    COORD c;
    COORD ruta_coordenadas[5];
    COORD ruta_copia[5];
   
    c.latitud = 5;
    c.longitud = 5;
   
    for(i=0; i<5;i++)
    {
        ruta_coordenadas[i].longitud = 55;
        ruta_coordenadas[i].latitud = 55;
        ruta_copia[i].longitud = 0;
        ruta_copia[i].latitud = 0;
    }
   
    printf("ANTES:\n");
    for(i=0;i<5;i++)
    {
        printf(" %d %d <---->", ruta_copia[i].longitud,
                                ruta_copia[i].latitud );
    }
   
    CopiarCoordenadas(ruta_copia,ruta_coordenadas);
   
    printf("\nDESPUES:\n");
    for(i=0;i<5;i++)
    {
        printf(" %d %d <---->", ruta_copia[i].longitud,
                                ruta_copia[i].latitud );
    }
}