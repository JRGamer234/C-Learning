#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	/*	Pedir por teclado un numero y calcular su factorial
	
	Ejemplo:
	Factorial de 5 = 5*4*3*2*1 = 120;
	
	*/
	int num;
	long long factorial = 1;

    printf("Ingrese un número: ");
    scanf("%d", &num);
    
    if (num < 0) {
        printf("Es menor a 0, no se puede\n");
    } else if (num == 0) {
        printf("Factorial de 0 = 1\n");
    } else {
        printf("Factorial de %d = ", num);

        for (int i = num; i > 0; i--) {
            factorial *= i;
            if (i == 1) {
                printf("%d = %lld", i, factorial);
            } else {
                printf("%d*", i);
            }
        }

    return 0;
}
}
