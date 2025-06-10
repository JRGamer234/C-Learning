#include <stdio.h>
#include <stdlib.h>
#include <string.h>
<<<<<<< HEAD

// Estructuras simples
typedef struct {
=======
#include <stdbool.h>
<<<<<<< HEAD
#include <graphics.h>
#include <winbgim.h>
#include <sstream>
=======
#include <cstring>
#include <graphics.h>
#include <winbgim.h>


>>>>>>> 37d98abb09c0d74074845813c25f14d61ee4a74f
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
>>>>>>> 4b47a765a008182bcfca4654a3f2adcac6d9d4a7
    char username[50];
    char password[50];
} Usuario;

typedef struct {
    char nombre[50];
    char tiempos[100][100]; // Almacena tiempos como string
    int numTiempos;
} Circuito;

// Variables globales simples
Usuario usuarios[50];
Circuito circuitos[10];
int numUsuarios = 0;
int numCircuitos = 0;
int usuarioLogueado = -1;

void limpiar() {
    system("cls");
}

void pausa() {
    printf("\nPresiona Enter...");
    getchar();
    getchar();
}

void inicializar() {
    // Circuitos por defecto
    strcpy(circuitos[0].nombre, "Santos");
    circuitos[0].numTiempos = 0;
    strcpy(circuitos[1].nombre, "Ariza");
    circuitos[1].numTiempos = 0;
    strcpy(circuitos[2].nombre, "Henakart");
    circuitos[2].numTiempos = 0;
    strcpy(circuitos[3].nombre, "Burgueno");
    circuitos[3].numTiempos = 0;
    strcpy(circuitos[4].nombre, "DR7");
    circuitos[4].numTiempos = 0;
    numCircuitos = 5;
}

void registrar() {
    limpiar();
    printf("\n=== REGISTRO ===\n");
    
    char user[50], pass[50];
    printf("Usuario: ");
    scanf("%s", user);
    printf("Password: ");
    scanf("%s", pass);
    
    // Verificar si existe
    for (int i = 0; i < numUsuarios; i++) {
        if (strcmp(usuarios[i].username, user) == 0) {
            printf("Usuario ya existe!\n");
            pausa();
            return;
        }
    }
    
    // Registrar
    strcpy(usuarios[numUsuarios].username, user);
    strcpy(usuarios[numUsuarios].password, pass);
    numUsuarios++;
    
    printf("Usuario registrado!\n");
    pausa();
}

int login() {
    limpiar();
    printf("\n=== LOGIN ===\n");
    
    char user[50], pass[50];
    printf("Usuario: ");
    scanf("%s", user);
    printf("Password: ");
    scanf("%s", pass);
    
    for (int i = 0; i < numUsuarios; i++) {
        if (strcmp(usuarios[i].username, user) == 0 && 
            strcmp(usuarios[i].password, pass) == 0) {
            usuarioLogueado = i;
            printf("Login exitoso!\n");
            pausa();
            return 1;
        }
    }
<<<<<<< HEAD
    
    printf("Credenciales incorrectas!\n");
    pausa();
=======
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

void mostrarMenu() {
    setcolor(WHITE);
    setbkcolor(BLACK);
    cleardevice();
    
    outtextxy(100, 50, "=== MENÚ PRINCIPAL ===");
    outtextxy(100, 100, "1. Registrarse");
    outtextxy(100, 150, "2. Iniciar sesión");
    outtextxy(100, 200, "3. Mostrar usuarios");
    outtextxy(100, 250, "0. Salir");
    outtextxy(100, 300, "Selecciona una opción:");
}

void dibujarMenu() {
    setcolor(WHITE);
    setbkcolor(BLACK);
    cleardevice();

    outtextxy(200, 50, "=== MENÚ PRINCIPAL ===");
    outtextxy(200, 100, "1. Registrarse");
    outtextxy(200, 150, "2. Iniciar sesión");
    outtextxy(200, 200, "3. Mostrar usuarios");
    outtextxy(200, 250, "0. Salir");
    outtextxy(200, 300, "Seleccione una opción:");

    rectangle(180, 90, 450, 270);  // Borde
}

int getMenuSelection() {
    while (!ismouseclick(WM_LBUTTONDOWN)) {}  // Espera un clic
    int x, y;
    getmouseclick(WM_LBUTTONDOWN, x, y);

    if (x >= 150 && x <= 450) {
        if (y >= 100 && y <= 150) return 1;
        if (y >= 170 && y <= 220) return 2;
        if (y >= 240 && y <= 290) return 3;
        if (y >= 310 && y <= 360) return 0;
    }

    return -1;
}

int main() {
    int gd = DETECT, gm;
<<<<<<< HEAD
    initgraph(&gd, &gm, "");
=======
    initwindow(640, 480);  // Ventana gráfica
>>>>>>> 37d98abb09c0d74074845813c25f14d61ee4a74f

    int op;
    do {
<<<<<<< HEAD
        mostrarMenu();
        scanf("%d", &op);
=======
        dibujarMenu();
        op = getMenuSelection();  // Detectar clic en los botones
>>>>>>> 37d98abb09c0d74074845813c25f14d61ee4a74f

        switch (op) {
            case 1: registerUser(); break;
            case 2: if (loginUser()) postLoginMenu(); break;
            case 3: showUsers(); break;
            case 0: break;  // Salir del programa
            default: printf("Opción inválida.\n");
        }
<<<<<<< HEAD
    } while (op != 0);

    closegraph();
    liberarMemoria();
=======

    } while (op != 0);

    closegraph();
>>>>>>> 37d98abb09c0d74074845813c25f14d61ee4a74f
>>>>>>> 4b47a765a008182bcfca4654a3f2adcac6d9d4a7
    return 0;
}

