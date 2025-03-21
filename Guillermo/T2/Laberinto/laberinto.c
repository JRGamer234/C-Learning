#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <windows.h>

#define MAX_FILAS 25
#define MAX_COLUMNAS 100

#define MAX_COORDENADAS 256

#define RESET_COLOR    "\x1b[0m"
#define NEGRO_T        "\x1b[30m"
#define NEGRO_F        "\x1b[40m"
#define ROJO_T     "\x1b[31m"
#define ROJO_F     "\x1b[41m"
#define VERDE_T        "\x1b[32m"
#define VERDE_F        "\x1b[42m"
#define AMARILLO_T "\x1b[33m"
#define AMARILLO_F  "\x1b[43m"
#define AZUL_T     "\x1b[34m"
#define AZUL_F      "\x1b[44m"
#define MAGENTA_T  "\x1b[35m"
#define MAGENTA_F  "\x1b[45m"
#define CYAN_T     "\x1b[36m"
#define CYAN_F     "\x1b[46m"
#define BLANCO_T   "\x1b[37m"
#define BLANCO_F   "\x1b[47m"

typedef struct coordenada
{
	int fila;
	int columna;
} Coordenada;

typedef struct celda
{
	char valor;
	Coordenada posicion;
	bool visitado_N;
	bool visitado_O;
	bool visitado_S;
	bool visitado_E;
	bool revisada;
	int origen_acceso; //0 Vine desde el Norte
					   //1 Vine desde el Oeste
					   //2 Vine desde el Sur
					   //3 Vine desde el Este
} Celda;

typedef struct laberinto
{
	int altura;
	int anchura;
	Celda mapa[MAX_FILAS][MAX_COLUMNAS];
	bool modoCircular;
	
} Laberinto;

void gotoxy(int x,int y){  
    HANDLE hcon;  
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos;  
    dwPos.X = y;  
    dwPos.Y = x;  
    SetConsoleCursorPosition(hcon,dwPos);  
} 

int MenuPrincipal()
{
	int opcion;
	do
	{	
		system("cls");
		printf(BLANCO_T AMARILLO_F ">>>>GESTOR DE LABERINTOS<<<<" RESET_COLOR "\n");
		printf(BLANCO_T AMARILLO_F "****************************" RESET_COLOR "\n");
		printf(BLANCO_T AMARILLO_F "* 1. Generar laberinto     *" RESET_COLOR "\n");
		printf(BLANCO_T AMARILLO_F "* 2. Editar laberinto      *" RESET_COLOR "\n");
		printf(BLANCO_T AMARILLO_F "* 3. Guardar laberinto     *" RESET_COLOR "\n");
		printf(BLANCO_T AMARILLO_F "* 4. Cargar laberinto      *" RESET_COLOR "\n");
		printf(BLANCO_T AMARILLO_F "* 5. Tiene solucion?       *" RESET_COLOR "\n");
		printf(BLANCO_T AMARILLO_F "* 6. Solucionar            *" RESET_COLOR "\n");
		printf(BLANCO_T AMARILLO_F "* 0. Salir                 *" RESET_COLOR "\n");
		printf(BLANCO_T AMARILLO_F "****************************" RESET_COLOR "\n>");
		fflush(stdin);
		scanf("%d", &opcion);
	}while(opcion < 0 || opcion > 6);
	
	return opcion;
}
void InicializarLaberinto(Laberinto *lab)
{
	int i,j;
	
	lab->altura = MAX_FILAS;
	lab->anchura = MAX_COLUMNAS;
	
	for(i=0;i<lab->altura;i++)
		for(j=0;j<lab->anchura;j++)
		{
			lab->mapa[i][j].valor = ' ';
			lab->mapa[i][j].posicion.fila = i;
			lab->mapa[i][j].posicion.columna = j;
			lab->mapa[i][j].origen_acceso = -1;
			lab->mapa[i][j].revisada = false;
			lab->mapa[i][j].visitado_N = false;
			lab->mapa[i][j].visitado_O = false;
			lab->mapa[i][j].visitado_S = false;
			lab->mapa[i][j].visitado_E = false;
		}
}

