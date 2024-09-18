#include<stdio.h>

int main(){
	
	int numero1;
	int numero2;
	/*
	// bool verdadero = true
	bool verdadero = 1;
	
	// bool falso = false
	bool falso = 0;
	
	char letra1 = 'A';
	char letra2 = '4';
	char letra3 = 'a';
	
	/*Operadores
		== igual
		!= diferente
		< menor que
		> mayor que
		<= menor o igual
		>= mayor o igual
		
		&& y
		|| o
	*/
	/*
	if(numero1 == 4 || numero1 == 0){
		printf("En la variable numero hay un 4");
	}else{
		printf("En la variable numero hay un 4");
	} */
	/*
	printf("Introduce un numero: ");
	scanf("%d", &numero1);
	
	printf("Introduce otro numero: ");
	scanf("%d", &numero2);
	
	printf("La sume de los numeros es: %d", numero1 + numero2);
	*/
	

  	/*
		Programa que pida 3 numeros y los sume, al hacer la suma tiene que mostrar un mensaje diciendo si es (mayor o igual) a 100 el resultado de la suma 
	*/
/*	
	int num1;
	int num2;
	int num3;
	int resultado;
	
	printf("Introduce un numero: ");
	scanf("%d", &num1);
	printf("Introduce otro numero: ");
	scanf("%d", &num2);
	printf("Introduce el último numero: ");
	scanf("%d", &num3);
	
	resultado = num1 + num2 + num3;
	
	if(resultado ==100){
		printf("El resultado es igual a 100\n");
	}else if(resultado > 100){
		printf("El resultado es mayor a 100\n");
	}else{
		printf("El resultado es menor a 100\n");
	}
	
	printf("El resultado es: %d", resultado);
}
*/

/*
	Programa que pida un numero y si es par lo eleve al 3 y si no es par lo eleve a la 2, luego imprimimos en pantalla el resultado
*/

int num1;
printf("Introduce un numero: ");
scanf("%d", &num1);

if(num1 % 2 == 0){
	printf("Es par, el resultado al ser par elevado a 3 es: %d", num1 * num1 * num1);
}else{
	printf("Es impar, el resultado al ser impar elevado a 2 es: %d", num1 * num1);
}








}



