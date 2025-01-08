#include <stdio.h>
#include <math.h>

// Función para sumar elementos de un array
void sumarElementos() {
    const int TAMANO = 10;
    int numeros[TAMANO];
    int suma = 0;

    printf("--- Sumar elementos de un array ---\n");
    for (int i = 0; i < TAMANO; i++) {
        printf("Ingrese el numero %d: ", i + 1);
        scanf("%d", &numeros[i]);
        suma += numeros[i];
    }

    printf("La suma de los numeros es: %d\n\n", suma);
}

// Función para encontrar el número mayor y menor
void encontrarMayorMenor() {
    const int TAMANO = 20;
    int numeros[TAMANO];
    int mayor, menor;

    printf("--- Encontrar numero mayor y menor ---\n");
    for (int i = 0; i < TAMANO; i++) {
        printf("Ingrese el numero %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    mayor = menor = numeros[0];
    for (int i = 1; i < TAMANO; i++) {
        if (numeros[i] > mayor) mayor = numeros[i];
        if (numeros[i] < menor) menor = numeros[i];
    }

    printf("El numero mayor es: %d\n", mayor);
    printf("El numero menor es: %d\n\n", menor);
}

// Función para calcular promedio de calificaciones
void promedioCalificaciones() {
    const int ESTUDIANTES = 30;
    float calificaciones[ESTUDIANTES];
    float suma = 0;
    int sobre_promedio = 0;

    printf("--- Promedio de calificaciones ---\n");
    for (int i = 0; i < ESTUDIANTES; i++) {
        printf("Ingrese la calificacion del estudiante %d: ", i + 1);
        scanf("%f", &calificaciones[i]);
        suma += calificaciones[i];
    }

    float promedio = suma / ESTUDIANTES;

    for (int i = 0; i < ESTUDIANTES; i++) {
        if (calificaciones[i] > promedio) sobre_promedio++;
    }

    printf("Promedio del grupo: %.2f\n", promedio);
    printf("Estudiantes sobre el promedio: %d\n\n", sobre_promedio);
}

// Función para contar vocales
int contarVocales(char* palabra) {
    char vocales[] = "aeiouAEIOU";
    int contador = 0;
    int i = 0;

    while (palabra[i] != '\0') {
        for (int j = 0; vocales[j] != '\0'; j++) {
            if (palabra[i] == vocales[j]) {
                contador++;
                break;
            }
        }
        i++;
    }

    return contador;
}

void contarVocalesPalabra() {
    const int MAX_LONGITUD = 100;
    char palabra[MAX_LONGITUD];

    printf("--- Contar vocales ---\n");
    printf("Ingrese una palabra: ");
    fgets(palabra, MAX_LONGITUD, stdin);

    // Eliminar el salto de línea del final
    for (int i = 0; palabra[i] != '\0'; i++) {
        if (palabra[i] == '\n') {
            palabra[i] = '\0';
            break;
        }
    }

    int num_vocales = contarVocales(palabra);
    printf("Numero de vocales: %d\n\n", num_vocales);
}

// Función para invertir una palabra
void invertirPalabra() {
    const int MAX_LONGITUD = 100;
    char palabra[MAX_LONGITUD];

    printf("--- Invertir una palabra ---\n");
    printf("Ingrese una palabra: ");
    fgets(palabra, MAX_LONGITUD, stdin);

    // Eliminar el salto de línea del final
    int longitud = 0;
    while (palabra[longitud] != '\0') {
        if (palabra[longitud] == '\n') {
            palabra[longitud] = '\0';
            break;
        }
        longitud++;
    }

    // Invertir la palabra
    for (int i = 0; i < longitud / 2; i++) {
        char temp = palabra[i];
        palabra[i] = palabra[longitud - 1 - i];
        palabra[longitud - 1 - i] = temp;
    }

    printf("Palabra invertida: %s\n\n", palabra);
}

// Función para comparar cadenas
int compararCadenas(const char* cadena1, const char* cadena2) {
    int i = 0;
    while (cadena1[i] != '\0' && cadena2[i] != '\0') {
        if (cadena1[i] != cadena2[i]) return 0;
        i++;
    }

    return cadena1[i] == '\0' && cadena2[i] == '\0';
}

void compararDosCadenas() {
    const int MAX_LONGITUD = 100;
    char cadena1[MAX_LONGITUD], cadena2[MAX_LONGITUD];

    printf("--- Comparar dos cadenas ---\n");
    printf("Ingrese la primera cadena: ");
    fgets(cadena1, MAX_LONGITUD, stdin);
    printf("Ingrese la segunda cadena: ");
    fgets(cadena2, MAX_LONGITUD, stdin);

    // Eliminar saltos de línea
    for (int i = 0; cadena1[i] != '\0'; i++) {
        if (cadena1[i] == '\n') cadena1[i] = '\0';
    }
    for (int i = 0; cadena2[i] != '\0'; i++) {
        if (cadena2[i] == '\n') cadena2[i] = '\0';
    }

    if (compararCadenas(cadena1, cadena2)) {
        printf("Las cadenas son iguales\n\n");
    } else {
        printf("Las cadenas son diferentes\n\n");
    }
}

// Función para generar serie de Fibonacci
void serieFibonacci() {
    const int CANTIDAD = 20;
    int fib[CANTIDAD];
    fib[0] = 0;
    fib[1] = 1;

    printf("--- Serie de Fibonacci ---\n");
    for (int i = 2; i < CANTIDAD; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    printf("Serie de Fibonacci:\n");
    for (int i = 0; i < CANTIDAD; i++) {
        printf("%d ", fib[i]);
    }
    printf("\n\n");
}

// Función para verificar si un número es primo
int esPrimo(int numero) {
    if (numero < 2) return 0;
    
    for (int i = 2; i <= sqrt(numero); i++) {
        if (numero % i == 0) return 0;
    }
    return 1;
}

// Función para encontrar números primos
void encontrarNumerosPrimos() {
    int limite;

    printf("--- Encontrar numeros primos ---\n");
    printf("Ingrese un numero limite: ");
    scanf("%d", &limite);
    
    printf("Numeros primos hasta %d:\n", limite);
    for (int num = 2; num <= limite; num++) {
        if (esPrimo(num)) {
            printf("%d ", num);
        }
    }
    printf("\n\n");
}

// Función para calcular factorial
unsigned long long factorial(int n) {
    unsigned long long resultado = 1;
    for (int i = 1; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}

void calcularFactorial() {
    int numero;

    printf("--- Calcular factorial ---\n");
    printf("Ingrese un numero para calcular su factorial: ");
    scanf("%d", &numero);

    printf("El factorial de %d es: %llu\n\n", numero, factorial(numero));
}

// Función para contar números pares en un array
int contarPares(int* array, int tamano) {
    int contador = 0;
    for (int i = 0; i < tamano; i++) {
        if (array[i] % 2 == 0) {
            contador++;
        }
    }
    return contador;
}

void contarNumerosPares() {
    const int TAMANO = 10;
    int numeros[TAMANO] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    printf("--- Contar numeros pares ---\n");
    int num_pares = contarPares(numeros, TAMANO);
    printf("Numeros pares en el array: %d\n\n", num_pares);
}

// Menú principal
int main() {
    int opcion;
    
    do {
        printf("--- MENU PRINCIPAL ---\n");
        printf("1. Sumar elementos de un array\n");
        printf("2. Numero mayor y menor\n");
        printf("3. Promedio de calificaciones\n");
        printf("4. Contar vocales\n");
        printf("5. Invertir una cadena\n");
        printf("6. Comparar cadenas\n");
        printf("7. Serie Fibonacci\n");
        printf("8. Numeros primos\n");
        printf("9. Factorial de un numero\n");
        printf("10. Numeros pares en un array\n");
        printf("0. Salir\n");
        printf("Ingrese su opcion: ");
        scanf("%d", &opcion);

        // Limpiar buffer de entrada
        while (getchar() != '\n');

        switch(opcion) {
            case 1: sumarElementos(); break;
            case 2: encontrarMayorMenor(); break;
            case 3: promedioCalificaciones(); break;
            case 4: contarVocalesPalabra(); break;
            case 5: invertirPalabra(); break;
            case 6: compararDosCadenas(); break;
            case 7: serieFibonacci(); break;
            case 8: encontrarNumerosPrimos(); break;
            case 9: calcularFactorial(); break;
            case 10: contarNumerosPares(); break;
            case 0: printf("Saliendo del programa...\n"); break;
            default: printf("Opcion invalida\n");
        }
    } while (opcion != 0);

    return 0;
}