#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//#include <graphics.h>

typedef struct Tiempo {
    char username[50];
    float tiempo; // en segundos
    struct Tiempo* next;
} Tiempo;

typedef struct Circuito {
    char nombre[50];
    Tiempo* listaTiempos;
    struct Circuito* next;
} Circuito;

typedef struct User {
    char username[50];
    char password[50];
    struct User* next;
} User;

User* userList = NULL;
User* usuarioActual = NULL;
Circuito* listaCircuitos = NULL;

float convertirTiempo(const char* tiempoStr) {
    int min, seg, mil;
    if (sscanf(tiempoStr, "%d:%d:%d", &min, &seg, &mil) != 3) {
        printf("Formato inválido. Use mm:ss:ddd\n");
        return -1;
    }
    return min * 60 + seg + mil / 1000.0;
}

void registerUser() {
    char username[50], password[50];
    printf("Ingrese nombre de usuario: ");
    scanf("%s", username);

    // Verifica si el usuario ya existe
    User* temp = userList;
    while (temp) {
        if (strcmp(temp->username, username) == 0) {
            printf("Ese usuario ya existe.\n");
            return;
        }
        temp = temp->next;
    }

    printf("Ingrese contrasena: ");
    scanf("%s", password);

    User* newUser = (User*)malloc(sizeof(User));
    if (!newUser) return;

    strcpy(newUser->username, username);
    strcpy(newUser->password, password);
    newUser->next = userList;
    userList = newUser;

    printf("Registro exitoso.\n");
}


bool loginUser() {
    char username[50], password[50];
    printf("Ingrese nombre de usuario: ");
    scanf("%s", username);
    printf("Ingrese contrasena: ");
    scanf("%s", password);

    User* temp = userList;
    while (temp) {
        if (strcmp(temp->username, username) == 0 &&
            strcmp(temp->password, password) == 0) {
            usuarioActual = temp;
            printf("Inicio de sesión exitoso.\n");
            return true;
        }
        temp = temp->next;
    }
    printf("Usuario o contrasena incorrectos.\n");
    return false;
}

void showUsers() {
    User* temp = userList;
    printf("Usuarios registrados:\n");
    while (temp) {
        printf("- %s\n", temp->username);
        temp = temp->next;
    }
}

void inicializarCircuitos() {
    const char* nombres[5] = {"Santos", "Ariza", "Henakart", "Burgueno", "DR7"};
    for (int i = 0; i < 5; i++) {
        Circuito* nuevo = (Circuito*)malloc(sizeof(Circuito));
        strcpy(nuevo->nombre, nombres[i]);
        nuevo->listaTiempos = NULL;
        nuevo->next = listaCircuitos;
        listaCircuitos = nuevo;
    }
}

