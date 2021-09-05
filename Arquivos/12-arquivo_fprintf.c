// Maria Vitoria - 2020
/*Vimos como ler e escrever em arquivos caracteres, strings e até mesmo blocos de bytes
A ling C também permite escrever uma lista formatada de variáveis em um arquivo do mesmo modo como 
fazemos na tela do computador com a função printf()
Para isso, usa-se a função fprintf()
Forma geral: printf()
printf("tipos de saida",variaveis);
Forma geral: fprintf()
fprintf(FILE *f,"tipos de saída",variáveis);
arquivo onde vai guardar , ,
arquivo, %d,x ->exemplo
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char nome[20]="Mavi";
    int id=19;
    float al=1.73;
    FILE *arq = fopen("testefprintfdados.txt","w");
    if(arq==NULL)
    {
        printf("Erro na abertura");
    }
    printf("\nUsando printf:\n");
    printf("Nome: %s \nIdade:%d \nAltura: %f\n",nome,id,al);
    printf("\nUsando fprintf:\n");
    fprintf(arq,"Nome:%s\nIdade:%d\nAltura: %f\n",nome,id,al);//print feito no arquivo
    //ver aquivo gerado
    fclose(arq);
    return 0;
}