#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	char palabra[50] = "hola";
	
	strcpy(palabra, "yy");
	
	printf("%s", palabra);
	
	int matriz[3][3] = {
		{0, 1, 2},
		{3, 4, 8},
		{6, 7, 8}
	}
	
	char palabras[3][5] = {
		{'h','o', 'l', 'a'},
		{'p', 'e', 'p', 'e'},
		{'p', 'e', 'p', 'a'}
	}
	
	char palabra2[3][5] = {
		"hola",
		"pepe",
		"pepa"
	}
	
	printf("%s", palabra2[0]);
	
	palabra2[0][0] = 'Y';
	
	printf("\n%c\n", palabra[0][0]);
	
	// sustituir e por Y
	 
	palabra[1][1] = "Y";
	
	if(palabra2[0][0] == palabra2[1][1]){
		printf("Iguales");
	}else{
		printf("No");
	}
	
	printf("\n\n");
	
	for(int i = 0; i < 3; i++){
		printf("\n%s", palabra2[i]);
	}
	
	printf("\n\n");
	
	for(int i = 0; i < 3; i++){
		
	}
	
	 	
	return 0;
}
