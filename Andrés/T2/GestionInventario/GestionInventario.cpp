#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PRODUCTOS 100
#define MAX_NOMBRE 50

// Estructura para representar un producto
typedef struct {
    char nombre[MAX_NOMBRE];
    float precioCompra;
    float precioVenta;
    int tipoIVA; // 21, 10 o 4
    int stockVendido;
} Producto;

// Estructura para gestionar el inventario
typedef struct {
    Producto productos[MAX_PRODUCTOS];
    int cantidadProductos;
} GestorInventario;

// Inicializar inventario
void inicializarInventario(GestorInventario* inventario) {
    inventario->cantidadProductos = 0;
}

// Función para calcular el recargo de equivalencia
float calcularRecargoEquivalencia(int tipoIVA) {
    switch(tipoIVA) {
        case 21: return 0.052; // 5.2%
        case 10: return 0.014; // 1.4%
        case 4:  return 0.005; // 0.5%
        default: return 0;
    }
}

// Calcular rentabilidad de un producto
float calcularRentabilidad(Producto* producto) {
    float recargoEq = calcularRecargoEquivalencia(producto->tipoIVA);
    float precioCompraConRecargo = producto->precioCompra * (1 + recargoEq);
    return (producto->precioVenta - precioCompraConRecargo) * producto->stockVendido;
}

// Función para dar de alta un producto
int altaProducto(GestorInventario* inventario, const char* nombre, float precioCompra, 
                 float precioVenta, int tipoIVA) {
    // Validar límite de productos
    if (inventario->cantidadProductos >= MAX_PRODUCTOS) {
        printf("Límite de productos alcanzado (máximo 100).\n");
        return 0;
    }

    // Validar tipo de IVA
    if (tipoIVA != 21 && tipoIVA != 10 && tipoIVA != 4) {
        printf("Tipo de IVA no válido. Debe ser 21, 10 o 4.\n");
        return 0;
    }

    // Crear nuevo producto
    Producto nuevoProducto;
    strncpy(nuevoProducto.nombre, nombre, MAX_NOMBRE - 1);
    nuevoProducto.nombre[MAX_NOMBRE - 1] = '\0';
    nuevoProducto.precioCompra = precioCompra;
    nuevoProducto.precioVenta = precioVenta;
    nuevoProducto.tipoIVA = tipoIVA;
    nuevoProducto.stockVendido = 0;

    // Añadir producto al inventario
    inventario->productos[inventario->cantidadProductos++] = nuevoProducto;
    printf("Producto dado de alta correctamente.\n");
    return 1;
}

// Mostrar todos los productos
void mostrarProductos(GestorInventario* inventario) {
    printf("Lista de Productos:\n");
    printf("%-20s %-15s %-15s %-10s\n", "Nombre", "Precio Compra", "Precio Venta", "Tipo IVA");
    
    for (int i = 0; i < inventario->cantidadProductos; i++) {
        Producto* p = &inventario->productos[i];
        printf("%-20s %-15.2f %-15.2f %-10d\n", 
            p->nombre, p->precioCompra, p->precioVenta, p->tipoIVA);
    }
}

// Eliminar un producto
int eliminarProducto(GestorInventario* inventario, const char* nombre) {
    for (int i = 0; i < inventario->cantidadProductos; i++) {
        if (strcmp(inventario->productos[i].nombre, nombre) == 0) {
            // Mover los elementos siguientes para llenar el hueco
            for (int j = i; j < inventario->cantidadProductos - 1; j++) {
                inventario->productos[j] = inventario->productos[j + 1];
            }
            inventario->cantidadProductos--;
            printf("Producto eliminado correctamente.\n");
            return 1;
        }
    }
    
    printf("Producto no encontrado.\n");
    return 0;
}