Circuito* buscarCircuito(const char* nombre) {
    Circuito* temp = listaCircuitos;
    while (temp) {
        if (strcmp(temp->nombre, nombre) == 0)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

void mostrarCircuitos() {
    Circuito* temp = listaCircuitos;
    int i = 1;
    while (temp) {
        printf("%d. %s\n", i++, temp->nombre);
        temp = temp->next;
    }
}

void anadirCircuito() {
    char nombre[50];
    printf("Ingrese nombre del nuevo circuito: ");
    scanf("%s", nombre);

    if (buscarCircuito(nombre)) {
        printf("El circuito ya existe. Se importarán los datos existentes.\n");
        return;
    }

    Circuito* nuevo = (Circuito*)malloc(sizeof(Circuito));
    strcpy(nuevo->nombre, nombre);
    nuevo->listaTiempos = NULL;
    nuevo->next = listaCircuitos;
    listaCircuitos = nuevo;

    printf("Circuito anadido exitosamente.\n");
}

void eliminarCircuito() {
    char nombre[50];
    printf("Ingrese nombre del circuito a eliminar: ");
    scanf("%s", nombre);

    Circuito *temp = listaCircuitos, *prev = NULL;
    while (temp) {
        if (strcmp(temp->nombre, nombre) == 0) {
            if (prev) prev->next = temp->next;
            else listaCircuitos = temp->next;

            Tiempo* t = temp->listaTiempos;
            while (t) {
                Tiempo* aux = t;
                t = t->next;
                free(aux);
            }

            free(temp);
            printf("Circuito eliminado.\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("Circuito no encontrado.\n");
}

void limpiarBuffer() {
    char ch;
    while (ch = getchar(), ch != '\n');
}

void anadirTiempo(Circuito* c) {
    Tiempo* nuevo = (Tiempo*)malloc(sizeof(Tiempo));
    if (!nuevo) return;

    strcpy(nuevo->username, usuarioActual->username);

    char tiempoStr[20];
    float tiempo;

    while (1) {
        printf("Ingrese su mejor tiempo (mm:ss:ddd): ");
        scanf("%19s", tiempoStr);
        limpiarBuffer(); // evitar bucles

        tiempo = convertirTiempo(tiempoStr);
        if (tiempo >= 0)
            break;

        printf("Formato inválido. Intente nuevamente.\n");
    }

    nuevo->tiempo = tiempo;
    nuevo->next = c->listaTiempos;
    c->listaTiempos = nuevo;

    printf("Tiempo registrado: %.3f s\n", tiempo);
}

void verTiempos(Circuito* c) {
    Tiempo* temp = c->listaTiempos;
    if (!temp) {
        printf("Sin tiempos registrados.\n");
        return;
    }

    printf("Tiempos en %s:\n", c->nombre);
    while (temp) {
        printf("%s: %.3f s\n", temp->username, temp->tiempo);
        temp = temp->next;
    }
}

void menuTiempos(Circuito* circuito) {
    int op;
    do {
        printf("\n--- %s ---\n", circuito->nombre);
        printf("1. Anadir tiempo\n");
        printf("2. Ver tiempos\n");
        printf("0. Volver atrás\n");
        printf("Opción: ");
        scanf("%d", &op);

        switch(op) {
            case 1: anadirTiempo(circuito); break;
            case 2: verTiempos(circuito); break;
            case 0: break;
            default: printf("Opción no válida.\n");
        }
    } while (op != 0);
}

void postLoginMenu() {
    int op;
    do {
        printf("\n--- MENÚ USUARIO (%s) ---\n", usuarioActual->username);
        printf("1. Ver circuitos\n");
        printf("2. Anadir circuito\n");
        printf("3. Eliminar circuito\n");
        printf("0. Cerrar sesión\n");
        printf("Opción: ");
        scanf("%d", &op);

        switch(op) {
            case 1: {
   				mostrarCircuitos();
    			printf("Seleccione un número o 0 para volver: ");
    			int sel;
    			scanf("%d", &sel);
    			if (sel == 0) break;

    			Circuito* temp = listaCircuitos;
   	 			int i = 1;
    			while (temp && i < sel) {
        			temp = temp->next;
        			i++;
    			}

    			if (temp && i == sel) {
        			menuTiempos(temp);
    			} else {
        			printf("Selección inválida.\n");
    			}
    			break;
			}

            case 2: anadirCircuito(); break;
            case 3: eliminarCircuito(); break;
            case 0: printf("Cerrando sesión...\n"); usuarioActual = NULL; break;
            default: printf("Opción no válida.\n");
        }
    } while (op != 0);
}

void liberarMemoria() {
    while (userList) {
        User* temp = userList;
        userList = userList->next;
        free(temp);
    }

    while (listaCircuitos) {
        Circuito* c = listaCircuitos;
        listaCircuitos = listaCircuitos->next;

        Tiempo* t = c->listaTiempos;
        while (t) {
            Tiempo* aux = t;
            t = t->next;
            free(aux);
        }

        free(c);
    }
}

int main() {
    int op;
    inicializarCircuitos();

    do {
        printf("\n=== MENÚ PRINCIPAL ===\n");
        printf("1. Registrarse\n");
        printf("2. Iniciar sesión\n");
        printf("3. Mostrar usuarios\n");
        printf("0. Salir\n");
        printf("Opción: ");
        scanf("%d", &op);

        switch(op) {
            case 1: registerUser(); break;
            case 2: if (loginUser()) postLoginMenu(); break;
            case 3: showUsers(); break;
            case 0: printf("Saliendo...\n"); break;
            default: printf("Opción inválida.\n");
        }
    } while (op != 0);
    
    liberarMemoria();
    return 0;

}


