// Maria Vitoria - 2020

/*scanf: usada para ler uma lista de variáveis formatadas, vindas do teclado
A linguagem C permite ler uma lista formatada de variáveis do arquivo do mesmo modo
como fazemos do teclado do computador com a função scanf()
Para isso, usamos a função fscanf()
fscanf() --> ler uma lista formatada, só que do arquivo
Forma geral: scanf()
scanf("tipos de entrada",variaveis);
Forma geral: fscanf()
fscanf(FILE *f,"tipos de entrada",variaveis);
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
   FILE *f = fopen("testefprintfdados.txt","r");
   if(f==NULL)
   {
       printf("Erro na abertura");
   }
   char texto[20],nome[20];
   int id;
   float h;
   fscanf(f,"%s %s",texto,nome);
   printf("\ntexto:\" %s\" nome:\"%s\"\n",texto,nome);
   fscanf(f,"%s %d",texto,&id);
   printf("\ntexto:\" %s\"  id: \"%d\"\n",texto,id);
   fscanf(f,"%s %f",texto,&h);
   printf("\ntexto:\" %s\"  h: \"%f\"\n",texto,h);
   fclose(f);
    return 0;
}