#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	/*
		Tenemos que calcular el precio final de un producto, pedimos al usuario el ID del producto y su precio original
		y tenemos que calcular sus correspondientes descuentos segun las siguientes reglas:
		
		- Si el ID del producto es par tiene 5% de descuento
		- Si el precio del producto es multiplo de 7 tiene 5%
		- Si el ID es multiplo de 10 tiene 10%
		- Si el precio es multiplo de 3 tiene 10%
		- Si el ID es multiplo de 3 tiene 5%
	
		El ID tiene que ser un numero de 1 a 100, si no se cumple la condicion tenemos que volver a pedir el id hasta que el usuario introduzca un ID váldio
		
		TODOS LOS DESCUENTOS SON ACUMULABLES Y SE CALCULAN SOBRE EL PRECIO ORIGINAL
	*/
	
	int id;
    int precio = 0;
	double 	descuento = 0, pfinal;
    
   
    
    do {
        printf("Introduzca un ID (entre 1 y 100): ");
        scanf("%d", &id);
        if (id < 1 || id > 100) {
            printf("ERROR. \nVuelva a intentarlo\n");
        }
    } while (id < 1 || id > 100);
    
	printf("Ingrese el precio original del producto: ");
    scanf("%d", &precio);
	
	if ((id % 2) == 0) {
        descuento += 0.05;
    }
    if ((precio % 7) == 0) {
        descuento += 0.05;
    }
    if ((id % 10) == 0) {
        descuento += 0.10;
    }
    if ((precio % 3) == 0) {
        descuento += 0.10;
    }
    if ((id % 3) == 0) {
        descuento += 0.05;
    }
    
    printf("%.2f\n", descuento);
	
	pfinal = precio * (1 - descuento);
	
	printf("ID del producto: %i , Precio del producto: %i\n", id, precio);
	printf("El precio final es: %.2f", pfinal);
	
	
	
	return 0;
}
