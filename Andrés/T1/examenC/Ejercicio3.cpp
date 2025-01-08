#include <stdio.h>

int main(){

    float cuenta, propina, total, prop;
    

    printf("Introduce el total de la cuenta del restaurante: ");
    scanf("%f", &cuenta);

    printf("Cuanto porcentaje de propina desea dejar? ");
    scanf("%f",&prop);

    propina = (cuenta*prop)/100;
    total = cuenta + propina;

    printf("Total sin propina: %f", cuenta);
    printf("Propina calculada: %f", propina);
    printf("Total a pagar: %f", total);

    return 0;
}
