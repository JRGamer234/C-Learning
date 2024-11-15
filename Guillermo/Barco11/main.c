#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
void ImprimirMapaORadar(char mapa[10][10])
{
    int i,j;
   
    printf("  ");
    for(i=0;i<10;i++)
        printf(" %d ",i);
    printf("\n");
    for(i=0;i<10;i++)
    {
        printf("%c ",i+65);
        for(j=0;j<10;j++)
        {
        printf(" %c ", mapa[i][j]);
        }
        printf("\n");
    }
}

void ColocarBarco(char mapa[10][10],int longitud_barco)
{
    int i,j,ci,cj,direccion_depliegue;
    bool desplegable;
    do
    {    
        desplegable = true;
        //PEDIR COORDENADA (ci,cj)
        ci = rand() % 10;
        cj = rand() % 10;
        //PEDIR DIRECCION (1Norte 2Sur 3Este 4Oeste)
        direccion_depliegue = 1 + rand()%4;
        //COMPROBAR LA VIABILIDAD DEL DESPLIEGUE DEL BARCO
        //(No salirse por los limites ni chocar con un barco que ya esté)
        if(direccion_depliegue == 1)
        {
            for(i=0;i<longitud_barco;i++)
                if(ci - i < 0 || mapa[ci-i][cj] == '@')
                    desplegable = false;
            if(desplegable)
                for(i=0;i<longitud_barco;i++)
                    mapa[ci - i][cj] = '@';    
        }
        if(direccion_depliegue == 2)
        {
            for(i=0;i<longitud_barco;i++)
                if(ci + i > 9 || mapa[ci+i][cj] == '@')
                    desplegable = false;
            if(desplegable)
                for(i=0;i<longitud_barco;i++)
                    mapa[ci + i][cj] = '@';    
        }
        if(direccion_depliegue == 3)
        {
            for(i=0;i<longitud_barco;i++)
                if(cj + i > 9 || mapa[ci][cj+i] == '@')
                    desplegable = false;
            if(desplegable)
                for(i=0;i<longitud_barco;i++)
                    mapa[ci][cj + i] = '@';    
        }
        if(direccion_depliegue == 4)
        {
            for(i=0;i<longitud_barco;i++)
                if(cj - i < 0 || mapa[ci][cj-i] == '@')
                    desplegable = false;
            if(desplegable)
                for(i=0;i<longitud_barco;i++)
                    mapa[ci][cj - i] = '@';
        }
    }while(!desplegable);
                   
}

int main(int argc, char *argv[])
{
    int i,j;
    char mapaJ1[10][10], mapaJ2[10][10], radarJ1[10][10],radarJ2[10][10];
   
    srand(time(NULL));
   
    printf("Hundir la Flota\n");
   
    //INICIALIZAR mapas y radares
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            mapaJ1[i][j] = '_';
            mapaJ2[i][j] = '_';
            radarJ1[i][j] = '?';
            radarJ2[i][j] = '?';
        }
    }
   
    //Colocar barcos J1 (aleatorio)
    ColocarBarco(mapaJ1,2);
    ColocarBarco(mapaJ1,3);
    ColocarBarco(mapaJ1,3);
    ColocarBarco(mapaJ1,4);
    ColocarBarco(mapaJ1,5);
    //Colocar barcos J2
    ColocarBarco(mapaJ2,2);
    ColocarBarco(mapaJ2,3);
    ColocarBarco(mapaJ2,3);
    ColocarBarco(mapaJ2,4);
    ColocarBarco(mapaJ2,5);
   
    printf("RADAR\n");
    ImprimirMapaORadar(radarJ1);
    printf("TABLERO\n");
    ImprimirMapaORadar(mapaJ1);
   
    //POR CADA TURNO
        //SELECCIONAR COORDENADA
        //SI AGUA ACTUALIZAR RADAR
        //SI TOCADO ACTUALIZAR RADAR Y MAPA DEL JUGADOR CONTRARIO
        //VICTORIA PARA EL PRIMER JUGADOR QUE HAGA 17 toques
   
    return 0;
}