void ImprimirInterfaz(Laberinto *lab)
{
	int i,j;
	system("cls");

	//IMPRIMIR EL MAPA
	for(i=0;i<lab->altura;i++)
	{
		for(j=0;j<lab->anchura;j++)
		{
			if(lab->mapa[i][j].valor == '#')
				printf(VERDE_T "%c" RESET_COLOR ,lab->mapa[i][j].valor);
			else if(lab->mapa[i][j].valor == 'E')
				printf(AMARILLO_T "%c" RESET_COLOR ,lab->mapa[i][j].valor);
			else if(lab->mapa[i][j].valor == 'S')
				printf(CYAN_T "%c" RESET_COLOR ,lab->mapa[i][j].valor);
			else
				printf("%c",lab->mapa[i][j].valor);
		}
		printf("\n");
	}
}
int GenerarLaberinto(Laberinto *lab)
{
	int i,j,pos_actual_i = 0, pos_actual_j = 0;
	int pos_entrada_i, pos_entrada_j, pos_salida_i, pos_salida_j;
	char tecla = ' ';
	
	bool entradaColocada = false;
	bool salidaColocada = false;
	
	system("cls");
	printf("Que dimensiones tendra el laberinto <altura> <anchura>:");
	scanf("%d %d", &lab->altura, &lab->anchura);
	
	if(lab->altura > MAX_FILAS || lab->anchura > MAX_COLUMNAS ||
	   lab->altura < 1 || lab->anchura < 1)
	{
		return -1;
	}
	
	for(i=0;i<lab->altura;i++)
		for(j=0;j<lab->anchura;j++)
			lab->mapa[i][j].valor = ' ';

	//Imprimir la interfaz
	ImprimirInterfaz(lab);

	printf(BLANCO_T AMARILLO_F ">>>>Modo EDICION<<<<" RESET_COLOR "\n");
	printf(BLANCO_T AZUL_F "Movimiento con teclas WASD. Poner (E)ntrada. Poner (Q)Salida. Poner (M)uro. Poner (C)amino.\n (X)Salir\n" RESET_COLOR "\n");
	gotoxy(pos_actual_i,pos_actual_j);
	while (tecla != 'x' && tecla != 'X')
	{
        // Si el usuario presiona una tecla
        if (kbhit()) {  
            tecla = getch(); // Captura la tecla presionada

            if(tecla == 'e' || tecla == 'E') //Colocar Entrada
            {
            	if(entradaColocada)
            	{
					gotoxy(pos_entrada_i, pos_entrada_j);
					printf(" ");
					lab->mapa[pos_entrada_i][pos_entrada_j].valor = ' ';
					gotoxy(pos_actual_i, pos_actual_j);
					printf("E");
					lab->mapa[pos_actual_i][pos_actual_j].valor = 'E';
					pos_entrada_i = pos_actual_i;
					pos_entrada_j = pos_actual_j;
				}
				else
				{
					pos_entrada_i = pos_actual_i;
					pos_entrada_j = pos_actual_j;
            		printf("E");
            		lab->mapa[pos_entrada_i][pos_entrada_j].valor = 'E';
            		entradaColocada = true;
            	}
			}
			if(tecla == 'm' || tecla == 'M') //Colocar Muro
            {
            	printf("#");
            	lab->mapa[pos_actual_i][pos_actual_j].valor = '#';
            }
            if(tecla == 'c' || tecla == 'C') //Colocar Camino
            {
            	printf(" ");
            	lab->mapa[pos_actual_i][pos_actual_j].valor = ' ';
            }
			if(tecla == 'q' || tecla == 'Q') //Colocar Salida
            {
            	if(salidaColocada)
            	{
					gotoxy(pos_salida_i, pos_salida_j);
					printf(" ");
					lab->mapa[pos_salida_i][pos_salida_j].valor = ' ';
					gotoxy(pos_actual_i, pos_actual_j);
					printf("S");
					lab->mapa[pos_actual_i][pos_actual_j].valor = 'S';
					pos_salida_i = pos_actual_i;
					pos_salida_j = pos_actual_j;
				}
				else
				{
					pos_salida_i = pos_actual_i;
					pos_salida_j = pos_actual_j;
            		printf("S");
            		lab->mapa[pos_actual_i][pos_actual_j].valor = 'S';
            		salidaColocada = true;
            	}
			}
            if ((tecla == 's' || tecla == 'S')
				&& pos_actual_i < lab->altura - 1)
			{
				pos_actual_i++;   	
            }
            if ((tecla == 'd' || tecla == 'D')
				&& pos_actual_j < lab->anchura - 1)
			{
                pos_actual_j++;
            }
            if ((tecla == 'w' || tecla == 'W')
				&& pos_actual_i > 0 ) {
                pos_actual_i--;	
            }
            if ((tecla == 'a' || tecla == 'A')
				&& pos_actual_j > 0 ) {
                pos_actual_j--;
            }
            
			gotoxy(pos_actual_i,pos_actual_j);
        }
    }
    //COMPROBAR QUE EL LABERINTO TIENE ENTRADA Y SALIDA
    if(!entradaColocada || !salidaColocada)
  		return -1;
  	else
  		return 0;
}
int EditarLaberinto(Laberinto *lab)
{
	int i,j,pos_actual_i = 0, pos_actual_j = 0;
	int pos_entrada_i, pos_entrada_j, pos_salida_i, pos_salida_j;
	char tecla = ' ';
	
	for(i=0;i<lab->altura;i++)
	{
		for(j=0;j<lab->anchura;j++)
		{
			if(lab->mapa[i][j].valor == 'E')
			{
				pos_entrada_i = i;
				pos_entrada_j = j;
			}
			if(lab->mapa[i][j].valor == 'S')
			{
				pos_salida_i = i;
				pos_salida_j = j;
			}
		}
	}
	//Imprimir la interfaz
	ImprimirInterfaz(lab);

	printf(BLANCO_T AMARILLO_F ">>>>Modo EDICION<<<<" RESET_COLOR "\n");
	printf(BLANCO_T AZUL_F "Movimiento con teclas WASD. Poner (E)ntrada. Poner (Q)Salida. Poner (M)uro. Poner (C)amino.\n (X)Salir\n" RESET_COLOR "\n");
	gotoxy(pos_actual_i,pos_actual_j);
	while (tecla != 'x' && tecla != 'X')
	{
        // Si el usuario presiona una tecla
        if (kbhit()) {  
            tecla = getch(); // Captura la tecla presionada

            if(tecla == 'e' || tecla == 'E') //Colocar Entrada
            {
				gotoxy(pos_entrada_i, pos_entrada_j);
				printf(" ");
				lab->mapa[pos_entrada_i][pos_entrada_j].valor = ' ';
				gotoxy(pos_actual_i, pos_actual_j);
				printf("E");
				lab->mapa[pos_actual_i][pos_actual_j].valor = 'E';
				pos_entrada_i = pos_actual_i;
				pos_entrada_j = pos_actual_j;
				
			}
			if(tecla == 'm' || tecla == 'M') //Colocar Muro
            {
            	printf("#");
            	lab->mapa[pos_actual_i][pos_actual_j].valor = '#';
            }
            if(tecla == 'c' || tecla == 'C') //Colocar Camino
            {
            	printf(" ");
            	lab->mapa[pos_actual_i][pos_actual_j].valor = ' ';
            }
			if(tecla == 'q' || tecla == 'Q') //Colocar Salida
            {
				gotoxy(pos_salida_i, pos_salida_j);
				printf(" ");
				lab->mapa[pos_salida_i][pos_salida_j].valor = ' ';
				gotoxy(pos_actual_i, pos_actual_j);
				printf("S");
				lab->mapa[pos_actual_i][pos_actual_j].valor = 'S';
				pos_salida_i = pos_actual_i;
				pos_salida_j = pos_actual_j;
			}
            if ((tecla == 's' || tecla == 'S')
				&& pos_actual_i < lab->altura - 1)
			{
				pos_actual_i++;   	
            }
            if ((tecla == 'd' || tecla == 'D')
				&& pos_actual_j < lab->anchura - 1)
			{
                pos_actual_j++;
            }
            if ((tecla == 'w' || tecla == 'W')
				&& pos_actual_i > 0 ) {
                pos_actual_i--;	
            }
            if ((tecla == 'a' || tecla == 'A')
				&& pos_actual_j > 0 ) {
                pos_actual_j--;
            }
            gotoxy(pos_actual_i,pos_actual_j);
        }
    }	
  		return 0;
}

