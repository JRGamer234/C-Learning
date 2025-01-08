#include <stdio.h>
#include <string.h>
#include <math.h>

// Gestión de Inventario
void gestionInventario() {
    const int MAX_PRODUCTOS = 10;
    char nombres[MAX_PRODUCTOS][50];
    int cantidades[MAX_PRODUCTOS];
    float precios[MAX_PRODUCTOS];
    int numProductos = 0;

    int opcion;
    do {
        printf("\n--- GESTION DE INVENTARIO ---\n");
        printf("1. Agregar producto\n");
        printf("2. Mostrar todos los productos\n");
        printf("3. Buscar producto\n");
        printf("4. Calcular valor total del inventario\n");
        printf("0. Salir\n");
        printf("Ingrese su opcion: ");
        scanf("%d", &opcion);
        getchar(); // Limpiar buffer

        switch(opcion) {
            case 1: {
                if (numProductos < MAX_PRODUCTOS) {
                    printf("Nombre del producto: ");
                    fgets(nombres[numProductos], 50, stdin);
                    nombres[numProductos][strcspn(nombres[numProductos], "\n")] = 0;

                    printf("Cantidad: ");
                    scanf("%d", &cantidades[numProductos]);

                    printf("Precio: ");
                    scanf("%f", &precios[numProductos]);

                    numProductos++;
                    printf("Producto agregado exitosamente.\n");
                } else {
                    printf("Inventario lleno. No se pueden agregar más productos.\n");
                }
                break;
            }
            case 2: {
                printf("\n--- LISTA DE PRODUCTOS ---\n");
                for (int i = 0; i < numProductos; i++) {
                    printf("Producto: %s\n", nombres[i]);
                    printf("Cantidad: %d\n", cantidades[i]);
                    printf("Precio: %.2f\n\n", precios[i]);
                }
                break;
            }
            case 3: {
                char busqueda[50];
                printf("Ingrese nombre del producto a buscar: ");
                fgets(busqueda, 50, stdin);
                busqueda[strcspn(busqueda, "\n")] = 0;

                int encontrado = 0;
                for (int i = 0; i < numProductos; i++) {
                    if (strcmp(nombres[i], busqueda) == 0) {
                        printf("Producto encontrado:\n");
                        printf("Nombre: %s\n", nombres[i]);
                        printf("Cantidad: %d\n", cantidades[i]);
                        printf("Precio: %.2f\n", precios[i]);
                        encontrado = 1;
                        break;
                    }
                }
                if (!encontrado) {
                    printf("Producto no encontrado.\n");
                }
                break;
            }
            case 4: {
                float valorTotal = 0;
                for (int i = 0; i < numProductos; i++) {
                    valorTotal += cantidades[i] * precios[i];
                }
                printf("Valor total del inventario: %.2f\n", valorTotal);
                break;
            }
        }
    } while (opcion != 0);
}

// Análisis de Texto
int esVocal(char letra) {
    char vocales[] = "aeiouAEIOU";
    for (int i = 0; vocales[i] != '\0'; i++) {
        if (letra == vocales[i]) return 1;
    }
    return 0;
}

int contarPalabras(char* texto) {
    int palabras = 0;
    int enPalabra = 0;

    for (int i = 0; texto[i] != '\0'; i++) {
        if (texto[i] == ' ' || texto[i] == '\n') {
            enPalabra = 0;
        } else if (!enPalabra) {
            palabras++;
            enPalabra = 1;
        }
    }

    return palabras;
}

void contarVocalesConsonantes(char* texto, int* vocales, int* consonantes) {
    *vocales = 0;
    *consonantes = 0;

    for (int i = 0; texto[i] != '\0'; i++) {
        if ((texto[i] >= 'a' && texto[i] <= 'z') || 
            (texto[i] >= 'A' && texto[i] <= 'Z')) {
            if (esVocal(texto[i])) {
                (*vocales)++;
            } else {
                (*consonantes)++;
            }
        }
    }
}

float promedioLongitudPalabras(char* texto) {
    int longitud = 0;
    int palabras = 0;
    int caracteresActuales = 0;

    for (int i = 0; texto[i] != '\0'; i++) {
        if (texto[i] == ' ' || texto[i] == '\n') {
            if (caracteresActuales > 0) {
                palabras++;
                longitud += caracteresActuales;
                caracteresActuales = 0;
            }
        } else {
            caracteresActuales++;
        }
    }

    // Palabra final
    if (caracteresActuales > 0) {
        palabras++;
        longitud += caracteresActuales;
    }

    return palabras > 0 ? (float)longitud / palabras : 0;
}

void analizarTexto() {
    const int MAX_LONGITUD = 1000;
    char texto[MAX_LONGITUD];

    printf("Ingrese un texto: ");
    fgets(texto, MAX_LONGITUD, stdin);

    int palabras = contarPalabras(texto);
    
    int vocales, consonantes;
    contarVocalesConsonantes(texto, &vocales, &consonantes);
    
    float promedio = promedioLongitudPalabras(texto);

    printf("\n--- ANALISIS DE TEXTO ---\n");
    printf("Numero de palabras: %d\n", palabras);
    printf("Numero de vocales: %d\n", vocales);
    printf("Numero de consonantes: %d\n", consonantes);
    printf("Longitud promedio de palabras: %.2f\n", promedio);
}

// Encriptación de Matriz
void leerMatriz(char matriz[3][3]) {
    printf("Ingrese los caracteres de la matriz 3x3:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Ingrese el caracter para la posicion [%d][%d]: ", i, j);
            scanf(" %c", &matriz[i][j]);
        }
    }
}

void encriptarMatriz(char matriz[3][3], char matrizEncriptada[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrizEncriptada[i][j] = matriz[i][j] + 5;
        }
    }
}

void mostrarMatriz(char matriz[3][3], const char* titulo) {
    printf("%s\n", titulo);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void encriptacion() {
    char matriz[3][3];
    char matrizEncriptada[3][3];

    leerMatriz(matriz);
    mostrarMatriz(matriz, "Matriz Original:");
    
    encriptarMatriz(matriz, matrizEncriptada);
    mostrarMatriz(matrizEncriptada, "Matriz Encriptada:");
}

// Menú Principal
int main() {
    int opcion;
    
    do {
        printf("\n--- MENU PRINCIPAL ---\n");
        printf("1. Gestion de Inventario\n");
        printf("2. Analisis de Texto\n");
        printf("3. Encriptacion de Matriz\n");
        printf("0. Salir\n");
        printf("Ingrese su opcion: ");
        scanf("%d", &opcion);
        getchar(); // Limpiar buffer de entrada

        switch(opcion) {
            case 1: gestionInventario(); break;
            case 2: analizarTexto(); break;
            case 3: encriptacion(); break;
            case 0: printf("Saliendo del programa...\n"); break;
            default: printf("Opcion invalida\n");
        }
    } while (opcion != 0);

    return 0;
}