#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*OBLIGATORIO PASO POR REFERENCIA

En la empresa donde trabajamos necesitan un software de
gestión de inventario que tenga las siguientes funcionalidades:

- Alta de productos (máximo 100 productos) con los
campos nombre, precio de compra SIN IVA NI RECARGO DE EQUIVALENCIA, tipo de iva
(en España tenemos 3 tipos de iva que son del 21% para productos con azúcar, 10% para alimentos sin azúcar ni cafeína y 4% para categorías especiales), precio de venta
-  Mostrar todos los productos
-  Eliminar productos (si eliminamos un producto
tenemos que eliminar también todas sus ventas)
-  Realizar venta donde pedimos que producto queremos
vender y cuantas unidades se venden de ese producto
-  Mostrar total de ventas (suma total de precio de
venta * unidades de todos los productos vendidos)
-  Mostrar 5 productos más rentable (la
rentabilidad se calcula con: (precio de venta – (precio de compra + IVA + recargo de equivalencia) ) * total ventas)

*recargo de equivalencia que aplica un % extra al precio de compra
dependiendo de su tipo de iva  21%:
recargo del 5,2%, 10%: recargo del 1,4%, 4%: recargo del 0,5%*/

#define MAX_PRODUCTOS 100
#define MAX_VENTAS 100

typedef struct
{
    int id;
    char nombre[50];
    float precio_compra;
    int tipo_iva;
    float precio_venta;
    int total_ventas;
} PRODUCTO;

typedef struct
{
    int id_producto;
    int unidades_vendidas;
} VENTA;

void altaProducto(PRODUCTO productos[], int *contador_productos);
void mostrarProductos(PRODUCTO productos[], int contador_productos);
void eliminarProducto(PRODUCTO productos[], VENTA ventas[], int *contador_productos, int *contador_ventas);
void realizarVenta(PRODUCTO productos[], VENTA ventas[], int *contador_productos, int *contador_ventas);
void mostrarTotalVentas(PRODUCTO productos[], VENTA ventas[], int contador_productos, int contador_ventas);
void mostrarProductosMasRentables(PRODUCTO productos[], VENTA ventas[], int contador_productos, int contador_ventas);

int main()
{
    PRODUCTO productos[MAX_PRODUCTOS];
    VENTA ventas[MAX_VENTAS];
    int contador_productos = 0;
    int contador_ventas = 0;
    int opcion;

    do
    {
        printf("\n1. Alta de producto\n");
        printf("2. Mostrar productos\n");
        printf("3. Eliminar producto\n");
        printf("4. Realizar venta\n");
        printf("5. Mostrar total de ventas\n");
        printf("6. Mostrar 5 productos más rentables\n");
        printf("7. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);
        getchar(); // Limpia el buffer de entrada

        switch (opcion)
        {
        case 1:
            altaProducto(productos, &contador_productos);
            break;
        case 2:
            mostrarProductos(productos, contador_productos);
            break;
        case 3:
            eliminarProducto(productos, ventas, &contador_productos, &contador_ventas);
            break;
        case 4:
            realizarVenta(productos, ventas, &contador_productos, &contador_ventas);
            break;
        case 5:
            mostrarTotalVentas(productos, ventas, contador_productos, contador_ventas);
            break;
        case 6:
            mostrarProductosMasRentables(productos, ventas, contador_productos, contador_ventas);
            break;
        case 7:
            printf("Saliendo...\n");
            break;
        default:
            printf("Opcion no valida\n");
            break;
        }
    } while (opcion != 7);

    return 0;
}

void altaProducto(PRODUCTO productos[], int *contador_productos)
{
    if (*contador_productos >= MAX_PRODUCTOS)
    {
        printf("No se pueden agregar más productos.\n");
        return;
    }

    PRODUCTO nuevo_producto;
    nuevo_producto.id = *contador_productos + 1;

    printf("Nombre del producto: ");
    fgets(nuevo_producto.nombre, 50, stdin);
    nuevo_producto.nombre[strcspn(nuevo_producto.nombre, "\n")] = 0;

    printf("Precio de compra (sin IVA ni recargo): ");
    scanf("%f", &nuevo_producto.precio_compra);

    printf("Tipo de IVA (21%% = 21, 10%% = 10, 4%% = 4): ");
    scanf("%d", &nuevo_producto.tipo_iva);

    printf("Precio de venta: ");
    scanf("%f", &nuevo_producto.precio_venta);

    nuevo_producto.total_ventas = 0;

    productos[*contador_productos] = nuevo_producto;
    (*contador_productos)++;
    printf("Producto agregado correctamente.\n");
}

void mostrarProductos(PRODUCTO productos[], int contador_productos)
{
    if (contador_productos == 0)
    {
        printf("No hay productos registrados.\n");
        return;
    }

    printf("\nLista de productos:\n");
    for (int i = 0; i < contador_productos; i++)
    {
        printf("%d. %s - Compra: %.2f - IVA: %d%% - Venta: %.2f - Vendidos: %d\n",
            productos[i].id, productos[i].nombre, productos[i].precio_compra, productos[i].tipo_iva, productos[i].precio_venta, productos[i].total_ventas);
    }
}

void eliminarProducto(PRODUCTO productos[], VENTA ventas[], int *contador_productos, int *contador_ventas)
{
    int id;
    printf("Ingrese el ID del producto a eliminar: ");
    scanf("%d", &id);
    id--;

    if (id < 0 || id >= *contador_productos)
    {
        printf("Producto no encontrado.\n");
        return;
    }

    for (int i = id; i < *contador_productos - 1; i++)
    {
        productos[i] = productos[i + 1];
    }
    (*contador_productos)--;
    printf("Producto eliminado.\n");
}

void realizarVenta(PRODUCTO productos[], VENTA ventas[], int *contador_productos, int *contador_ventas)
{
    int id, unidades;
    printf("Ingrese el ID del producto a vender: ");
    scanf("%d", &id);
    id--;

    if (id < 0 || id >= *contador_productos)
    {
        printf("Producto no encontrado.\n");
        return;
    }

    printf("Ingrese la cantidad vendida: ");
    scanf("%d", &unidades);

    productos[id].total_ventas += unidades;

    ventas[*contador_ventas].id_producto = id;
    ventas[*contador_ventas].unidades_vendidas = unidades;
    (*contador_ventas)++;

    printf("Venta registrada.\n");
}

void mostrarTotalVentas(PRODUCTO productos[], VENTA ventas[], int contador_productos, int contador_ventas)
{
    float total = 0;
    for (int i = 0; i < contador_productos; i++)
    {
        total += productos[i].precio_venta * productos[i].total_ventas;
    }
    printf("Total de ventas: %.2f\n", total);
}

void mostrarProductosMasRentables(PRODUCTO productos[], VENTA ventas[], int contador_productos, int contador_ventas)
{

    float total = 0;
    float max = 0;
    int id_producto = 0;
    for (int i = 0; i < contador_productos; i++)
    {
        for (int j = 0; j < contador_ventas; j++)
        {
            if (ventas[j].id_producto == i)
            {
                total += productos[i].precio_venta * ventas[j].unidades_vendidas;
            }
        }
    }
    for (int i = 0; i < contador_productos; i++)
    {
        for (int j = 0; j < contador_ventas; j++)
        {
            if (ventas[j].id_producto == i)
            {
                if (total > max)
                {
                    max = total;
                    id_producto = i;
                }
            }
        }
        printf("Producto mas rentable: %d\n", id_producto);
    }
}
