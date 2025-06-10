#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//#include <graphics.h>
#define RED   "\x1b[31m"
#define GREEN "\x1b[32m"
#define RESET "\x1b[0m"

#define MAX_KARTS 100

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

typedef struct ResultadoCarrera {
    char fecha[20];
    char tipo[30]; // "Resistencia 2h", "Sprint", etc.
    int posicion;
    struct ResultadoCarrera* next;
} ResultadoCarrera;

typedef struct BoxNode {
    int numeroKart;
    bool ocupado;
    struct BoxNode* next;
} BoxNode;

typedef struct BoxColumn {
    char nombre[6]; // "ROJO" o "AZUL"
    BoxNode* karts;
} BoxColumn;

User* userList = NULL;
User* usuarioActual = NULL;
Circuito* listaCircuitos = NULL;
ResultadoCarrera* listaResultados = NULL;

// Aquí podríamos inicializar la pantalla gráfica
void iniciarGraficos() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    setbkcolor(WHITE);
    cleardevice();
}

// Una función simple para mostrar texto en pantalla con `graphics.h`
void mostrarTextoGraficos(char* mensaje, int x, int y, int color) {
    setcolor(color);
    outtextxy(x, y, mensaje);
}

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

void registrarResultado() {
    ResultadoCarrera* nuevo = (ResultadoCarrera*)malloc(sizeof(ResultadoCarrera));
    if (!nuevo) return;

    limpiarBuffer(); // por seguridad
    printf("Ingrese la fecha (DD/MM/AAAA): ");
    fgets(nuevo->fecha, sizeof(nuevo->fecha), stdin);
    nuevo->fecha[strcspn(nuevo->fecha, "\n")] = 0;

    printf("Tipo de carrera:\n");
    printf("1. Resistencia 2h\n");
    printf("2. Sprint\n");
    printf("3. Resistencia más horas\n");
    int tipo;
    scanf("%d", &tipo);

    switch (tipo) {
        case 1: strcpy(nuevo->tipo, "Resistencia 2h"); break;
        case 2: strcpy(nuevo->tipo, "Sprint"); break;
        case 3: strcpy(nuevo->tipo, "Resistencia más horas"); break;
        default: strcpy(nuevo->tipo, "Desconocido"); break;
    }

    printf("Posición final en la carrera: ");
    scanf("%d", &nuevo->posicion);

    nuevo->next = listaResultados;
    listaResultados = nuevo;

    printf("Resultado registrado con éxito.\n");
}

void verResultados() {
    ResultadoCarrera* temp = listaResultados;
    if (!temp) {
        printf("No hay resultados registrados.\n");
        return;
    }

    printf("=== RESULTADOS DE CARRERA ===\n");
    while (temp) {
        printf("Fecha: %s | Tipo: %s | Posición: %d\n", temp->fecha, temp->tipo, temp->posicion);
        temp = temp->next;
    }
}

int contarKarts(BoxNode* nodo) {
    int count = 0;
    while (nodo) {
        count++;
        nodo = nodo->next;
    }
    return count;
}

void mostrarBoxes(BoxColumn rojo, BoxColumn azul) {
    BoxNode* rojoArr[MAX_KARTS], *azulArr[MAX_KARTS];
    int totalR = 0, totalA = 0;
    
    BoxNode* temp = rojo.karts;
    while (temp && totalR < MAX_KARTS) {
        rojoArr[totalR++] = temp;
        temp = temp->next;
    }

    temp = azul.karts;
    while (temp && totalA < MAX_KARTS) {
        azulArr[totalA++] = temp;
        temp = temp->next;
    }

    printf("ROJO\t\tAZUL\n");
    int maxFilas = (totalR > totalA) ? totalR : totalA;
    
    for (int i = 0; i < maxFilas; i++) {
        if (i < totalR) {
            printf("%s%d\t%s", (i >= totalR - 2) ? GREEN : RED, rojoArr[i]->numeroKart, RESET);
        } else {
            printf("\t");
        }

        if (i < totalA) {
            printf("%s%d%s", (i >= totalA - 2) ? GREEN : RED, azulArr[i]->numeroKart, RESET);
        }
        printf("\n");
    }

    printf("\n%s= Ocupado%s, %s= Libre%s\n", RED, RESET, GREEN, RESET);
}

void inicializarBoxColumn(BoxColumn* columna, const char* nombre) {
    strcpy(columna->nombre, nombre);
    columna->karts = NULL;

    for (int i = 1; i <= 2; i++) {
        BoxNode* nuevo = (BoxNode*)malloc(sizeof(BoxNode));
        if (!nuevo) {
            printf("Error: No se pudo asignar memoria.\n");
            return;
        }
        nuevo->numeroKart = i;
        nuevo->ocupado = false;
        nuevo->next = columna->karts;
        columna->karts = nuevo;
    }
}

BoxNode* agregarKart(BoxColumn* columna, int numero) {
    BoxNode* nuevo = (BoxNode*)malloc(sizeof(BoxNode));
    if (!nuevo) {
        printf("Error: No se pudo asignar memoria.\n");
        return NULL;
    }
    nuevo->numeroKart = numero;
    nuevo->ocupado = false;
    nuevo->next = NULL;

    if (!columna->karts) {
        columna->karts = nuevo;
    } else {
        BoxNode* ultimo = columna->karts;
        while (ultimo->next) {
            ultimo = ultimo->next;
        }
        ultimo->next = nuevo;
    }
    return nuevo;
}

void estrategiaBoxes() {
    BoxColumn rojo, azul;
    inicializarBoxColumn(&rojo, "ROJO");
    inicializarBoxColumn(&azul, "AZUL");

    char columna;
    int numero;

    while (true) {
        printf("\nIntroduzca 'r' o 'a' seguido del número del kart (ej. r 5, 0 para salir): ");
        
        if (scanf(" %c %d", &columna, &numero) != 2) {
            printf("Entrada inválida. Inténtelo de nuevo.\n");
            while (getchar() != '\n');  // Limpieza de buffer
            continue;
        }

        if (numero == 0) {
            printf("Saliendo de estrategia de boxes...\n");
            return;
        }

        BoxColumn* target;
        if (columna == 'r' || columna == 'R') {
            target = &rojo;
        } else if (columna == 'a' || columna == 'A') {
            target = &azul;
        } else {
            printf("Columna inválida. Use 'r' o 'a'.\n");
            continue;
        }

        agregarKart(target, numero);
        mostrarBoxes(rojo, azul);
    }
}

void postLoginMenu() {
    int op;
    do {
        printf("\n--- MENÚ USUARIO (%s) ---\n", usuarioActual->username);
        printf("1. Ver circuitos\n");
        printf("2. Anadir circuito\n");
        printf("3. Eliminar circuito\n");
        printf("4. Registrar resultado carrera\n");
        printf("5. Ver resultados\n");
        printf("6. Estrategia en boxes\n");
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
            case 4: registrarResultado(); break;
        	case 5: verResultados(); break;
        	case 6: estrategiaBoxes(); break;
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
    while (listaResultados) {
        ResultadoCarrera* r = listaResultados;
        listaResultados = listaResultados->next;
        free(r);
    }

}

int main() {
	
	iniciarGraficos();
    mostrarTextoGraficos("Bienvenido al sistema de carreras!", 100, 100, BLUE);
    
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
    delay(5000); // Mantener la pantalla por 5 segundos
    closegraph();
    return 0;

}


