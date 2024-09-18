#include<stdio.h>

int main(){
	
	int numero1;
	int numero2;
	
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
	
	printf("Introduce un numero: ");
	scanf("%d", &numero1);
	
	printf("Introduce otro numero: ");
	scanf("%d", &numero2);
	
	printf("La sume de los numeros es: %d", numero1 + numero2);
	
	

}
