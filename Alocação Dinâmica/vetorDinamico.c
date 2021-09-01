#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Você já deve ter ouvido falar que é errado fazer o seguinte:
    /*
    printf("Qual o tamanho do vetor?");
    scanf("%d",&n);
    vetor[n];

    for(int i =0;i<n;i++)
    {
        scanf("%d",&vetor[i]);
    }

    Realmente, não faça isso, pode causar erros.
    Sendo assim, vamos aprender a criar um vetor dinâmico.
    Dessa forma, você pode criar um vetor do tamanho especificado pelo usuário e, caso necessário, pode realocar
    mais espaço posteriormente.
    */

    int *vetor;
    int n; // tamanho do vetor;
    int i; // para o loop

    printf("Tamanho do vetor:    "); scanf("%d%*c",&n);

    vetor = (int*)malloc(n*sizeof(int)); // malloc retorna um ponteiro para um bloco de memória capaz de guardar n inteiros
    // Além disso, lembre-se que o bloco de memoria tem endereços contíguos, pois se trata de um vetor
    
    if(vetor == NULL)
    {
        printf("Algum erro ocorreu");
        exit(1);
    }
    
    for(i=0;i<n;i++)
    {
        printf("\nInsira o valor %d do vetor: \n",i);
        scanf("%d%*c",&vetor[i]);
    }

    for(i=0;i<n;i++)
        printf(" %d ",*(vetor+i)); // nome do vetor é um ponteiro para o primeiro elemento. -> aritmética de ponteiro
    
    // As áreas alocadas via malloc são automaticamente terminadas quando a execução do programa termina
    // É possível explicitamente liberar a memória usando free(ponteiro para o bloco de memória)
    free(vetor);
    return 0;
}