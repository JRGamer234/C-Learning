#include <stdio.h>
#include <stdlib.h>

int main(){

// Programa que solicite dos arrays de 10 posiciones numericas
// y sea capaz de almacenar en un tercer array la suma de sus celdas
// EJ:            9573162310
//                 0413734235
//                 9986896545
    int i;
    int numeros1[10], numeros2[10], suma[10];

    printf("Cadena1: \n");
    for (i = 0; i < 10; i++) {
        printf("Introduce número: \n");
        scanf("%d", &numeros1[i]);
    }
    printf("Cadena2: \n");
    for (i = 0; i < 10; i++) {
        printf("Introduce número: \n");
        scanf("%d", &numeros2[i]);
    }
    // muestra los numeros
    printf("Números introducidos cadena1:\n");
    for (i = 0; i < 10; i++) {
        printf("%d -", numeros1[i]);
    }
    printf("\n");
    printf("Números introducidos cadena2:\n");
    for (i = 0; i < 10; i++) {
        printf("%d -", numeros1[i]);
    }
    printf("\n");
    printf("Suma:\n");
    for (i = 0; i < 10; i++) {
        suma[i] = numeros1[i] + numeros2[i];
        printf("%d -", suma[i]);
    }
    printf("\n");

// Programa que sea capaz de detectar la secuencia 1 2 3
// en un array numerico de 10 posiciones
// Ej: 9595123234 --->Por pantalla se devuelve: SI, ESTA LA SECUENCIA
// Ej: 9595023234 --->Por pantalla se devuelve: NO, ESTA LA SECUENCIA
// Hacer un programa parecido al anterior, donde se detecte
// la secuencia 123 pero esta vez en un numero entero
// Ej: 91235 --->Por pantalla se devuelve: SI, ESTA LA SECUENCIA
// Ej: 21379 --->Por pantalla se devuelve: NO, ESTA LA SECUENCIA

bool detectarSecuenciaEnArray(int arr[], int tam) {
    for (int i = 0; i < tam - 2; i++) {
        if (arr[i] == 1 && arr[i + 1] == 2 && arr[i + 2] == 3) {
            return true;
        }
    }
    return false;
}

bool detectarSecuenciaEnNumero(int numero) {
    string strNumero = to_string(numero);
    return strNumero.find("123") != string::npos;
}

int main() {
    // Parte 1: Detección en array
    int arr[10] = {9, 5, 9, 5, 1, 2, 3, 2, 3, 4};
    cout << "Chequeando array: ";
    if (detectarSecuenciaEnArray(arr, 10)) {
        cout << "SI, ESTA LA SECUENCIA" << endl;
    } else {
        cout << "NO, ESTA LA SECUENCIA" << endl;
    }

    // Parte 2: Detección en número entero
    int numero = 91235;
    cout << "Chequeando numero: ";
    if (detectarSecuenciaEnNumero(numero)) {
        cout << "SI, ESTA LA SECUENCIA" << endl;
    } else {
        cout << "NO, ESTA LA SECUENCIA" << endl;
    }


return 0;
}
}