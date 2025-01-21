#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LONGITUD 4

struct producto {
    int id;
    char nombre[50];
    int cantidad;
    float precio;
};

struct producto productos[LONGITUD];

void inicializarProductos() {
    int i;
    for (i = 0; i < LONGITUD; i++) {
        productos[i].id = 0;
        productos[i].cantidad = 0;
        productos[i].precio = 0.0;
        strcpy(productos[i].nombre, "");
    }
}

void mostrarProductos() {
    int i;
    printf("\nLista de productos:\n");
    printf("ID\tNombre\t\tCantidad\tPrecio\n");
    printf("------------------------------------------------\n");
    for (i = 0; i < LONGITUD; i++) {
        if (productos[i].id != 0) {
            printf("%d\t%-10s\t%d\t\t%.2f\n", 
                   productos[i].id, 
                   productos[i].nombre, 
                   productos[i].cantidad,
                   productos[i].precio);
        }
    }
}

int buscarProducto(char nombre[]) {
    int i;
    for (i = 0; i < LONGITUD; i++) {
        if (productos[i].id != 0 && strcmp(productos[i].nombre, nombre) == 0) {
            printf("\nProducto encontrado:\n");
            printf("ID: %d\n", productos[i].id);
            printf("Nombre: %s\n", productos[i].nombre);
            printf("Cantidad: %d\n", productos[i].cantidad);
            printf("Precio: %.2f\n", productos[i].precio);
            return i;
        }
    }
    return -1;
}

float calcularValorTotal() {
    float total = 0;
    int i;
    for (i = 0; i < LONGITUD; i++) {
        if (productos[i].id != 0) {
            total += productos[i].cantidad * productos[i].precio;
        }
    }
    return total;
}

int agregarProducto(int id, char nombre[], int cantidad, float precio) {
    int i;
    int posicion = -1;
    
    for (i = 0; i < LONGITUD; i++) {
        if (productos[i].id == 0) {
            posicion = i;
            break;
        }
    }
    
    if (posicion == -1) {
        return 0;
    }
    
    for (i = 0; i < LONGITUD; i++) {
        if (productos[i].id != 0 && strcmp(productos[i].nombre, nombre) == 0) {
            return -1;
        }
    }
    
    productos[posicion].id = id;
    strcpy(productos[posicion].nombre, nombre);
    productos[posicion].cantidad = cantidad;
    productos[posicion].precio = precio;
    
    return 1;
}

int main() {
    int opcion, id, cantidad;
    float precio;
    char nombre[50];
    int resultado;
    
    inicializarProductos();
    
    do {
        printf("\n=== Sistema de Gestion de Inventario ===\n");
        printf("1. Agregar producto\n");
        printf("2. Mostrar todos los productos\n");
        printf("3. Buscar producto por nombre\n");
        printf("4. Calcular valor total del inventario\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        
        switch(opcion) {
            case 1:
                printf("Ingrese ID del producto: ");
                scanf("%d", &id);
                
                printf("Ingrese nombre del producto: ");
                scanf("%s", nombre);
                
                printf("Ingrese cantidad: ");
                scanf("%d", &cantidad);
                
                printf("Ingrese precio: ");
                scanf("%f", &precio);
                
                resultado = agregarProducto(id, nombre, cantidad, precio);
                if (resultado == 1) {
                    printf("Producto agregado exitosamente\n");
                } else if (resultado == 0) {
                    printf("Error: No hay espacio en el inventario\n");
                } else {
                    printf("Error: El producto ya existe\n");
                }
                break;
                
            case 2:
                mostrarProductos();
                break;
                
            case 3:
                printf("Ingrese nombre del producto a buscar: ");
                scanf("%s", nombre);
                if (buscarProducto(nombre) == -1) {
                    printf("Producto no encontrado\n");
                }
                break;
                
            case 4:
                printf("Valor total del inventario: %.2f\n", calcularValorTotal());
                break;
                
            case 5:
                printf("Gracias por usar el sistema!\n");
                break;
                
            default:
                printf("Opcion no valida\n");
        }
    } while (opcion != 5);
    
    return 0;
}