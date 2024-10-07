#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
   
    int cpu;
   
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
