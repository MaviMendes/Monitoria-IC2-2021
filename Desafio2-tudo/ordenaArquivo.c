#include <stdio.h>
#include <stdlib.h>

#define  SIZE 1001 // vetor comeca em indice 1
void quicksort(int *v, int n);
void particiona(int *v, int l, int r);
void imprimirVetor(int *v, int n);

int main()
{
    
    FILE *fileC = fopen("C.txt","r");
    
    int i;
    int *arrayC;
    arrayC = (int*)malloc(SIZE*sizeof(int));

    // ler do arquivo e inserir no vetor

    for(i=1;i<SIZE;i++)
    {
        fscanf(fileC,"%d",&arrayC[i]);
    }
    
    int count=1;
    printf("\narrayC ANTES DE ORDENAR:\n");
    imprimirVetor(arrayC,SIZE);
    // abriu para ler, fechar
    fclose(fileC);
    

    // ordenar vetores
    quicksort(arrayC,SIZE);
    

    printf("\narrayC:\n");
    imprimirVetor(arrayC,SIZE);
    
    // abrir para escrever
    FILE *C = fopen("C.txt","w+");
    
    // escrever: inserir dados ordenados
     for(i=1;i<SIZE;i++)
    {
        fprintf(C,"%d\n",arrayC[i]);
        
    }

    // liberar espaco dos vetores e fechar arquivos depois de fazer todos os procedimentos necessarios
    free(arrayC);
    fclose(C);
    
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