// Maria Vitoria - 2020

/*Para ler um caractere de um arquivo, usamos a função fgetc()
Forma geral:
int fgetc(FILE *fp);
Retorna:
-a constante EOF(que normalmente vale -1), em caso de erro
-em caso de sucesso, retorna o caractere lido do arquivo
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *f;
    f=fopen("arquivo.txt","r");
    if(f==NULL)
    {
        printf("Erro na abertura do arquivo");
    }
    // char c;
    // int i;
    // //lê o arquivo, um caractere por vez
    // for(i=1;i<=30;i++)
    // {
    //     c=fgetc(f);
    //     printf("%c",c);
    // }
    // printf("\nFIM dos 10 caracteres\n");
    /*Como fazer para ler todos os caracteres? Usando a constante EOF(End of file). Quando atingimos o final de um arquivo,
a função fgetc() devolve a constante EOF
*/
    printf("\nLendo todo o documento\n");
    char c2=fgetc(f);
    while(c2!=EOF)
    {
        printf("%c",c2);
        c2=fgetc(f);
    }
    fclose(f);

}
