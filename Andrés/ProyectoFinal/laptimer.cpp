#include <stdio.h>   // Uso de printf en lugar de cout
#include <stdlib.h>  // Para gestión de memoria dinámica
#include <string.h>  // Para manejo de cadenas
#include <stdbool.h> // Uso de valores booleanos
#include <graphics.h> // Librería gráfica según requisitos

// =============================
//      Estructura de Usuario
// =============================
typedef struct User {
    char username[50];  
    char password[50];  
    struct User* next;  // Puntero para lista enlazada de usuarios
} User;

// =============================
//   Variables Globales
// =============================
User* userList = NULL;  // Inicio de la lista enlazada

// =============================
//  Función de Registro de Usuario
// =============================
void registerUser() {
    User* newUser = (User*)malloc(sizeof(User)); // Reservamos memoria
    if (!newUser) {
        printf("Error al asignar memoria.\n");
        return;
    }

    printf("Ingrese nombre de usuario: ");
    scanf("%s", newUser->username);
    printf("Ingrese contraseña: ");
    scanf("%s", newUser->password);

    // Insertar usuario en la lista enlazada
    newUser->next = userList;
    userList = newUser;

    printf("Registro exitoso.\n");
}

// =============================
//  Función para Mostrar Usuarios
// =============================
void showUsers() {
    User* temp = userList;
    printf("Lista de Usuarios:\n");
    while (temp) {
        printf("- %s\n", temp->username);
        temp = temp->next;
    }
}

// =============================
//  Main - Menú inicial
// =============================
int main() {
    int option;
    
    do {
        printf("\n--- MENU PRINCIPAL ---\n");
        printf("1. Registrarse\n");
        printf("2. Mostrar usuarios registrados\n");
        printf("0. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &option);
        
        switch(option) {
            case 1:
                registerUser();
                break;
            case 2:
                showUsers();
                break;
            case 0:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida.\n");
        }
    } while (option != 0);
    
    return 0;
}

