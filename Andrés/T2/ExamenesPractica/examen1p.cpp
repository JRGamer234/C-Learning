//**Examen de Programación en C++**

//**Nombre:** ___Jorge___  **Fecha:** ___29/03/2025_____

//**Instrucciones:** Resuelve los siguientes ejercicios en C++. Escribe el código correspondiente y explica brevemente su funcionamiento.

//---

// ### **Ejercicios:**
#include <stdio.h>
#include <libreria.h>

// 1. **Uso de strlen:**
//    - Escribe un programa que pida al usuario una cadena y muestre su longitud usando `strlen`.
void ejer1()
{
    char cadena[100];
    printf("Ingrese una cadena: ");
    scanf("%s", cadena);
    int longitud = strlen(cadena);
    printf("La longitud de la cadena es: %d\n", longitud);
}

// 2. **Uso de strcpy:**
//    - Crea un programa que copie el contenido de una cadena en otra utilizando `strcpy` y muestre ambas cadenas.
void ejer2()
{
    char cadena1[100], cadena2[100];
    printf("Introduce cadena1: ");
    scanf("%s", cadena1);
    strcpy(cadena2, cadena1);
    printf("Copia de cadena1 a cadena2 es: %s", cadena2);
}

// 3. **Uso de strcmp:**
//    - Implementa un programa que compare dos cadenas ingresadas por el usuario usando `strcmp` e indique si son iguales o diferentes.
void ejer3()
{
    char cadena1ejer3[100], cadena2ejer3[100];
    printf("Ingrese cadena1: ");
    scanf("%s", cadena1ejer3);
    printf("Ingrese cadena2: ");
    scanf("%s", cadena2ejer3);

    printf("Comparación: %d", strcmp(cadena1ejer3, cadena2ejer3));
}

// 4. **Invertir una palabra:**
//    - Escribe una función que invierta una cadena de caracteres ingresada por el usuario.
void ejer4()
{
    char cadena1ejer4[100], cadenainvertida[100];
    printf("Ingresa una cadena: ");
    scanf("%s", cadena1ejer4);
    invertir_palabra(cadena1ejer4, cadenainvertida);
    printf("Palabra invertida: %s", cadenainvertida);
}

// 5. **Mayúscula a minúscula (char):**
//    - Implementa un programa que convierta un carácter en mayúscula a minúscula sin usar funciones de librería.
void ejer5()
{
    char letra1 = 'O';
    printf("Mayuscula '%c' a minúscula: '%c'\n", letra1, mayuscula_a_minuscula(letra1));
}

// 6. **Minúscula a mayúscula (char):**
//    - Implementa un programa que convierta un carácter en minúscula a mayúscula sin usar funciones de librería.
void ejer6(){
    char letra1ejer6 = 'j';
    printf("Minuscula '%c' a mayuscula: '%c'\n", letra1ejer6, minuscula_a_mayuscula(letra1ejer6));
}

// 7. **Mayúscula a minúscula (Array char):**
//    - Escribe un programa que convierta todas las letras de una cadena de mayúsculas a minúsculas.
void ejer7(){
    char frase[250];
    char vocales[50];
    printf("Introducir frase: %d", frase);
    obtener_vocales(frase, vocales);
    printf("Vocales en '%s': %s\n", frase, vocales);
}

// 8. **Minúscula a mayúscula (Array char):**
//    - Escribe un programa que convierta todas las letras de una cadena de minúsculas a mayúsculas.
void ejer9(){

}

// 9. **Convertir int a char:**
//    - Implementa un programa que convierta un número entero a carácter.

// 10. **Convertir char a int:**
//     - Escribe un programa que convierta un carácter numérico a su valor entero correspondiente.

// 11. **Obtener vocales de una cadena:**
//     - Diseña un programa que extraiga todas las vocales de una cadena ingresada por el usuario.

// 12. **Obtener consonantes de una cadena:**
//     - Diseña un programa que extraiga todas las consonantes de una cadena ingresada por el usuario.

// 13. **Determinar si un número es primo:**
//     - Escribe una función que determine si un número es primo.

// 14. **Cálculo del Mínimo Común Múltiplo (MCM):**
//     - Escribe un programa que calcule el MCM de dos números dados.

// 15. **Cálculo del Máximo Común Divisor (MCD):**
//     - Implementa un programa que calcule el MCD de dos números.

// 16. **Determinar si un carácter es una vocal:**
//     - Escribe un programa que indique si un carácter ingresado es una vocal.

// 17. **Obtener números de un string:**
//     - Diseña un programa que extraiga todos los números de una cadena.

// 18. **Obtener letras de un string:**
//     - Diseña un programa que extraiga todas las letras de una cadena.

// 19. **Contar palabras en una cadena:**
//     - Implementa un programa que cuente cuántas palabras tiene una frase ingresada por el usuario.

// 20. **Obtener palabras de una frase por posición:**
//     - Escribe una función que extraiga una palabra específica de una frase dada una posición.

// 21. **Cifrado César:**
//     - Implementa el cifrado César para codificar un mensaje.

// 22. **Descifrado César:**
//     - Implementa el descifrado César para recuperar un mensaje cifrado.

// 23. **Alternar mayúsculas y minúsculas en una cadena:**
//     - Diseña un programa que alterne entre mayúsculas y minúsculas en una cadena.

// 24. **Comprobar subcadenas:**
//     - Escribe un programa que determine si una cadena está contenida dentro de otra.

//---

int main()
{
    int main()
{
    printf("Ejercicio 1: \n");
    ejer1();
    printf("\nEjercicio 2: \n");
    ejer2();
    printf("\nEjercicio 3: \n");
    ejer3();
    printf("\nEjercicio 4: \n");
    ejer4();
    printf("\nEjercicio 5: \n");
    ejer5();
    printf("\nEjercicio 6: \n");
    ejer6();
    printf("\nEjercicio 7: \n");
    ejer7();
    printf("\nEjercicio 8: \n");
    ejer8();
    printf("\nEjercicio 9: \n");
    ejer9();
    printf("\nEjercicio 10: \n");
    ejer10();
    printf("\nEjercicio 11: \n");
    ejer11();
    printf("\nEjercicio 12: \n");
    ejer12();
    printf("\nEjercicio 13: \n");
    ejer13();
    printf("\nEjercicio 14: \n");
    ejer14();
    printf("\nEjercicio 15: \n");
    ejer15();
    printf("\nEjercicio 16: \n");
    ejer16();
    printf("\nEjercicio 17: \n");
    ejer17();
    printf("\nEjercicio 18: \n");
    ejer18();
    printf("\nEjercicio 19: \n");
    ejer19();
    printf("\nEjercicio 20: \n");
    ejer20();
    printf("\nEjercicio 21: \n");
    ejer21();
    printf("\nEjercicio 22: \n");
    ejer22();
    printf("\nEjercicio 23: \n");
    ejer23();
    printf("\nEjercicio 24: \n");
    ejer24();
    
    return 0;
}
}

//**Criterios de Evaluación:**
//- Correcta implementación del código (60%)
//- Explicación clara y concisa de cada solución (20%)
//- Uso adecuado de funciones y estructuras de C++ (20%)
