// Maria Vitoria - 2020
/*Arquivo: coelção de bytes armazenados em um dispositivo de armazenamento secundário
-disco rídido
-cd
-dvd
Vantagens de usar arquivos:
-armazenamento durável -> você desliga o pc e os dados ainda estão no seu disco rígido
-permitem armazenar uma grande quantidade de informações
-acesso concorrente aos dados -> arquivo pode ser usado por vários programas
Cuidado: extensão do arquivo NÃO define seu tipo
o que define um arquivo é a maneira como os dados estão organizados e 
as operações usadas por um programa para processar(ler ou escrever) esse arquivo
Ao mudar a extensão, isso não muda. A extensão serve para o sistema operacional saber
qual o programa mais adequado para lidar com aquele arquivo
ARQUIVOS: biblioteca stdio.h
A linguagem C usa um tipo especial de ponteiro para manipular arquivos
Forma geral:
FILE *nome_ponteiro;
É esse ponteiro que controla o fluxo de leitura e escrita dentro de um arquivo
*/