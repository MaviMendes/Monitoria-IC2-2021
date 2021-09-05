// Maria Vitoria - 2020

/*
As funções de escrita de blocos de bytes permitem escrever dados mais complexos,
como os tipo int,float,double,array,ou mesmo um tipo definido pelo programador, como por exemplo
a STRUCT
Elas devem ser utilizadas preferencialmente com arquivos binários
Para escrever um bloco de bytes em um arquivo, usamos a função fwrite()
Forma geral:
int fwrite(void *buffer,int bytes,int count, file *fp);
Parâmetros:
-buffer: ponteiro genérico para os dados (onde na memória estao os dados que quero gravar no arquivo)
-bytes:tamanho,em bytes, de cada unidade de dado a ser gravada(ex: quero gravar um inteiro. Então bytes é o tamanho de um inteiro)
-count: total de unidades de dados que devem ser gravadas(ex: vetor de inteiros. Quero gravar inteiros, 4 bytes, e o vetor tem 10 elementos. Então bytes e count trabalham em conjunto)
-fp:o ponteiro para o arquivo
Retorno: total de unidades de dados gravadas com sucesso
Se o retorno for igual ao count, significa que você obteve sucesso na gravação do arquivo
*/
#include <stdio.h>
#include <stdlib.h>
struct cadastro{
 char nome[30],endereco[30];
 int idade;
};
int main()
{
    FILE *x;
    x = fopen("vetor.txt","wb");
    //verificação
    if(x==NULL)
    {
        printf("Erro na abertura");
    }
    int total_gravado,v[5]={1,2,3,4,5};
    //grava todo o array no arquivo(5 posições)
    //total_gravado recebe o resultado de fwrite
    //v: endereço de onde estão os dados na memória
    total_gravado=fwrite(v,sizeof(int),5,x);
    if(total_gravado != 5)
    {
        printf("Erro na escrita do arquivo");
    }
    fclose(x);
    //gravando tipos de dados diferentes
    FILE *arq2;
    arq2=fopen("dados.txt","wb");
    if(arq2==NULL)
    {
        printf("Erro na abertura");
    }
    char str[12]="Linguagem C";
    float n=5;
    int v2[5]={1,2,3,4,5};
    fwrite(str,sizeof(char),12,arq2);
    fwrite(&n,sizeof(float),1,arq2);//ENDEREÇO da variável
    fwrite(v2,sizeof(int),5,arq2);
    fclose(arq2);
    //gravando uma struct
    FILE *arq3;
    arq3 = fopen("struct.txt","wb");
    //verificação
    if(arq3==NULL)
    {
        printf("Erro na abertura");
    }
    //criar variável da estrutura e preencher
    struct cadastro cad = {"Mavi","Rua 01",19};
    //passar endereço de cad, é uma variável
    fwrite(&cad,sizeof(struct cadastro),1,arq3);
    fclose(arq3);
    return 0;
}