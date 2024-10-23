#include <iostream>
#include <stdio.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	/* H o l a \0*/
	char palabra[5] = "Hola";
	char letra = 'c';
	int i = 0;
	
	printf("%s", palabra);
	scanf("%s", &palabra);
	
	printf("\n");
	
	while(palabra[i] != '\0'){
		printf("%c", palabra[i]);
		i++;
	}
	
	printf("\n");
	
	for(i = 0; i < strlen(palabra); i++){
		printf("%c", palabra[i]);
	}
	return 0;
}
