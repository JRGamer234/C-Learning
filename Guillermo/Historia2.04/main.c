#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    
    int opcion, coche, modalidad, final, vidas = 3;

    while(vidas > 0) {
        printf("Juego de carreras.\nSelecciona un coche\n");
        printf("1) BMW \n2) TOYOTA \n3) NISSAN\n");
        scanf("%i", &opcion);
        
        switch(opcion) {
            case 1:
                printf("�Qu� modelo de BMW quieres?\n");
                printf("1) M3 e46 \n2) M3 e92\n");
                scanf("%i", &coche);
                break;
            case 2:
                printf("�Qu� modelo de TOYOTA quieres?\n");
                printf("1) SUPRA \n2) AE86\n");
                scanf("%i", &coche);
                break;
            case 3:
                printf("�Qu� modelo de NISSAN quieres?\n");
                printf("1) R34 \n2) R33\n");
                scanf("%i", &coche);
                break;
            default:
                printf("No has seleccionado un coche valido. Pierdes una vida.\n");
                vidas--;
                continue; // Vuelve a empezar el ciclo sin continuar el resto del programa
        }

        printf("�Qu� modalidad quieres correr con tu coche seleccionado?\n");
        printf("1) DRIFT \n2) GRIP\n");
        scanf("%i", &modalidad);
        
        switch(modalidad) {
            case 1: 
                printf("Has escogido DRIFT.\n");
                printf("�Listo para correr contra alguien? \n1) SI \n2) No\n");
                scanf("%i", &final);
                break;
            case 2:
                printf("Has escogido GRIP.\n");
                printf("�Listo para correr contra alguien? \n1) SI \n2) NO\n");
                scanf("%i", &final);
                break;
            default:
                printf("No has escogido una modalidad valida. Pierdes una vida.\n");
                vidas--;
                continue; // Vuelve a empezar el ciclo sin continuar el resto del programa
        }

        // Aqu� es donde cambian las opciones de la historia
        switch(final) {
            case 1:
                printf("Has comenzado la carrera...\n");
                printf("Vas muy r�pido, pero el oponente te est� alcanzando. �Qu� quieres hacer?\n");
                printf("1) Aumentar la velocidad \n2) Mantener la calma y seguir igual\n");
                int decisionCarrera;
                scanf("%i", &decisionCarrera);
                
                if (decisionCarrera == 1) {
                    printf("Aumentas la velocidad... pero te arriesgas demasiado y pierdes el control. \nHas chocado y perdido la carrera. \nPierdes una vida.\n");
                    vidas--;
                } else if (decisionCarrera == 2) {
                    printf("Mantienes la calma y logras controlar la situaci�n. \n�Has ganado la carrera!\n");
                } else {
                    printf("No has tomado una decisi�n v�lida y pierdes el control del coche. \nPierdes una vida.\n");
                    vidas--;
                }
                break;
            
            case 2:
                printf("Por no querer correr, el oponente te desaf�a a una apuesta m�s arriesgada.\n");
                printf("�Aceptas la apuesta? \n1) S� \n2) No\n");
                int decisionApuesta;
                scanf("%i", &decisionApuesta);
                
                if (decisionApuesta == 1) {
                    printf("Aceptas la apuesta y el oponente elige una carrera cuesta abajo en una peligrosa monta�a.\n");
                    printf("Empiezas la carrera, pero la dificultad es extrema. �Qu� haces?\n");
                    printf("1) Freno un poco para mantener el control \n2) Mantengo la velocidad para ganar\n");
                    int decisionMontana;
                    scanf("%i", &decisionMontana);
                    
                    if (decisionMontana == 1) {
                        printf("Frenas a tiempo y logras mantener el control en las curvas dif�ciles. �Ganas la carrera!\n");
                    } else if (decisionMontana == 2) {
                        printf("Mantienes la velocidad, pero una curva te traiciona y caes por el borde. \nPierdes la carrera y una vida.\n");
                        vidas--;
                    } else {
                        printf("No has tomado una decisi�n v�lida, pierdes el control y caes. \nPierdes una vida.\n");
                        vidas--;
                    }
                } else {
                    printf("Decides no aceptar la apuesta y te retiras. \nPierdes autom�ticamente una vida por no aceptar el desaf�o.\n");
                    vidas--;
                }
                break;
            
            default:
                printf("No has escogido una opci�n v�lida. \nPierdes una vida.\n");
                vidas--;
                break;
        }

        if (vidas > 0) {
            printf("Te quedan %d vidas.\n", vidas);
        } else {
            printf("Te has quedado sin vidas. \nHAS PERDIDO.\n");
        }
    }
    
    return 0;
}

