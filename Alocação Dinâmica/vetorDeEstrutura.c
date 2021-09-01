// Maria Vitoria Ribeiro Mendes - 30/08/2021
#include <stdio.h>
#include <stdlib.h>

// Boa prática: declare a estrutura fora da main

typedef struct pratoRestaurante{

    float valor;
    char nome[50];
    int numIngredientes;
    char **ingredientes;
} PRATO;

PRATO **inicializaEstrutura(PRATO **cardapio, int n)
{
    return (PRATO**)malloc(n*sizeof(PRATO));
}

char **inicializaArrayStrings(char **ingredientes, int n)
{
    return (char**)malloc(n*sizeof(char));
}

void adicionaIngredientes(char **Listaingredientes,int n)
{
    int i;
    printf("Adicionar ingredientes.\n");
    for(i=0;i<n;i++)
    {
        Listaingredientes[i] = (char*)malloc(50*sizeof(char));
        fgets(Listaingredientes[i],50,stdin); // ler, da entrada padrao, uma string de tamanho no maximo 50
        printf("Ingrediente %s adicionado.\n",Listaingredientes[i]);
    }
}

void preencheEstrutura(PRATO **cardapio,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        cardapio[i] = (PRATO*)malloc(sizeof(PRATO));
        printf("\nNome do prato %d:\n",i+1);
        //fscanf(cardapio[i]->nome,50,stdin); // da pra melhorar isso aqui
        fgets(cardapio[i]->nome,50,stdin);
        printf("Valor:\n");
        scanf("%f%*c",&cardapio[i]->valor);
        printf("Quantidade de ingrediantes:\n");
        scanf("%d%*c",&cardapio[i]->numIngredientes);
        cardapio[i]->ingredientes = inicializaArrayStrings(cardapio[i]->ingredientes,cardapio[i]->numIngredientes);
        adicionaIngredientes(cardapio[i]->ingredientes,cardapio[i]->numIngredientes);
        printf("\n_____________________\n");
    }
}


void imprimirCardapio(PRATO **cardapio, int n)
{
    int i;int j;

    for(i=0;i<n;i++)
    {
        printf("*Nome do prato: %s*Valor: %2.2f\n*Contem %d ingredientes:\n",cardapio[i]->nome,cardapio[i]->valor,cardapio[i]->numIngredientes);
        for(j=0;j<cardapio[i]->numIngredientes;j++)
            printf("  ->%s\n",cardapio[i]->ingredientes[j]);

        printf("\n_____________________\n");
    }
}
int main()
{
    
    printf("Criar o cardapio do restaurante. Quantos pratos?\n");
    int n;
    scanf("%d%*c",&n);
    PRATO **cardapio = inicializaEstrutura(cardapio,n); // malloc devolve um ponteiro para o tipo array de PRATO
    //PRATO **cardapio = (PRATO**)malloc(n*sizeof(PRATO));
    // ponteiro para um bloco de memoria capaz de guardar n pratos
    preencheEstrutura(cardapio,n);
    imprimirCardapio(cardapio,n);
    
    return 0;
}