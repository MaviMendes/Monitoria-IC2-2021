#include <stdio.h>
#include <stdlib.h>
#define  SIZE 4000 // vetor comeca em indice 1
int verifica(int *arrayC, int *arrayCGabarito);

int main()
{
    // abrir arquivo C e verificar se ele esta correto:

    FILE *fileC = fopen("C.txt","r"); // seu arquivo C
    FILE *fileCGabarito = fopen("CGabarito.txt","r");

    int i;
    int *arrayC;
    int *arrayCGabarito;
    arrayC = (int*)malloc(SIZE*sizeof(int));
    arrayCGabarito = (int*)malloc(SIZE*sizeof(int));

    // ler do arquivo e inserir no vetor

    for(i=1;i<SIZE;i++)
    {
        fscanf(fileC,"%d",&arrayC[i]);
        fscanf(fileCGabarito,"%d",&arrayCGabarito[i]);
    }

    int verificacao = verifica(arrayC,arrayCGabarito);

    if(verificacao == 1)
        printf("CERTO! PARABENS!");
    else 
        printf("Tente novamente.");

    free(arrayC);
    free(arrayCGabarito);
    fclose(fileCGabarito);
    fclose(fileC);
    
}

int verifica(int *arrayC, int *arrayCGabarito)
{
    int i=0;
    int certo = 1;

    for(i=1;i<SIZE;i++)// foi convencionado que os vetores comecem no indice 1
    {
        
        if(arrayC[i] != arrayCGabarito[i])
        {
            printf("\nErro no indice %d, %d != %d\n",i,arrayC[i],arrayCGabarito[i]);
            certo = 0;
        }
    } 
        

    return certo;
}