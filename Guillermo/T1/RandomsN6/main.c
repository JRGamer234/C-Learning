#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
   
    int opcion, cpu, jugador1, jugador2, puntos1=0, puntos2=0, puntosb=0;
    char *opciones[] = {"Piedra", "Papel", "Tijera"};
   
    srand(time(NULL));
	do{
    printf("******************************\n");
    printf("*** Piedra, Papel o Tijera ***\n");
    printf("******************************\n");    
    printf("1) 1 vs 1\n2) 1 vs BOT\n3) Salir\n");
    
    printf("Elige una opción: ");
    scanf("%d", &opcion);

    switch (opcion) {
        case 1:
            // 1 vs 1
            printf("Jugador 1, elige:\n1) Piedra\n2) Papel\n3) Tijera\n");
            printf("Tu: ");
            scanf("%d", &jugador1);
            
            printf("Jugador 2, elige:\n1) Piedra\n2) Papel\n3) Tijera\n");
            printf("Tu: ");
            scanf("%d", &jugador2);
            
            printf("Jugador 1 : %s\n", opciones[jugador1 - 1]);
            printf("Jugador 2 : %s\n", opciones[jugador2 - 1]);

            if (jugador1 == jugador2) {
                printf("¡Empate!\n");
            } else if ((jugador1 == 1 && cpu == 3) || (jugador1 == 2 && cpu == 1) || (jugador1 == 3 && cpu == 2)) {
                puntos1 + 1;
				if(puntos1 >=3){
                	printf("GANAS el jugador 1");
				}
				printf("¡Jugador 1 gana!\n");
            } else {
                puntos2 + 1;
				if(puntos2 >=3){
                	printf("GANAS el jugador 2");
            }
				printf("¡Jugador 2 gana!\n");
                
            }
            break;
        
        case 2:
            // 1 vs BOT
            printf("Jugador, elige:\n1) Piedra\n2) Papel\n3) Tijera\n");
            printf("Tu: ");
            scanf("%d", &jugador1);
            
            cpu = 1 + rand() % 3;
            printf("Bot: %s\n", opciones[cpu - 1]);

            if (jugador1 == cpu) {
                printf("¡Empate!\n");
            } else if ((jugador1 == 1 && cpu == 3) || (jugador1 == 2 && cpu == 1) || (jugador1 == 3 && cpu == 2)) {
                printf("¡Tú ganas!\n");
                puntos1 + 1;
				if(puntos1 >=3){
                	printf("GANAS el jugador 1");
				}
            } else {
                printf("¡BOT Gana!\n");
                puntosb + 1;
            }
            break;

        case 3:
            printf("¡Gracias por jugar!\n");
            break;

        default:
            printf("ERROR.\n");
            break;
    }
}
	while(opcion != 3);
    return 0;
}





