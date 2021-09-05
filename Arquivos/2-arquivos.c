// Maria Vitoria - 2020
/*
Fonte: https://www.youtube.com/watch?v=ueg-IE8cZH4&list=PL8iN9FQ7_jt4DJbeQqv--jpTy-2gTA3Cp&index=67
A linguagem c trabalha apenas com dois tipos de arquivos:
-arquivos texto: podem ser editados no bloco de notas
-arquivos binários: NÃO podem ser editados no bloco de notas
ARQUIVOS TEXTO:
-os dados são gravados exatamento como seriam impressos na tela
-os dados são gravados como caracteres de 8 bits utilizando a tabela ASCII
-para isso, existe a etapa de "conversão" dos dados
Problemas com a conversão:
-arquivos maiores
-leitura e escrita lentas
Considere um número inteiro com 8 dígitos
int n = 12345678; --> 32 bits na memória
Num arquivo de texto, cada dígito será convertido para seu caractere ASCII,ou seja, 8 bits por dígito
"12345678" --> 64 bits no arquivo
ARQUIVO BINÁRIO
-os dados são gravados exatamente como estão organizados na memória do computador
-não existe etapa de "conversão" dos dados
Consequência:
-arquivos em geral menores
-leitura e escrita mais rápidas
Voltando ao número inteiro com 8 dígitos:
int n = 12345678; --> 32 bits na memória
Num arquivo binário, o conteúdo da memória será copiado diretamente para o arquivo, SEM CONVERSÃO
12345678 --> 32 bits no arquivo(codificado), não será possível ler ele assim
Para entender melhor a diferença entre esses dois arquivos, imagine os seguintes dados a serem gravados:
char nome[20]="Mavi";
int i = 30;
float a = 1.74;
No arquivo de texto, os dados ficam como estão
No arquivo binário, o texto fica como está, mas os números não são representados como o original
*/