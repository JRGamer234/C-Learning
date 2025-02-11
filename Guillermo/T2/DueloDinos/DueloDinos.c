#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char nombre[30];
    int vida;
    int energia;
    int defensa;
    int ataque;
    int agilidad;
} Dinosaurio;

typedef struct {
    int id_habilidad;
    char nombre_habilidad[30];
    char parametro_modificable[20];
    int valor;
} Habilidad;

// Colección de habilidades disponibles
Habilidad habilidades[] = {
    {1, "Rugido Feroz", "ataque", 15},
    {2, "Piel Dura", "defensa", 10},
    {3, "Velocidad", "agilidad", 8},
    {4, "Recuperación", "vida", 20},
    {5, "Vigor", "energia", 25}
};

const int NUM_HABILIDADES = 5;

int tirarDado() {
    return (rand() % 10) + 1;
}

int calcularIniciativa(Dinosaurio dino) {
    return tirarDado() + dino.agilidad;
}

int intentarHuir(Dinosaurio *atacante, Dinosaurio *defensor) {
    int tiradaAtacante = tirarDado() + atacante->agilidad;
    int tiradaDefensor = tirarDado() + defensor->agilidad;
    
    if (tiradaAtacante >= tiradaDefensor) {
        printf("%s logra huir! %s gana!\n", atacante->nombre, defensor->nombre);
        atacante->vida = 0;
        return 1;
    } else {
        printf("%s intenta huir pero %s lo impide!\n", atacante->nombre, defensor->nombre);
        return 0;
    }
}

void morder(Dinosaurio *atacante, Dinosaurio *victima) {
    int danio = atacante->ataque - (victima->defensa / 2);
    if (danio < 0) danio = 1;  // Daño mínimo
    victima->vida -= danio;
    atacante->energia -= 5;
    printf("%s muerde a %s causando %d de daño!\n", atacante->nombre, victima->nombre, danio);
}

void aplicarHabilidad(Dinosaurio *dino, Habilidad hab) {
    if (strcmp(hab.parametro_modificable, "vida") == 0) {
        dino->vida += hab.valor;
    } else if (strcmp(hab.parametro_modificable, "energia") == 0) {
        dino->energia += hab.valor;
    } else if (strcmp(hab.parametro_modificable, "defensa") == 0) {
        dino->defensa += hab.valor;
    } else if (strcmp(hab.parametro_modificable, "ataque") == 0) {
        dino->ataque += hab.valor;
    } else if (strcmp(hab.parametro_modificable, "agilidad") == 0) {
        dino->agilidad += hab.valor;
    }
    printf("%s usa %s! Su %s aumenta en %d puntos!\n", 
           dino->nombre, hab.nombre_habilidad, hab.parametro_modificable, hab.valor);
}

void mostrarHabilidades() {
    printf("\nHabilidades disponibles:\n");
    for (int i = 0; i < NUM_HABILIDADES; i++) {
        printf("%d) %s (%s +%d)\n", 
               habilidades[i].id_habilidad,
               habilidades[i].nombre_habilidad,  
               habilidades[i].parametro_modificable,
               habilidades[i].valor);
    }
}

void mostrarEstado(Dinosaurio dino1, Dinosaurio dino2) {
    printf("\nEstado actual:\n");
    printf("%s: Vida=%d, Energía=%d, Defensa=%d, Ataque=%d, Agilidad=%d\n", 
           dino1.nombre, dino1.vida, dino1.energia, dino1.defensa, dino1.ataque, dino1.agilidad);
    printf("%s: Vida=%d, Energía=%d, Defensa=%d, Ataque=%d, Agilidad=%d\n", 
           dino2.nombre, dino2.vida, dino2.energia, dino2.defensa, dino2.ataque, dino2.agilidad);
}

void menuCombate(Dinosaurio *atacante, Dinosaurio *defensor) {
    int opcion;
    printf("\nTurno de %s\n", atacante->nombre);
    printf("1) Morder\n");
    printf("2) Usar Habilidad\n");
    printf("3) Huir\n");
    printf("Elige tu acción: ");
    scanf("%d", &opcion);
    
    switch(opcion) {
        case 1:
            if (atacante->energia >= 5) {
                morder(atacante, defensor);
            } else {
                printf("%s está demasiado cansado para morder!\n", atacante->nombre);
            }
            break;
        case 2:
            mostrarHabilidades();
            printf("Elige una habilidad (1-%d): ", NUM_HABILIDADES);
            int hab_id;
            scanf("%d", &hab_id);
            if (hab_id >= 1 && hab_id <= NUM_HABILIDADES) {
                aplicarHabilidad(atacante, habilidades[hab_id-1]);
            } else {
                printf("Habilidad inválida, pierdes el turno!\n");
            }
            break;
        case 3:
            intentarHuir(atacante, defensor);
            break;
        default:
            printf("Opción inválida, pierdes el turno!\n");
    }
}

void inicializarDinosaurio(Dinosaurio *dino) {
    dino->vida = 100;
    dino->energia = 100;
    dino->defensa = 20;
    dino->ataque = 25;
    dino->agilidad = 15;
}

void menu() {
    int opcion;
    printf("============================\n");
    printf("=== Juego de Dinosaurios ===\n");
    printf("============================\n");
    printf("===   Quieres jugar ?    ===\n");
    printf("===  1) SI               ===\n");
    printf("===  2) NO               ===\n");
    printf("============================\n");
    scanf("%d", &opcion);
    
    if (opcion == 1) {
        Dinosaurio dino1, dino2;
        
        inicializarDinosaurio(&dino1);
        inicializarDinosaurio(&dino2);
        
        printf("Nombre del dinosaurio 1: ");
        scanf("%s", dino1.nombre);
        printf("Nombre del dinosaurio 2: ");
        scanf("%s", dino2.nombre);
        
        // Determinar quién empieza con tiro de iniciativa
        int iniciativa1 = calcularIniciativa(dino1);
        int iniciativa2 = calcularIniciativa(dino2);
        
        printf("\n¡Tiro de iniciativa!\n");
        printf("%s obtiene %d\n", dino1.nombre, iniciativa1);
        printf("%s obtiene %d\n", dino2.nombre, iniciativa2);
        
        int turno = (iniciativa1 >= iniciativa2) ? 1 : 2;
        printf("\n¡%s comienza el combate!\n", (turno == 1) ? dino1.nombre : dino2.nombre);
        
        while (dino1.vida > 0 && dino2.vida > 0) {
            mostrarEstado(dino1, dino2);
            
            if (turno % 2 == 1) {
                menuCombate(&dino1, &dino2);
            } else {
                menuCombate(&dino2, &dino1);
            }
            
            turno++;
        }
        
        mostrarEstado(dino1, dino2);
        if (dino1.vida <= 0) {
            printf("\n¡%s ha ganado!\n", dino2.nombre);
        } else {
            printf("\n¡%s ha ganado!\n", dino1.nombre);
        }
    } else if (opcion == 2) {
        printf("Saliendo...\n");
    } else {
        printf("ERROR: Opción inválida\n");
    }
}

int main() {
    menu();
    return 0;
}