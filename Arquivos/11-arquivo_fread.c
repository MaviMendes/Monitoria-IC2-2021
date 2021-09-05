
// Maria Vitoria - 2020
/*Para ler um bloco de bytes de um arquivo, usamos a função fread()
Forma geral:
int fread(void *buffer, int bytes,int count, FILE *fp);
Parâmetros:
buffer: ponteiro genérico para os dados --> os dados pegos do arquivos vão vir pra esse buffer
bytes: tamanho, em bytes,  de cada unidade de dados a ser lida
count: total de unidades de dados que devem ser lidas
fp: ponteiro para o arquivo
Retorno: o total de unidades de dados lidos com sucesso
Se retorno = count, significa que a leitura de dados foi bem sucedida
*/
#include <stdio.h>
#include <stdlib.h>
struct cadastro{
 char nome[30],endereco[30];
 int idade;
};
int main()
{
    FILE *arq = fopen("vetor.txt","rb");
    int i;
    if(arq==NULL)
    {
        printf("Erro na abertura");
    }
    int total_lido,v[5];//{1,2,3,4,5}
    total_lido = fread(v,sizeof(int),5,arq);//v: onde está sendo guardada a informação lida
    if(total_lido != 5)
    {
        printf("Erro na leitura do arquivo");
    }
    else
    {
        printf("v:\n");
        for(i=0;i<5;i++)
        {
            printf(" %d ",v[i]);
        }
    }
    fclose(arq);
    printf("\n\n");
    FILE *arq2 = fopen("dados.txt","rb");
    if(arq2==NULL)
    {
        printf("Erro na abertura");
    }
    char str[12];//Linguagem C
    float x;
    int v2[5];
    fread(str,sizeof(char),12,arq2);
    fread(&x,sizeof(float),1,arq2);
    fread(v2,sizeof(int),5,arq2);
    printf("str: %s\nx: %f\n",str,x);
    int j;
    printf("\nv2:\n");
    for(j=0;j<5;j++)
    {
        printf(" %d ",v2[j]);
    }
    fclose(arq2);
    //lendo estrutura
    FILE *arq3 = fopen("struct.txt","rb");
    if(arq3==NULL)
    {
        printf("Erro na abertura");
    }
    struct cadastro CAD;
    fread(&CAD,sizeof(struct cadastro),1,arq3);
    printf("\nNome:%s \n End:%s \n Idade: %d\n",CAD.nome,CAD.endereco,CAD.idade);
    fclose(arq3);
/*se fosse um vetor de struc, CAD[teria o tamanho aqui] e não precisaria ser passado como &CAD e em vez de "1" teria o tamanho de CAD*/
    return 0;
    
}