// Realizar venta
int realizarVenta(GestorInventario* inventario, const char* nombre, int cantidad) {
    for (int i = 0; i < inventario->cantidadProductos; i++) {
        if (strcmp(inventario->productos[i].nombre, nombre) == 0) {
            inventario->productos[i].stockVendido += cantidad;
            printf("Venta realizada: %d unidades de %s\n", cantidad, nombre);
            return 1;
        }
    }
    
    printf("Producto no encontrado.\n");
    return 0;
}

// Mostrar total de ventas
float mostrarTotalVentas(GestorInventario* inventario) {
    float totalVentas = 0;
    for (int i = 0; i < inventario->cantidadProductos; i++) {
        totalVentas += inventario->productos[i].precioVenta * 
                       inventario->productos[i].stockVendido;
    }
    printf("Total de ventas: %.2f €\n", totalVentas);
    return totalVentas;
}

// Comparación para qsort - ordenar productos por rentabilidad
int compararRentabilidad(const void* a, const void* b) {
    Producto* productoA = (Producto*)a;
    Producto* productoB = (Producto*)b;
    
    float rentA = calcularRentabilidad(productoA);
    float rentB = calcularRentabilidad(productoB);
    
    if (rentA > rentB) return -1;
    if (rentA < rentB) return 1;
    return 0;
}

// Mostrar 5 productos más rentables
void mostrarProductosMasRentables(GestorInventario* inventario) {
    if (inventario->cantidadProductos == 0) {
        printf("No hay productos en el inventario.\n");
        return;
    }

    // Crear copia de productos para ordenar
    Producto productosOrdenados[MAX_PRODUCTOS];
    memcpy(productosOrdenados, inventario->productos, 
           sizeof(Producto) * inventario->cantidadProductos);

    // Ordenar por rentabilidad
    qsort(productosOrdenados, inventario->cantidadProductos, 
          sizeof(Producto), compararRentabilidad);

    printf("Top 5 Productos más Rentables:\n");
    printf("%-20s %-15s\n", "Nombre", "Rentabilidad");

    int limite = (inventario->cantidadProductos < 5) ? 
                 inventario->cantidadProductos : 5;
    
    for (int i = 0; i < limite; i++) {
        printf("%-20s %-15.2f €\n", 
            productosOrdenados[i].nombre, 
            calcularRentabilidad(&productosOrdenados[i]));
    }
}

int main() {
    GestorInventario inventario;
    inicializarInventario(&inventario);
    
    int opcion;
    char nombre[MAX_NOMBRE];
    float precioCompra, precioVenta;
    int tipoIVA, cantidad;

    do {
        printf("\n--- Sistema de Gestión de Inventario ---\n");
        printf("1. Alta de Producto\n");
        printf("2. Mostrar Productos\n");
        printf("3. Eliminar Producto\n");
        printf("4. Realizar Venta\n");
        printf("5. Mostrar Total de Ventas\n");
        printf("6. Mostrar Productos más Rentables\n");
        printf("0. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                printf("Nombre del producto: ");
                scanf(" %[^\n]", nombre);
                printf("Precio de compra: ");
                scanf("%f", &precioCompra);
                printf("Precio de venta: ");
                scanf("%f", &precioVenta);
                printf("Tipo de IVA (21, 10 o 4): ");
                scanf("%d", &tipoIVA);
                altaProducto(&inventario, nombre, precioCompra, precioVenta, tipoIVA);
                break;
            case 2:
                mostrarProductos(&inventario);
                break;
            case 3:
                printf("Nombre del producto a eliminar: ");
                scanf(" %[^\n]", nombre);
                eliminarProducto(&inventario, nombre);
                break;
            case 4:
                printf("Nombre del producto: ");
                scanf(" %[^\n]", nombre);
                printf("Cantidad vendida: ");
                scanf("%d", &cantidad);
                realizarVenta(&inventario, nombre, cantidad);
                break;
            case 5:
                mostrarTotalVentas(&inventario);
                break;
            case 6:
                mostrarProductosMasRentables(&inventario);
                break;
            case 0:
                printf("Saliendo del sistema...\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }
    } while (opcion != 0);

    return 0;
}