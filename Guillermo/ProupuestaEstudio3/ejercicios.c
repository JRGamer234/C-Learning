#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
// -Escribe un programa que determine si una palabra empieza y termina por la misma letra.

char palabra[100];

printf("Introduce una palabra: ");
scanf("%s", &palabra);

char ini = tolower(palabra[0]);
char ulti = tolower(palabra[strlen(palabra) - 1]);

if(ini == ulti){
    printf("La palabra %s empieza y termina por la misma letra", palabra);
}else{
    printf("Son diferentes la primera y la ultima letra");
}

//-Escribe un programa que concatene dos palabras si la ultima letra de la primera coincide con la primera letra de la segunda.



//-Escribe un programa que tome una palabra y la imprima sin vocales juntando las letras entre huecos.
//Ej: murcielago -> mrclg




//-Escribe un programa que desplace las letras de una palabra a la derecha de forma circular un numero de veces dado por el usuario:
//Ejemplo: Se introduce la palabra "esfera" y el usuario introduce un 3. La salida es: "eraesf"






return 0;
}