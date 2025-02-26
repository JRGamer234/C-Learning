#include<stdio.h>

struct alumno{
	char nombre[50];
	int notaMedia;
};

void imprimir(struct alumno datos[], int len){
	for(int i = 0 ; i < len ; i++){
		printf("alumno: %s %d ", datos[i].nombre, datos[i].notaMedia);
	}
	
	printf("\n");
}

int main(){
	
	int len = 4;
	struct alumno aux;
	struct alumno datos[len];
	
	for(int i = 0 ; i < len ; i++){
		printf("Introduce el nombre: ");
		scanf("%s", datos[i].nombre);
		printf("Introduce la nota media: ");
		scanf("%d", &datos[i].notaMedia);
	}7
	
	imprimir(datos, len);
	
	// de menor a mayor	
	for(int i = 0 ; i < len ; i++){
		for(int j = 0 ; j < len ; j++){
			if(datos[i].notaMedia < datos[j].notaMedia){
				aux = datos[i];
				datos[i] = datos[j];
				datos[j] = aux;
			}
		}
	}
	
	imprimir(datos, len);
	
	// de mayor a menor	
	for(int i = 0 ; i < len ; i++){
		for(int j = 0 ; j < len ; j++){
			if(datos[i].notaMedia > datos[j].notaMedia){
				aux = datos[i];
				datos[i] = datos[j];
				datos[j] = aux;
			}
		}
	}
	
	imprimir(datos, len);
}y