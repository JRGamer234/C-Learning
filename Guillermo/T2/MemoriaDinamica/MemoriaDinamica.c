#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,j;
    int filas, columnas;
    int n_letras;
    char *nombre;
   
    char **tablero;
   
    printf("Cuantas letras tiene tu nombre? Quiero reservar la memoria exacta para ello\n");
    fflush(stdin);
    scanf("%d", &n_letras);
   
    nombre = malloc((n_letras + 1) * sizeof(int));
    printf("Escribe tu nombre:");
    fflush(stdin);
    scanf("%s",nombre);
    printf("Tu nombre es %s\n",nombre);
   
    //Definicion de un tablero en memoria dinamica
    printf("Cuantas filas columnas exactas quieres para un tablero? (f c):");    
    fflush(stdin);
    scanf("%d %d", &filas, &columnas);
   
    tablero = malloc(filas * sizeof(char*));
   
    for(i=0; i < filas; i++)
    {
        tablero[i] = malloc(columnas*sizeof(char));
    }
   
    //El tablero esta LISTO
    for(i=0;i<filas;i++)
        for(j=0; j< columnas; j++)
            tablero[i][j] = '_';
       
    tablero[0][0] = 'w';
    tablero[1][1] = 'w';
    tablero[2][2] = 'w';
   
    for(i=0;i<filas;i++)
    {
        for(j=0; j< columnas; j++)
        {
            printf("%c", tablero[i][j]);
        }
        printf("\n");    
    }
   
   
    //ZONA DE LIBERACION DE MEMORIA
    for(i=0;i<filas;i++)
    {
        free(tablero[i]);
    }
    free(tablero);
   
    free(nombre);
   
    return 0;
}ç