#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	//Modifica el programa de la historia interactiva de manera que cada vez que el personaje enuentre un final “malo” pierda una vida. Si se queda a 0 vidas, decreta final de programa lamentando su final.

	int opcion, coche, modalidad, final;
    
    printf("Juego de carreras.\nSelecciona un coche\n");
    printf("1) BMW \n2) TOYOTA \n3) NISSAN\n");
    scanf("%i", &opcion);
    
    switch(opcion) {
        case 1:
            printf("¿Qué modelo de BMW quieres?\n");
            printf("1) M3 e46 \n2) M3 e92\n");
            scanf("%i", &coche);
            break;
        case 2:
            printf("¿Qué modelo de TOYOTA quieres?\n");
            printf("1) SUPRA \n2) AE86\n");
            scanf("%i", &coche);
            break;
        case 3:
            printf("¿Qué modelo de NISSAN quieres?\n");
            printf("1) R34 \n2) R33\n");
            scanf("%i", &coche);
            break;
        default:
            printf("No has seleccionado un coche valido.\n");
            return 1;
    }
    
    printf("¿Qué modalidad quieres correr con tu coche seleccionado?\n");
    printf("1) DRIFT \n2) GRIP\n");
    scanf("%i", &modalidad);
    
    switch(modalidad) {
        case 1: 
            printf("Has escogido DRIFT.\n");
            printf("¿Listo para correr contra alguien? \n1) Sí \n2) No\n");
            scanf("%i", &final);
            break;
        case 2:
            printf("Has escogido GRIP.\n");
            printf("¿Listo para correr contra alguien? \n1) SI \n2) NO\n");
            scanf("%i", &final);
            break;
        default:
            printf("No has escogido una modalidad valida.\n");
            return 1; // Salir del programa si no selecciona una modalidad válida
    }
    
    switch(final) {
        case 1:
            printf("Has perdido.\n");
            break;
        case 2:
            printf("Por no querer correr, pierdes automáticamente.\n");
            break;
        default:
            printf("No has escogido una opción valida.\n");
            break;
    }
		
	return 0;
}
