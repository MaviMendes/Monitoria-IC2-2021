#include <stdio.h>
#include <stdlib.h>

#define  SIZE 1001 // vetor comeca em indice 1
void quicksort(int *v, int n);
void particiona(int *v, int l, int r);
void imprimirVetor(int *v, int n);

int main()
{
    
    FILE *fileA = fopen("A.txt","r");
    FILE *fileB = fopen("B.txt","r");
    
    int i;
    int *arrayA, *arrayB;
    arrayA = (int*)malloc(SIZE*sizeof(int));
    arrayB = (int*)malloc(SIZE*sizeof(int));

    // ler do arquivo e inserir no vetor

    for(i=1;i<SIZE;i++)
    {
        fscanf(fileA,"%d",&arrayA[i]);
        fscanf(fileB,"%d",&arrayB[i]);
    }
    
    int count=1;

    /*printf("Esta funcionando? arrayA: \n");
    for(i=0;i<SIZE;i++)
    {
        printf("%d\n",arrayA[i]);
        count++;
    }
    printf("\ncount = %d\n", count);*/

    // abriu para ler, fechar
    fclose(fileA);
    fclose(fileB);

    // ordenar vetores
    quicksort(arrayA,SIZE);
    quicksort(arrayB, SIZE);

    printf("\narrayA:\n");
    imprimirVetor(arrayA,SIZE);
    printf("\narrayB:\n");
    imprimirVetor(arrayB,SIZE);
    // abrir para escrever
    FILE *A = fopen("A.txt","w+");
    FILE *B = fopen("B.txt","w+");

    // escrever: inserir dados ordenados
     for(i=1;i<SIZE;i++)
    {
        fprintf(A,"%d\n",arrayA[i]);
        fprintf(B,"%d\n",arrayB[i]);
    }

    // liberar espaco dos vetores e fechar arquivos depois de fazer todos os procedimentos necessarios
    free(arrayA);
    free(arrayB);
    fclose(A);
    fclose(B);

    return 0;
}

//QUICKSORT

//particao

void particiona(int *v, int l, int r)
{
    int i = l, 
    j = r, 
    x = v[(l+r)/2],
    w;

    //elementos menores que x ficam a sua esquerda, elementos maiores que x ficam a sua direita

    do
    {

    while(v[i] < x)
    i++;
          
    while(v[j]>x)
    j--;

    if(i<=j)
    {
        w = v[i]; //permuta os elementos: maior que x vai para a direita, menor que x vai para a esquerda
        v[i] = v[j];
        v[j] = w;
        i++;
        j--;
    }

    }
    while(i<=j);
    
    //recursao

    if(l < j)
      particiona(v,l,j); //particionar a metade esquerda

    if(i < r)
      particiona(v,i,r); //particiona a metade direita
} //particionamentos feitos ate que tenha 1 elemento

void quicksort(int *v, int n)
{
   particiona(v,1,n);
}

void imprimirVetor(int *v, int n)
{
    int i;
    printf("[ ");
    for(i=1;i<=n;i++)
    {
        printf(" %d ",v[i]);
    }
    printf(" ]");
}