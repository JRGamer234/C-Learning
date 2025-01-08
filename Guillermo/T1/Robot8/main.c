#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void ImprimirTablero(int posRi, int posRj, int posBi, int posBj)
{
    int i,j;
    for(i = 0;i < 10;i++)

        {
            for(j = 0;j < 10;j++)
            {
                if(posRi == i && posRj == j)
                {
                    printf("R");
                }
                else if(posBi == i && posBj == j)
                {
                    printf("B");
                }
                else
                {
                    printf("_");
                }
            }
            printf("\n");
        }
}

char ElegirMovimiento()
{
    char movimiento;

    printf("Donde te quieres mover?\n(w)Arriba (s)Abajo (a)Izquierda (d)Derecha\n");
    printf(">");
    fflush(stdin);
    scanf("%c",&movimiento);

    return movimiento;
}

int main() {
    int posRi, posRj;
    int posBi, posBj;
    int i,j;
    int gasolina = 100;
    char movimiento;
    bool opcion_incorrecta = false;

    srand(time(NULL));

    printf("Bienvenid@ al programa del robot\n");
    do
    {
        //QUIERO PEDIR LAS COORDENADAS DE FILA COLUMNA DE UN ROBOT
        printf("Dame la coordenada de fila (0-9):");
        fflush(stdin);
        scanf("%d",&posRi);
        printf("Dame la coordenada de columna (0-9):");
        fflush(stdin);
        scanf("%d",&posRj);
   
        if(posRi < 0 || posRi > 9 || posRj < 0 || posRj > 9)
        {
            printf("El valor es incorrecto\n");
            opcion_incorrecta = true;
        }
        else
        {
            opcion_incorrecta = false;
        }
    }while(opcion_incorrecta == true);
   
    posBi = rand() % 10;
    posBj = rand() % 10;
   
    do
    {
        system("cls");
        printf("Te quedan %d de gasolina\n", gasolina);

        //QUIERO PINTAR EL MAPA DEL JUEGO
        ImprimirTablero(posRi,posRj,posBi,posBj);
        movimiento = ElegirMovimiento();
       
        do
        {    //QUIERO DAR LA OPCION AL USUARIO DE QUE MUEVA EL ROBOT
           
            switch(movimiento)
            {
                case 'w':
                {
                    if(posRi == 0)
                    {
                        posRi = 9;
                    }
                    else
                    {
                        posRi = posRi - 4; //posRi--;
                    }
                    gasolina = gasolina - 20; //gasolina-=10;
                    opcion_incorrecta = false;
                    break;
                }
                case 's':
                {
                    if(posRi == 9)
                    {
                        posRi = 0;
                    }
                    else
                    {
                        posRi = posRi + 4; //posRi++;
                    }
                    gasolina = gasolina - 20; //gasolina-=10;
                    opcion_incorrecta = false;
                    break;
                }
                case 'a':
                {
                    if(posRj == 0)
                    {
                        posRj = 9;
                    }
                    else
                    {
                        posRj = posRj - 4; //posRj--;
                    }
                    gasolina = gasolina - 20; //gasolina-=10;
                    opcion_incorrecta = false;
                    break;
                }
                case 'd':
                {
                    if(posRj == 9)
                    {
                        posRj = 0;
                    }
                    else
                    {
                        posRj = posRj + 4; //posRj++;
                    }
                    gasolina = gasolina - 20; //gasolina-=10;
                    opcion_incorrecta = false;
                    break;
                }
                default:
                {
                    opcion_incorrecta = true;
                    break;
                }
            }
            //COMPROBAR SI ESTOY ENCIMA DEL BIDON
            if(posRi == posBi && posRj == posBj)
            {
                gasolina = 100;
                posBi = rand() % 10;
                posBj = rand() % 10;
            }
           
        }while(opcion_incorrecta == true);
   
    }while(gasolina > 0);
   
    printf("Te has quedado sin gasolina\nGracias por jugar");

    return 0;
}