bool TieneSolucion(Laberinto *lab)
{
	int i,j;
	Coordenada posicion_actual;
	bool laberintoConsumidoTotalmente = false;
	//Localizar la entrada del laberinto
	for(i=0;i<lab->altura;i++)
		for(j=0;j<lab->anchura;j++)
			if(lab->mapa[i][j].valor == 'E')
			{
				posicion_actual.fila = i;
				posicion_actual.columna = j;
			}

	while(!laberintoConsumidoTotalmente)
	{
		//¿TENGO LA SALIDA AL LADO?	
		if( (posicion_actual.fila - 1 >= 0 &&
		   lab->mapa[posicion_actual.fila - 1][posicion_actual.columna].valor == 'S') ||
		   (posicion_actual.columna - 1 >= 0 &&
		   lab->mapa[posicion_actual.fila][posicion_actual.columna - 1].valor == 'S') ||
		    (posicion_actual.fila + 1 < lab->altura &&
		   lab->mapa[posicion_actual.fila + 1][posicion_actual.columna].valor == 'S') ||
		   (posicion_actual.columna + 1 < lab->anchura &&
		   lab->mapa[posicion_actual.fila][posicion_actual.columna + 1].valor == 'S') )
				return true;
	
			// MOVERSE
    // COMPROBAR N
    if (posicion_actual.fila - 1 >= 0 &&
        lab->mapa[posicion_actual.fila - 1][posicion_actual.columna].valor == ' ' &&
        !lab->mapa[posicion_actual.fila - 1][posicion_actual.columna].revisada)
    {
        lab->mapa[posicion_actual.fila][posicion_actual.columna].revisada = true;
        posicion_actual.fila -= 1;
    }
    else if (posicion_actual.columna - 1 >= 0 &&
             lab->mapa[posicion_actual.fila][posicion_actual.columna - 1].valor == ' ' &&
             !lab->mapa[posicion_actual.fila][posicion_actual.columna - 1].revisada)
    {
        // COMPROBAR O
        lab->mapa[posicion_actual.fila][posicion_actual.columna].revisada = true;
        posicion_actual.columna -= 1;
    }
    else if (posicion_actual.fila + 1 < lab->altura &&
             lab->mapa[posicion_actual.fila + 1][posicion_actual.columna].valor == ' ' &&
             !lab->mapa[posicion_actual.fila + 1][posicion_actual.columna].revisada)
    {
        // COMPROBAR S
        lab->mapa[posicion_actual.fila][posicion_actual.columna].revisada = true;
        posicion_actual.fila += 1;
    }
    else if (posicion_actual.columna + 1 < lab->anchura &&
             lab->mapa[posicion_actual.fila][posicion_actual.columna + 1].valor == ' ' &&
             !lab->mapa[posicion_actual.fila][posicion_actual.columna + 1].revisada)
    {
        // COMPROBAR E
        lab->mapa[posicion_actual.fila][posicion_actual.columna].revisada = true;
        posicion_actual.columna += 1;
    }
    else
    {
        // Si no hay más movimientos posibles, el laberinto está consumido
        laberintoConsumidoTotalmente = true;
    }
	}
	return false;
}