void verUsuarios() {
    limpiar();
    printf("\n=== USUARIOS ===\n");
    
    if (numUsuarios == 0) {
        printf("No hay usuarios\n");
    } else {
        for (int i = 0; i < numUsuarios; i++) {
            printf("%d. %s\n", i+1, usuarios[i].username);
        }
    }
    pausa();
}

void anadirTiempo(int circuito) {
    limpiar();
    printf("\n=== AÑADIR TIEMPO - %s ===\n", circuitos[circuito].nombre);
    
    char tiempo[20];
    printf("Ingrese tiempo (ej: 01:30:500): ");
    scanf("%s", tiempo);
    
    int indice = circuitos[circuito].numTiempos;
    sprintf(circuitos[circuito].tiempos[indice], "%s: %s", 
            usuarios[usuarioLogueado].username, tiempo);
    circuitos[circuito].numTiempos++;
    
    printf("Tiempo registrado!\n");
    pausa();
}

void verTiempos(int circuito) {
    limpiar();
    printf("\n=== TIEMPOS - %s ===\n", circuitos[circuito].nombre);
    
    if (circuitos[circuito].numTiempos == 0) {
        printf("Sin tiempos registrados\n");
    } else {
        for (int i = 0; i < circuitos[circuito].numTiempos; i++) {
            printf("%s\n", circuitos[circuito].tiempos[i]);
        }
    }
    pausa();
}

void menuCircuito(int circuito) {
    int op;
    do {
        limpiar();
        printf("\n=== %s ===\n", circuitos[circuito].nombre);
        printf("1. Añadir tiempo\n");
        printf("2. Ver tiempos\n");
        printf("0. Volver\n");
        printf("Opcion: ");
        scanf("%d", &op);
        
        switch(op) {
            case 1: anadirTiempo(circuito); break;
            case 2: verTiempos(circuito); break;
        }
    } while(op != 0);
}

void gestionCircuitos() {
    int op;
    do {
        limpiar();
        printf("\n=== CIRCUITOS ===\n");
        for (int i = 0; i < numCircuitos; i++) {
            printf("%d. %s\n", i+1, circuitos[i].nombre);
        }
        printf("0. Volver\n");
        printf("Opcion: ");
        scanf("%d", &op);
        
        if (op > 0 && op <= numCircuitos) {
            menuCircuito(op-1);
        }
    } while(op != 0);
}

void menuUsuario() {
    int op;
    do {
        limpiar();
        printf("\n=== MENU: %s ===\n", usuarios[usuarioLogueado].username);
        printf("1. Gestionar circuitos\n");
        printf("2. Simulacion boxes\n");
        printf("0. Cerrar sesion\n");
        printf("Opcion: ");
        scanf("%d", &op);
        
        switch(op) {
            case 1: gestionCircuitos(); break;
            case 2: 
                limpiar();
                printf("\n=== BOXES ===\n");
                printf("ROJO    AZUL\n");
                printf("----    ----\n");
                printf("K1      K1\n");
                printf("K2      K2\n");
                printf("Simulacion basica\n");
                pausa();
                break;
            case 0: usuarioLogueado = -1; break;
        }
    } while(op != 0);
}

int main() {
    inicializar();
    
    int op;
    do {
        limpiar();
        printf("\n================================\n");
        printf("      KARTING MANAGER\n");
        printf("================================\n");
        printf("1. Registrarse\n");
        printf("2. Iniciar sesion\n");
        printf("3. Ver usuarios\n");
        printf("0. Salir\n");
        printf("Opcion: ");
        scanf("%d", &op);
        
        switch(op) {
            case 1: registrar(); break;
            case 2: 
                if (login()) {
                    menuUsuario();
                }
                break;
            case 3: verUsuarios(); break;
            case 0: printf("Gracias!\n"); break;
            default: printf("Opcion invalida\n"); pausa();
        }
    } while(op != 0);
    
    return 0;
}
