#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    
    FILE *file = fopen("A.txt","w+");
    srand(time(0)); // usar a hora atual como semente a fim de gerar numeros aleatorios diferentes a cada execucao do programa
    int i, num;

    for(i=0;i<1000;i++)
    {
        num = rand();

        // A: rand() % 3000 + 1985;   // A in the range 1985-4985
        // B: rand() % 1000 + 1;   // A in the range 1985-4985
        fprintf(file,"%d\n", rand()% 3000 + 1985);
    }

    fclose(file);

    return 0;
}