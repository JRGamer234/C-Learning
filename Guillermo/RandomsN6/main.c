#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
   
    int opcion, cpu;
   
    srand(time(NULL));
   
   printf("****************************");
   printf("***Piedra, Papel o Tijera***");
   printf("****************************");	
   	
   	printf("1) 1 vs 1\n2) 1 vs BOT ");
   
    srand(time(NULL));
   
    do
    {
        system("cls");
        cpu = 1 + rand() % 10;
        printf("%d\n", cpu);
        cpu = 1 + rand() % 10;
        printf("%d\n", cpu);
        cpu = 1 + rand() % 10;
        printf("%d\n", cpu);
        sleep(1);
    }while(1);
   
   
    return 0;
}
