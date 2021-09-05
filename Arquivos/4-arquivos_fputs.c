// Maria Vitoria - 2020

/*Como gravar algo dentro de um arquivo
Vamos começar pela função fputc()
Forma geral:
int fputc(char c, FILE *fp);
retorna:
-a constante EOF(em caso de erro)
-o prórpio caractere, em caso de sucesso

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    FILE *f;
    f=fopen("arquivo.txt","w");
    if(f==NULL)
    {
        printf("Erro na abertura");
    }
    char texto[20]="Meu programa em C";
    int i;
    //grava a string caractere a caractere
    for(i=0;i<strlen(texto);i++)
    {
        fputc(texto[i],f);
        fputc(' ',f);//podemos combinar funções fputc
    }
    fclose(f);//importante fechar o arquivo
    return 0;
}