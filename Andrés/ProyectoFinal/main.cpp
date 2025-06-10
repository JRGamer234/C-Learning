#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructuras simples
typedef struct {
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
    
    printf("Credenciales incorrectas!\n");
    pausa();
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
