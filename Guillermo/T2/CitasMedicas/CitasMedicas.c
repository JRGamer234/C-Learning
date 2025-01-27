#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
    Deben poder darse de alta pacientes
    Deben poder darse de alta citas (con id propio, fecha e identificador del paciente que las solicitó)
    Deben poder modificarse citas
    Deben poder borrarse citas
*/

#define MAX_PACIENTES 100
#define MAX_CITAS 100

typedef struct {
    char nombre[50];
    char fecha_nacimiento[11];
    char dni[10];
    char fecha_registro[11];
    int activo;
} Paciente;

typedef struct {
    int id;
    char fecha[11];
    char dni_paciente[10];
    int activo;
} Cita;

Paciente pacientes[MAX_PACIENTES];
Cita citas[MAX_CITAS];
int num_pacientes = 0;
int num_citas = 0;

void mostrarMenu();
void altaPaciente();
void altaCita();
void modificarCita();
void borrarCita();
void verPerfil();
int buscarPaciente(char dni[]);
void limpiarPantalla();

int main() {
    int opcion;
    
    for(int i = 0; i < MAX_PACIENTES; i++) {
        pacientes[i].activo = 0;
    }
    for(int i = 0; i < MAX_CITAS; i++) {
        citas[i].activo = 0;
    }
    
    do {
        mostrarMenu();
        scanf("%d", &opcion);
        limpiarPantalla();
        
        switch(opcion) {
            case 1:
                altaPaciente();
                break;
            case 2:
                altaCita();
                break;
            case 3:
                modificarCita();
                break;
            case 4:
                borrarCita();
                break;
            case 5:
                verPerfil();
                break;
            case 6:
                printf("\nGracias por usar el sistema.\n");
                break;
            default:
                printf("\nOpción no válida.\n");
        }
        
        printf("\nPresiona Enter para continuar...");
        getchar();
        getchar();
        limpiarPantalla();
        
    } while(opcion != 6);
    
    return 0;
}

void mostrarMenu() {
    printf("=====================\n");
    printf("==  Citas Médicas  ==\n");
    printf("=====================\n");
    printf("\n1. Alta de Paciente");
    printf("\n2. Alta de Cita");
    printf("\n3. Modificar Cita");
    printf("\n4. Borrar Cita");
    printf("\n5. Ver Perfil");
    printf("\n6. Salir");
    printf("\n\nElige una opción: ");
}

void altaPaciente() {
    if(num_pacientes >= MAX_PACIENTES) {
        printf("\nNo hay espacio para más pacientes.\n");
        return;
    }
    
    Paciente nuevoPaciente;
    printf("\n== Alta de Paciente ==\n");
    printf("\nNombre: ");
    getchar();
    fgets(nuevoPaciente.nombre, 50, stdin);
    nuevoPaciente.nombre[strcspn(nuevoPaciente.nombre, "\n")] = 0;
    
    printf("Fecha de nacimiento (DD/MM/AAAA): ");
    scanf("%s", nuevoPaciente.fecha_nacimiento);
    
    printf("DNI: ");
    scanf("%s", nuevoPaciente.dni);
    
    printf("Fecha actual (DD/MM/AAAA): ");
    scanf("%s", nuevoPaciente.fecha_registro);
    
    nuevoPaciente.activo = 1;
    
    for(int i = 0; i < MAX_PACIENTES; i++) {
        if(!pacientes[i].activo) {
            pacientes[i] = nuevoPaciente;
            num_pacientes++;
            printf("\nPaciente registrado con éxito.\n");
            return;
        }
    }
}

void altaCita() {
    if(num_citas >= MAX_CITAS) {
        printf("\nNo hay espacio para más citas.\n");
        return;
    }
    
    Cita nuevaCita;
    char dni[10];
    
    printf("\n== Alta de Cita ==\n");
    printf("\nDNI del paciente: ");
    scanf("%s", dni);
    
    if(buscarPaciente(dni) == -1) {
        printf("\nPaciente no encontrado.\n");
        return;
    }
    
    strcpy(nuevaCita.dni_paciente, dni);
    printf("Fecha de la cita (DD/MM/AAAA): ");
    scanf("%s", nuevaCita.fecha);
    
    nuevaCita.id = num_citas + 1;
    nuevaCita.activo = 1;
    
    for(int i = 0; i < MAX_CITAS; i++) {
        if(!citas[i].activo) {
            citas[i] = nuevaCita;
            num_citas++;
            printf("\nCita registrada con éxito. ID de cita: %d\n", nuevaCita.id);
            return;
        }
    }
}

void modificarCita() {
    char dni[10];
    int encontrado = 0;
    
    printf("\n== Modificar Cita ==\n");
    printf("\nDNI del paciente: ");
    scanf("%s", dni);
    
    printf("\nCitas encontradas:\n");
    for(int i = 0; i < MAX_CITAS; i++) {
        if(citas[i].activo && strcmp(citas[i].dni_paciente, dni) == 0) {
            printf("ID: %d - Fecha: %s\n", citas[i].id, citas[i].fecha);
            encontrado = 1;
            
            printf("\nNueva fecha (DD/MM/AAAA): ");
            scanf("%s", citas[i].fecha);
            printf("\nCita modificada con éxito.\n");
        }
    }
    
    if(!encontrado) {
        printf("\nNo se encontraron citas para este DNI.\n");
    }
}

void borrarCita() {
    char dni[10];
    int encontrado = 0;
    char confirmar;
    
    printf("\n== Borrar Cita ==\n");
    printf("\nDNI del paciente: ");
    scanf("%s", dni);
    
    printf("\nCitas encontradas:\n");
    for(int i = 0; i < MAX_CITAS; i++) {
        if(citas[i].activo && strcmp(citas[i].dni_paciente, dni) == 0) {
            printf("ID: %d - Fecha: %s\n", citas[i].id, citas[i].fecha);
            encontrado = 1;
            
            printf("\n¿Desea borrar esta cita? (s/n): ");
            getchar();
            scanf("%c", &confirmar);
            
            if(confirmar == 's' || confirmar == 'S') {
                citas[i].activo = 0;
                printf("\nCita borrada con éxito.\n");
            }
        }
    }
    
    if(!encontrado) {
        printf("\nNo se encontraron citas para este DNI.\n");
    }
}

void verPerfil() {
    char dni[10];
    int indice;
    
    printf("\n== Ver Perfil ==\n");
    printf("\nDNI del paciente: ");
    scanf("%s", dni);
    
    indice = buscarPaciente(dni);
    if(indice != -1) {
        printf("\nDatos del paciente:\n");
        printf("Nombre: %s\n", pacientes[indice].nombre);
        printf("Fecha de nacimiento: %s\n", pacientes[indice].fecha_nacimiento);
        printf("Fecha de registro: %s\n", pacientes[indice].fecha_registro);
        
        printf("\nCitas programadas:\n");
        int tieneCitas = 0;
        for(int i = 0; i < MAX_CITAS; i++) {
            if(citas[i].activo && strcmp(citas[i].dni_paciente, dni) == 0) {
                printf("ID: %d - Fecha: %s\n", citas[i].id, citas[i].fecha);
                tieneCitas = 1;
            }
        }
        
        if(!tieneCitas) {
            printf("No tiene citas programadas.\n");
        }
    } else {
        printf("\nPaciente no encontrado.\n");
    }
}

int buscarPaciente(char dni[]) {
    for(int i = 0; i < MAX_PACIENTES; i++) {
        if(pacientes[i].activo && strcmp(pacientes[i].dni, dni) == 0) {
            return i;
        }
    }
    return -1;
}

void limpiarPantalla() {
    system("cls");
}