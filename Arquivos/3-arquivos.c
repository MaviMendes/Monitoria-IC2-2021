// Maria Vitoria - 2020
/*Abertura e fechamento de arquivo
Função fopen(): permite ABRIR um arquivo em um determinado modo de leitura ou escrita
Forma geral:
FILE *fopen(char *nome, char *modo) --> nome/endereço, modo: leitura/escrita, retorna um ponteiro do tipo FILE*
Exemplo:
FILE *f;
f = fopen("arquivo.txt","w"); "w" --> escrita
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *f;
    f=fopen("H:\arquivo.txt","w");
    if(f==NULL)
    {
        printf("Erro na abertura");
    }
    return 0;
}
/*Se a função fopen() não conseguir abrir o arquivo, ela irá retornar NULL
Obs: no devc esse código rodou, no vs code não
Para o "nome" do arquivo, podemos usar caminho
-absolutp(endreço completo) -> desde a raiz
-relativo: (relativo a pasta do programa)
EXEMPLO:
Caminho absoluto
f = fopen("C:\\Porjetos\\arquivo.txt","w");
Caminho relativo
f = fopen("arquivo.txt","w"); <-- esse arquivo só pode ser acessado se o programa estiver rodando na mesma pasta
f=fopen("..\\Novo\\arq2.txt","w"); <-- 2 pontos ".." voltar uma pasta, entra na pasta "novo" e acessa o arquivo --> caminho relativo a partir de aonde está
O modo de abertura determina que tipo de uso será feito do arquivo
FILE *f;
Leitura de arquivo de texto
f=fopen("arquivo.txt","r");
Escrita de arquivo de texto
f=fopen("arquivo.txt","w");
Leitura de arquivo binário
f=fopen("arquivo.txt","rb");
Escrita de arquivo binário
f=fopen("arquivo.txt","wb");
r ou rb: o arquivo deve existir
w ou wb: cria arquivo se não houver, apaga anterior se existir
a ou ab: os dados serão adicionados no fim do arquivo("append")
Sempre que terminados de usar um arquivo, precisamos FECHÁ-LO. Para isso, usa-se
a função fclose()
Forma geral:
int fclose(FILE *f);
fclose() retorna zero no caso de sucesso no fechamento do arquivo
Exemplo:
FILE *f;
f=fopen("C:\\arquivo.txt","w");
if(f==NULL)
{
    printf("Erro na abertura");
}
fclose(); --> fechar o arquivo garante que todos os dados foram realmente gravados

*/