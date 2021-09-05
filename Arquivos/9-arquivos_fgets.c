// Maria Vitoria - 2020
/*Usando fgetc, precisamos fazer um laço pra ler o arquivo, caractere por caractere
Para ler uma string de um arquivo, usamos a função fgets()
Forma geral:
char* fgets(char *str,int tamanho,FILE *fp);
str: string que vai ler, onde vai ser amrz a string lida; tamanho: tamanho max da string ou quantos caracteres vai ler
o que é lido de fato: tamanho-1 . Tamanho de uma string[n] = n-1, p último é o \0
char* -> retorna um ponteiro pra char
Retorna:
NULL -> em caso de erro
Um ponteiro para o primeiro caractere de str -> caso de sucesso

*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char str[100];
    FILE *arq;
    arq=fopen("haikai_maiusculo.txt","r");
    if(arq==NULL)
    {
        printf("Erro na abertura");
    }
    char *read=fgets(str,30,arq);//vai ler 29
    if(read==NULL)
    {
        printf("Erro na leitura");
    }
    else
    {
        printf("%s",str);
    }
    fclose(arq);
    /*A função fgets() lê uma string até encontrar um caractere de nova linha (\n)
    ou "tamanho"-1 caracteres*/
    char str2[20];
    FILE *arq2;
    arq2=fopen("hello.txt","r");
    if(arq2==NULL)
    {
        printf("Erro na abertura");
    }
    char *read2 =fgets(str2,20,arq2);
    if(read2==NULL)
    {
        printf("Erro");
    }
    else
    {
        printf("%s",str2);
    }
    fclose(arq2);
    
    return 0;
}