int GuardarLaberinto(Laberinto *lab)
{
	int i, j;
	FILE *fp = NULL;
	
	fp = fopen("mapa.txt","w");
	if(fp == NULL)
	{
		return -1;
	}
	else
	{
		fprintf(fp,"%d %d\n",lab->altura,
							lab->anchura);
		
		for(i=0;i<lab->altura;i++)
		{
			for(j=0;j<lab->anchura;j++)
			{
				fprintf(fp,"%c", lab->mapa[i][j].valor);
			}
			fprintf(fp,"\n");
		}

		fclose(fp);
		return 0;
	}
	
}
int CargarLaberinto(Laberinto *lab)
{
	int i, j;
	FILE *fp = NULL;
	
	fp = fopen("mapa.txt","r");
	if(fp == NULL)
	{
		printf("Ha habido algun error al intentar cargar la simulacion\n");
		return -1;
	}
	else
	{
		fscanf(fp,"%d %d\n",&lab->altura,
							&lab->anchura);
		
		for(i=0;i<lab->altura;i++)
		{
			for(j=0;j<lab->anchura;j++)
			{
				lab->mapa[i][j].valor = fgetc(fp);	
			}
			fgetc(fp);
		}

		fclose(fp);
		return 0;
	}
}

int main(int argc, char *argv[])
{
	int opcion;
	int res;
	Laberinto lab;
	
	//Coordenada ruta[MAX_COORDENADAS];
	
	InicializarLaberinto(&lab);
	
	do
	{
		opcion = MenuPrincipal();
		switch(opcion)
		{
			case 1:
				res = GenerarLaberinto(&lab);
				system("cls");
				while(res == -1)
				{
					printf("Dimensiones incorrectas de mapa o falta Entrada y Salida\n");
					system("pause");
					res = GenerarLaberinto(&lab);
				}
				system("cls");
				printf("Configuracion de laberinto completada\n");
				system("pause");
				break;
			case 2:
				EditarLaberinto(&lab);
				system("cls");
				printf("El laberinto se edito correctamente\n");
				system("pause");
				break;
			case 3:
				res = GuardarLaberinto(&lab);
				system("cls");
				if(res == -1)
				{
					printf("Ha habido algun error al intentar grabar el laberinto\n");
				}
				else
				{
					printf("Laberinto guardado correctamente\n");
				}
				system("pause");
				break;
			case 4:
				res = CargarLaberinto(&lab);
				system("cls");
				if(res == -1)
				{
					printf("Ha habido algun error al intentar cargar el laberinto\n");
				}
				else
				{
					printf("Laberinto cargado correctamente\n");
				}
				system("pause");
				break;
			case 5:
				system("cls");
				if(TieneSolucion(&lab))
				{
					printf("El laberinto se puede solucionar\n");
				}
				else
				{
					printf("El laberinto NO se puede solucionar\n");
				}
				system("pause");
				break;
			case 6:
				break;
			case 0:
				break;
		}
	}while(opcion!=0);
	return 0;
}

