#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

typedef struct
{
    int id;
    char nick[30];
    int puntuacion;
} Usuario;

void InicializarUsuarios(Usuario *usuarios)
{
    int i;
   
    Usuario *aux_origen = usuarios;
   
    for(i=0; i<10; i++)
    {
        usuarios->id = -1;
        strcpy(usuarios->nick,"");
        usuarios->puntuacion = 0;
        usuarios++;
    }
    usuarios = aux_origen;
}
void ImprimirDatosUsuarios(Usuario *usuarios)
{
    int i;
   
    Usuario *aux_origen = usuarios;
   
    for(i=0; i<10; i++)
    {    
        printf("------------------\n");    
        printf("ID: %d\n", usuarios->id);
        printf("Nick: %s\n", usuarios->nick);
        printf("Puntuacion: %d\n", usuarios->puntuacion);
        usuarios++;
    }
    usuarios = aux_origen;
}
void AltaUsuario(Usuario *usuarios)
{
    int i;
   
    Usuario *aux_origen = usuarios;
    //Recorrer el array buscando un espacio con id = -1
    while(usuarios->id != -1)
    {
        usuarios++;
    }
   
    //Dar de Alta
    usuarios->id = rand() % 99999;
   
    printf("Dame nombre:");
    fflush(stdin);
    scanf("%s", usuarios->nick);
    usuarios->puntuacion = 0;
   
    usuarios = aux_origen;
}

void EliminarUsuario(Usuario *usuarios)
{
    char nick_objetivo[30];
    int i;
    Usuario *aux_origen = usuarios;
   
    printf("Pone el nick del usuario a eliminar");
    fflush(stdin);
    scanf("%s", nick_objetivo);
   
    //Recorrer array de usuarios mirando donde esta el nick_objetivo
    for(i=0; i<10; i++)
    {
        if(strcmp(nick_objetivo,usuarios->nick) == 0)
        {
            usuarios->id = -1;
            strcpy(usuarios->nick,"");
            usuarios->puntuacion = 0;

            return;
        }
        usuarios++;
    }
    usuarios = aux_origen;
}

int main()
{
    Usuario usuarios[10];

    InicializarUsuarios(usuarios);
   
    //Dar 3 usuarios de alta
    AltaUsuario(usuarios);
    AltaUsuario(usuarios);
    AltaUsuario(usuarios);
    //Cargarme el 2º usuario
    EliminarUsuario(usuarios);
    //Ver que efectivamente esta todo como debe
    ImprimirDatosUsuarios(usuarios);
    //Introducir nuevo usuario y comprobar que ha ocupado el espacio 2º
    AltaUsuario(usuarios);    
    //Ver que efectivamente esta todo como debe
    ImprimirDatosUsuarios(usuarios);
   
    return 0;
}