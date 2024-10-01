#include<stdio.h>
#include<math.h>

int main(){
	
	/*
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
    */
    
    // Pedir por teclado los 3 lados del triangulo tenemos que calcular el lado que el usuario intruduzca a 0
    
    double a1, b1, c1;
    printf("Introduce a: ");
	scanf("%d", &a1);
	printf("Introduce b: ");
	scanf("%d", &b1);
	printf("Introduce c: ");
	scanf("%d", &c1);
	
	if (a1 == 0){
		a1 = sqrt((c1*c1)-(b1*b1));
	}else if(b1 == 0){
		b1 = sqrt((c1*c1)-(a1*a1));
	}else if(c1 == 0){
		c1 = sqrt((a1*a1)+(b1*b1));
	}
	
	printf("A = %d , B = %d , C = %d ", a1,b1,c1);

	return 0;
	
	
	
	
	
	
}
