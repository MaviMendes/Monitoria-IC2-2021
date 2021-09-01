/*
Bibliografia:
- Linguagem C, Luís Damas, 10a edição
- Cap 8
Monitoria de IC2, 2021/2, Maria Vitória
*/
#include <stdio.h>

int main()
{
    /*
    Variáveis são armazenadas na memória, especificamente em algum endereço
    A memória RAM é um vetor de bytes consecutivos
    É na RAM que são armazenadas as variáveis que fazem parte dos nossos programas
    É na RAM que são carregados os nossos programas, jogos, processadores de texto, etc
    Cada byte da RAM ocupa uma posição de memória: varia de 0 até a totalidade de bytes da RAM do seu pc
    
    Declarar variável: indicar seu tipo e seu nome
    Referenciamos a variável pelo seu nome e não pelo seu endereço de memória
    x = 5 -> vá até a posição de memória onde está a variável x e insira o valor 5

    Ponteiro é uma variável que guarda endereços, sendo o endereço guardado pertencente a outra variável
    Pointeiro também ocupa posição na memória
    Por segurança, inicie os ponteiros criados. Se não souber para onde apontá-los, aponte para NULL
    O operador & retorna o endereço de uma variável. Por meio dele coloca-se uma carga inicial em um ponteiro.
    Ponteiro aponta para NULL: ele não aponta para nenhuma variável
    NULL represente o endereço de memória número ZERO
    Utilidade do ponteiro: permitir acessar outros objetos por meio de seu endereço

    *ponteiro --> ler o valor apontado pelo ponteiro

    Para cada tipo de dado, o compilador reserva um determinado espaço de memória
    O endeço de uma variável é sempre o menor dos endereços que ela ocupa na memória
    Sendo assim, os ponteiros para as variáveis devem ser do mesmo tipo delas, eles devem saber  quantos bytes de memória terão que considerar
    
    sizeof é um operador da linguagem C. Ele retorna o número de btes que uma variável ou um determinado tipo ocupa em uma determinada arquitetura
    ____________________________________________________________________ 

    * Ponteiros e vetores * 

    O nome de um vetor corresponde ao endereço de seu primeiro elemento: v = = &v[0]
    Logo, o nome de um vetor é um ponteiro(constante) para o seu primeiro elemento
    Ponteiro constate: o vetor não pode ser alterado durante a execução do programa
    
    _______________________________________________________________________

    *Aritmetica*

    -> Incremento: ptr + sizeof(tipo)
    ptr += 4; --> vai avançar 4*sizeof(tipo) bytes

    -> Decremento: ptr - sizeof(tipo)
    
    -> Diferença: a diferença entre dois ponteiros para elementos DO MESMO TIPO permite saber quantos elementos existem entre um 
    endereço e outro

    -> Comparacao: verificar a ordem de dois elementos num vetor por meio do valor de seus elementos
    */

   int x = 5;
   // Declaração: [tipo] *[nome ponteiro]
   int *ptr1 = &x; // colocar o endereço de x em ptr1
   // int * ptr1, int* ptr1, int *ptr1 ---> equivalente
   // Atenção: int* x,y,z; ---> apenas x é ponteiro! 

   printf("Imprimindo o valor de x: %d\n", x);
   printf("Imprimindo o valor apontado por ptr1: %d\n",*ptr1);

   // colocar 25 no valor de ptr1
   *ptr1 = 25;
   printf("Lendo o valor de x apos trocar o valor apontado por ptr1 para 25: %d\n", x);
   printf("Lendo o valor apontado por ptr1: %d\n",*ptr1);
   
   printf("Endereco de x: %p\n", &x);
   printf("Endereco de ptr1: %p\n",&ptr1);
   printf("Teste: apenas o nome do vetor: %p\n",ptr1); // valor contido no vetor: endereço de x, execute e verifique que é igual
   int vetor[5] = {1,2,3,4,5};	
   int *ptrVetor;
   ptrVetor = vetor; // ptrVetor aponta para o primeiro elemento

// ARITMÉTICA
// Incremento
   printf("vetor[0] = %d = prtVetor = %d\n",vetor[0],*ptrVetor);
   printf("sizeof(int) = %d\n",sizeof(int));

   int i  = 0;
   for(i=0;i<5;i++)
       printf(" posicao %d) %d\nendereco do vetor: %p\nlocal de memoria para onde o vetor aponta: %p\n\n",i,*ptrVetor++,&ptrVetor,ptrVetor);
   
// Decremento: exemplo -> imprimir string ao contrario

    char s[100];
    char *ptrString = s; // uma string é um vetor de caracteres

    printf("Insira uma string:\n");
    fgets(s,100,stdin);

    if(*ptrString == '\0')
        printf("String vazia");

    //imprimir na ordem normal
    printf("String na ordem normal:\n");
    while(*ptrString != '\0')
        putchar(*ptrString++);
    //imprimir ao contrario 
    ptrString--; // o último caractere era o '\0'

    printf("String na ordem inversa:\n");
    while(ptrString >= s) // enquanto ptrString for >= que &s[0] 
        putchar(*ptrString--); // imprime e depois decrementa
    
// Diferenca
// calcular o tamanho de uma string

char *ptrStart = s;
char *ptrEnd = s;

while(*ptrEnd != '\0')
    ptrEnd++;

printf("\nO tamanho da string s eh: %ld\n",(ptrEnd-ptrStart)); // inclui '\0'
    return 0;
}
