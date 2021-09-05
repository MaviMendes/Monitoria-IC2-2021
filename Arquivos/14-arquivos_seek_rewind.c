// Maria Vitoria - 2020

/*
https://www.youtube.com/watch?v=cdXGEy-6jMU&list=PL8iN9FQ7_jt4DJbeQqv--jpTy-2gTA3Cp&index=79
Em geral, o acesso a um arquivo tende a ser feito de forma sequencial
Mas a linguagem C permite realizar operações de leitura e escrita randômica usando a função fseek()
randomica -> pular certos dados pra ler outros
Forma geral:
int fseek(FILE *fp,long numbytes,int origem)
*fp: arquivo
origem: vou pular tantos bytes dependendo de onde estou, do inicio do arquivo, do final do arquivo
parâmetros:
fp: o ponteiro para o arquivo
numbytes: é o total de bytes a ser pulado a partir de "origem"
origem: a partir de onde "numbytes" serão contados
Retorno: ZERO em caso de sucesso
obs: valores negativos de bytes indicam voltar posições no arquivo
Os valores possíveis para o parâmetro "origem" são definidos por constante na biblioteca stdio.h, e são:

Constante       | Valor| Significado
______________________________________
SEEK_SET            0     Início do arquivo
SEEK_CUR            1     Ponto atual do arquivo
SEEK_END            2     Fim do arquivo

*/
#include <stdio.h>
#include <stdlib.h>
struct cadastro{
    char nome[20],rua[20];
    int idade;
};
int main()
{
    /*cria estrutura e grava os dados dela num arquivo. Depois, será feita a leitura de modo randômico*/
    FILE *f = fopen("umarquivo.txt","wb");//melhor trabalhar com arquivo binário quando lidando com leitura randômica
    if(f==NULL)
    {
        printf("Erro na abertura");
    }
    struct cadastro cad[4] = {"Maria","Rua 1",19,
                              "Vitória","Rua 2",20,
                              "Ribeiro","Rua 3",21,
                              "Mendes","Rua 4",22};
    fwrite(cad,sizeof(struct cadastro),4,f);
    fclose(f);
    //leitura  abriu o arq, ta na primeira posição
    FILE *f2 = fopen("umarquivo.txt","rb");//melhor trabalhar com arquivo binário quando lidando com leitura randômica
    if(f2==NULL)
    {
        printf("Erro na abertura");
    }
    struct cadastro c;
    fseek(f2,2*sizeof(struct cadastro),SEEK_SET); //2*sizeof... ou seja, pular 2x o tamanho
    /*
    [ ] ->inicio, estava aqui. Pula esse
    [ ] -> pula esse
    [ ] -> vai ler isso
    [ ]
    */
    fread(&c,sizeof(struct cadastro),1,f2);
    printf("\n Nome: %s \n Rua: %s \n Idade: %d\n",c.nome,c.rua,c.idade);
    //rewind
    rewind(f2);
    printf("\nAPOS REWIND:\n");
    fread(&c,sizeof(struct cadastro),1,f2);
    printf("\n Nome: %s \n Rua: %s \n Idade: %d\n",c.nome,c.rua,c.idade);
    fclose(f2);
    /*Outra opção de movimentação dentro do arquivo é simplesmente retornar para o seu início usando a função rewind()
    Forma geral:
    void rewind(FILE *fp);
    */
}