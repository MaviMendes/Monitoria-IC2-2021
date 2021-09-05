// Maria Vitoria - 2020

/*Problema: ler um arquivo contendo um texto em minúsculo
e criar outro arquivo com o texto em maiúsculo*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> //função toupper
int main()
{
    FILE *f1,*f2;
    //1º abrir o arquivo
    f1=fopen("haikai_minusculo.txt","r");
    f2=fopen("haikai_maiusculo.txt","w");
    //2º verificar se existe
    if(f1==NULL ||f2==NULL)
    {
        printf("Erro na abertura\n");
    }
    char c = fgetc(f1);
    while(c!=EOF)
    {
        fputc(toupper(c),f2);
        c=fgetc(f1);//lê o arquivo
    }
    fclose(f1);
    fclose(f2);
    return 0;
}