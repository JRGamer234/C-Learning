#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

int main(int argc, char *argv[]) {
    int i,j,k;
    int intentos = 0;
    char diccionario[10][30];
    char tablero[6][6];
    int estado[5];    //10000
    char alfabeto[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
   
    //0 letra no tratada
    //1 letra descubierta y en posicion
    //2 letra descubierta y descolocada
    //3 letra descartada
    char palabra_oculta[6];
    char palabra_intento[6];
    bool localizada = false;        
//INICIALIZACIONES
    srand(time(NULL));
    //DICCIONARIO
    strcpy(diccionario[0],"PERRO");
    strcpy(diccionario[1],"RADAR");
    strcpy(diccionario[2],"GORRA");
    strcpy(diccionario[3],"PENCA");
    strcpy(diccionario[4],"CARPA");
    strcpy(diccionario[5],"VOLAR");
    strcpy(diccionario[6],"LAVAR");
    strcpy(diccionario[7],"MIRAR");
    strcpy(diccionario[8],"TORRE");
    strcpy(diccionario[9],"BROCA");
    //ESTADO DEL ALFABETO
    for(i=0;i<26;i++)
        estado[i] = 0;
   
    for(i=0;i<6;i++)
        for(j=0;j<6;j++)
        {
            if(j == 5)
                tablero[i][j] = '\0';
            else
                tablero[i][j] = '_';
        }
   

    //(BONUS)DIBUJAR LAS LETRAS DISPONIBLES
   


    //ESTABLECER LA PALABRA OCULTA
    strcpy(palabra_oculta,diccionario[rand() % 10]);
    strcpy(palabra_intento,"_____");
    printf("HACK: Palabra Oculta es %s\n",palabra_oculta);
    do
    {
        //MOSTRAR TABLERO
        for(i=0;i<6;i++)
            printf("%s\n",tablero[i]);
        printf("\n");
        for(i=0;i<26;i++)
            printf("%c ",alfabeto[i]);
        printf("\n");
        //REINICIO ESTADO
        for(i=0;i<5;i++)
            estado[i] = 0;
        //PREGUNTAR POR UNA PALABRA AL USUARIO
        printf("%s\r",palabra_intento);
        fflush(stdin);
        scanf("%s", palabra_intento);
        strcpy(tablero[intentos],palabra_intento);
       
        intentos++;
        //ANALISIS/ALGORITMO DE WORDLE
        //QUIERO COGER CADA LETRA DE la palabra_intento
        //Y RECORRER la palabra_oculta VIENDO SI APARECE DICHA LETRA
        for(i=0;i<strlen(palabra_intento);i++)
        {
            localizada = false;
            for(j=0;j<strlen(palabra_oculta);j++)
            {
                if(estado[j] != 1 && palabra_intento[i] == palabra_oculta[j])
                {    
                    localizada = true;
                    //MISMA POSICION
                    if(i == j)
                    {
                        estado[j] = 1;
                        palabra_intento[j] = palabra_oculta[j];
                        tablero[intentos][j] = palabra_oculta[j];
                    }
                    else
                    {//DISTINTA POSICION
                        estado[i] = 2;
                    }
                }
            }
            if(!localizada)
            {
                estado[i] = 3;
                printf("Letra eliminada: %c\n",alfabeto[palabra_intento[i] - 65]);
                alfabeto[palabra_intento[i] - 65] = '_';
            }
        }
        printf("Informacion de estado:\n");
        for(i=0;i<5;i++)
            printf("%d",estado[i]);
        printf("\n");
    }while(intentos < 6 && strcmp(palabra_intento,palabra_oculta) != 0);
   
    //MOSTRAR TABLERO
    for(i=0;i<6;i++)
        printf("%s\n",tablero[i]);
    printf("\n");
    //CONDICION DE VICTORIA
    if(strcmp(palabra_intento,palabra_oculta) == 0)
    {
        printf("Enhorabuena\n Has consumido %d intentos",intentos);
    }
    else
    {
        printf("Lastima, has consumido los 6 intentos la palabra era %s",palabra_oculta);
    }
    //BONUS - ESTADISTICAS
   
    return 0;
}