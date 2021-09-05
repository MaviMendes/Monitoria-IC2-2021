// Maria Vitoria - 2020

/*EOF(end of file) é uma constante que indica o fim do arquivo
Porém, quando manipulando dados binários, um valor inteiro igual ao valor da constante EOF pode ser lido
Para evitar esse tipo de situação, a linguagem c inclui a FUNÇÃO feof()

int feof(FILE *fp)

Essa função retorna um valor inteiro igual a ZERO se aind NÃO tiver atingido o FINAL do arquivo
Valor != 0 significa que chegou ao final do arquivo
Essa função serve para qualquer tipo de arquivo e para trabalhar com qualquer tipo de dados
fgetc e fputc é ok usar EOF
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
   FILE *f;
   f=fopen("haikai_minusculo.txt","r");
   if(f==NULL)
   {
       printf("Erro na abertura");
   }
   char c= fgetc(f);
   while(!feof(f)) //feof retorna 0 se não chegou ao final. 0 é falso, então NOT feof(f) é verdadeiro enquanto feof retornar 0, ou seja, emquanto não tiver acabado o arquivo
   {
     printf("%c",c);
     c=fgetc(f);
   }
   fclose(f);
    return 0;
}