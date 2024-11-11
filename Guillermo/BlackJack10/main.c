#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main(int argc, char *argv[]) {
   
    bool mazo[52];    //0..12 Picas
                    //13..25 Corazones
                    //26..38 Diamantes
                    //39..51 Treboles
    int cartasJ1[15]; //Valores: 1=AS ..... 11=J 12=Q 13=K
    int cartasCPU[15];
    int max_cartasJ1=0, max_cartasCPU=0;
    int accJ1=0, accCPU=0;
    int carta;
    int opcion;
    int i;
   
    srand(time(NULL));
   
    //INICIALIZAR EL MAZO (Todo dentro) Y LAS CARTAS SACADAS
    for(i=0;i<52;i++)
    {
        mazo[i] = false;
    }
    for(i=0;i<15;i++)
    {
        cartasJ1[i] = 0;
        cartasCPU[i] = 0;
    }
   
    printf("Bienvenido al BlackJack\n");
   
    //LA CPU SACA DOS CARTAS
    carta = rand() % 52;
    mazo[carta] = true;
    cartasCPU[0] = 1 + (carta % 13);
    if(cartasCPU[0] >= 10 && cartasCPU[0] <=13)
        cartasCPU[0] = 10;
    max_cartasCPU++;
   
    do{
        carta = rand() % 52;
    }while(mazo[carta]);
    mazo[carta] = true;
    cartasJ1[0] = 1 + (carta % 13);
    if(cartasJ1[0] >= 10 && cartasJ1[0] <=13)
        cartasJ1[0] = 10;
    max_cartasJ1++;
   
    do{
        carta = rand() % 52;
    }while(mazo[carta]);
    mazo[carta] = true;
    cartasJ1[1] = 1 + (carta % 13);
    if(cartasJ1[1] >= 10 && cartasJ1[1] <=13)
        cartasJ1[1] = 10;
    max_cartasJ1++;
       
    do
    {
        printf("Cartas CPU: ");
        for(i=0; i<max_cartasCPU;i++)
        {
            printf("%d ", cartasCPU[i]);
        }
        printf("\n");
        printf("Cartas JUGADOR: ");
        for(i=0; i<max_cartasJ1;i++)
        {
            printf("%d ", cartasJ1[i]);
        }
        printf("\n");
        //OFRECER JUGAR
        printf("1.Pedir\n2.Plantarse\n3.Salir\n");
        scanf("%d", &opcion);
   
        if(opcion == 1)
        {
            //EXTRAER DEL MAZO Y GUARDAR EN cartasJ1
            do{
                carta = rand() % 52;
            }while(mazo[carta]);
            mazo[carta] = true;
           
            cartasJ1[max_cartasJ1] = 1 + (carta % 13);
            if(cartasJ1[max_cartasJ1] >= 10 && cartasJ1[max_cartasJ1] <=13)
                cartasJ1[max_cartasJ1] = 10;
            printf("\nHas sacado un %d\n",cartasJ1[max_cartasJ1]);
            max_cartasJ1++;
           
            //SI HE LLEGADO A 21 --> GANAR
            accJ1 = 0;
            for(i=0; i<max_cartasJ1;i++)
            {
                accJ1+=cartasJ1[i];
            }
            if(accJ1 == 21)
            {
                printf("\nGANA J1 porque ha llegado a 21\n");
                return 0;
            }
            //SI ME HE PASADO DE 21 --> PERDER
            if(accJ1 > 21)
            {
                printf("\nLa suma del J1 es: %d\n",accJ1);
                printf("PIERDE J1 porque se ha pasado.");
                return 0;
            }
        }
        else if(opcion == 2)
        {
            do{
                carta = rand() % 52;
            }while(mazo[carta]);
            mazo[carta] = true;
            cartasCPU[max_cartasCPU] = 1 + (carta % 13);
            if(cartasCPU[max_cartasCPU] >= 10 && cartasCPU[max_cartasCPU] <=13)
                cartasCPU[max_cartasCPU] = 10;
            printf("\nla CPU ha sacado un %d\n",cartasCPU[max_cartasCPU]);
            max_cartasCPU++;
           
            //La CPU esta obligada a plantarse con 16 o más
            accCPU = 0;
            for(i=0; i<max_cartasCPU;i++)
            {
                accCPU+= cartasCPU[i];
            }
            while(accCPU <=15)
            {
                do{
                    carta = rand() % 52;
                }while(mazo[carta]);
                mazo[carta] = true;
                cartasCPU[max_cartasCPU] = 1 + (carta % 13);
                if(cartasCPU[max_cartasCPU] >= 10 && cartasCPU[max_cartasCPU] <=13)
                    cartasCPU[max_cartasCPU] = 10;
                printf("\nla CPU ha sacado un %d\n",cartasCPU[max_cartasCPU]);
                max_cartasCPU++;
               
                accCPU = 0;
                for(i=0; i<max_cartasCPU;i++)
                {
                    accCPU+=cartasCPU[i];
                }
            }
            if(accCPU > 21)
            {
                printf("\nLa suma de la CPU es: %d\n",accCPU);
                printf("GANA J1 porque la CPU se ha pasado\n");
                return 0;
            }
            accJ1 = 0;
            for(i=0; i<max_cartasJ1;i++)
            {
                accJ1+=cartasJ1[i];
            }
            printf("El acumulado final del J1 es %d\nEl acumulado final de la CPU es %d\n",accJ1,accCPU);
            if(accCPU > accJ1)
                printf("PIERDE J1");
            else if(accCPU < accJ1)
                printf("GANA J1");
            else
                printf("EMPATE");
            return 0;
        }
        else
        {
            printf("Gracias por jugar\n");
            return 0;
        }
    }while(opcion!=2);
   
    return 0;
}
