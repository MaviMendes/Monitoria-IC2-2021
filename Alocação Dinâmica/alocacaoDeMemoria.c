/*
Bibliografia:
- Linguagem C, Luís Damas, 10a edição
- Cap 12
Monitoria de IC2, 2021/2, Maria Vitória
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    /*
        A alocação dinâmica é útil para usar apenas a quantidade necessária de memória e ter a possibilidade de liberá-la
        quando ela não for mais necessária.
        As funções relacionadas a alocação dinâmica estão disponíveis por meio de #include <stdlib.h>

        Funções: malloc (Memory Allocation) e calloc
            Sintaxe: void *malloc(size_t n_Bytes)
                size_t: typedef unsigned int size_t
            A função cria um bloco de memória de n_Bytes bytes e devolve o endereço desse bloco
            Se a alocação falhar, devolve NULL

            void* siginifica que a função retorna um ponteiro para qualquer tipo de dado, ou seja, um endereço de memória.

        free(ponteiro) --> liberar memória previamente alocada

        Sintaxe: void *calloc(size_t num, size_t size)
            Criar dinamicamente num elementos, cada um deles com dimensão size bytes
            Aloca todos os bytes com valor zero
            Devolve ponteiro para a zona de memória que foi criada ou NULL

        realloc: alterar o número de bytes que estão associados a um bloco previamente criado com malloc ou calloc
            Sintaxe: void *realloc(void *ptr, size_t new_size)
            Se o parâmetro for igual a NULL, realloc se comporta como malloc


    */

   char *str;

   str = (char*)malloc(30);

   strcpy(str,"Monitoria de IC2");
   printf("String: %s\nEndereco: %p\n",str,str);
   
   str = (char*)realloc(str,100);
   printf("Apos realocar espaco\nString: %s\nEndereco: %p\n",str,str);

   // liberar memória
   free(str);
   
   // Vamos analisar o que acontece nesse exemplo

   char s[] = "Alocacao dinamica e ponteiros";
   printf("Retorno da funcao strduo(s): %s",strdup(s));

   return 0;
}

char *strdup(char *s)
{
    char *tmp = (char*)malloc(strlen(s)+1); // por meio da função malloc, um novo bloco de memória é alocado
    // o ponteiro tmp aponta para o endereço inicial desse bloco de memória
    if(tmp != NULL)
        strcpy(tmp,s);
    return tmp; // retorna-se o endereço
}