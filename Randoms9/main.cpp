#include<stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	/*
	Generar 20 numeros impares de 1 a 100 y mostrarlos por
	pantalla ademas indicar cual es el numero mas grande y el mas pequeño
	*/
int num[20];
int max, min;
srand(time(NULL));

for(int i = 0; i < 20; i ++){
num[i] = (rand() % 100) + 1;
printf("%d\n", num[i]);
}

max = min = num[0];

for(int i = 0; i < 20; i ++){
if(num[i] > max){
max = num[i];
}else if(num[i] < min){
min = num[i];
}
}
printf("Max = %d \n", max);
printf("Min = %d\n", min);
}
