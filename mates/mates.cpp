#include<stdio.h>
#include<math.h>

int main(){
	
	int a, b, c;
	double resultadopos, resultadoneg;
	
	printf("Calculadora de ecuaciones de segundo grado ( ax^2 + bx +2 = y)\n");
	
	printf("Introduce a: ");
	scanf("%i", &a);
	printf("Introduce b: ");
	scanf("%i", &b);
	printf("Introduce c: ");
	scanf("%i", &c);
	
	printf("%dx^2 %dx %d = y\n", a, b, c);
	
	double imposible = b * b - 4 * a * c;
    if (imposible < 0) {
        printf("No existen soluciones reales \n");
    } else {
        resultadopos = (-b + sqrt(imposible)) / (2 * a);
        resultadoneg = (-b - sqrt(imposible)) / (2 * a);
	
        printf("X+ = %f | X- = %f\n", resultadopos, resultadoneg);
    }

	return 0;
	
	
	
	
	
	
}
