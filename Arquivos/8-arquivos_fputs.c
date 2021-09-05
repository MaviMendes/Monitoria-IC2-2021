// Maria Vitoria - 2020
/*fputc --> grava caractere por caractere
Para escrever uma string em um arquivo usamos a função fputs()
Forma geral:
int fputs(char *str, FILE *fp);
Retorna:
-a constante EOF, em caso de ERRO
-um valor DIFERENTE DE ZERO em caso de SUCESSO

*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *t;
    t=fopen("poeminha.txt","w");
    if(t==NULL)
    {
        printf("Erro na abertura");
    }
    char texto[]=" Roses are red \n the sky is blue \n what is it \n I don't have a clue";
    //grava toda a string de uma vez
    int retorno = fputs(texto,t);
    if(retorno==EOF)
    {
        printf("Erro na gravação");
    }
    fclose(t);
    /*fputs grava apenas a string pedida*/
    FILE *m;
    m=fopen("frase.txt","w");
    if(m==NULL)
    {
        printf("Erro na abertura");
    }
    fputs("Tem que adicionar o espaço ",m);
    fputs("     porque fputs não adiciona espaço",m);
    fclose(m);
    /*formas de evitar problema: fputs("hello\n",f)
                                fputs("world\n",f);
Outra forma seria utilizar fputc
fputs("hello",f);
fputc('\n',f);
fputs("world",f);
fclose(f);
output:
Hello
world
*/
    return 0;
}
