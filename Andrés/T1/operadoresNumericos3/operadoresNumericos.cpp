#include<stdio.h>

int main(){

/*
char letra = 'a';
char letra1 = '3';

printf("%f \n", letra);


int numero1;
printf("Introduce un numero: ");
scanf("%d", &numero1);

// if(numero == 3) son iguales if(numero1 == 51)
//if('3' == 51)
 

// Diferente
if(numero1 == 3){
	printf("En la variable hay un 3");
}else if(numero1 == 2){
	printf("En la variable hay un 2");
}else{
	printf("En la variable no hay ni un 3 ni un 2");
}
*/


/* Pedir por teclado una letra, tenemos que imprimir en pantalla la letra convertida
(Si es mayus a minus) && (si es minus a mayus)*/

char letra;
printf("Introduce una letra: ");
scanf("%c", &letra);

if(letra >= 'A' && letra <= 'Z'){
	printf("Conversion a minuscula: %c", letra + 32);
}else if(letra >= 'a' && letra <= 'z'){
	printf("Conversion a mayuscula: %c", letra - 32);
}else{
	printf("ERROR");
}












}
