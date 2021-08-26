/*
Bibliografia:
- Linguagem C, Luís Damas, 10a edição
- Cap 10
Monitoria de IC2, 2021/2, Maria Vitória
*/

#include <stdio.h>
#include <string.h>

char *Mystrcpy(char *dest, char *orig);
char *Mystrcat(char *dest, char *orig);

int main()
{
    // Formas de acessar elementos de um vetor

    char s[] = "Monitoria de IC2";
    char *ptr = s; // ptr tem como valor &s[0] endereço do primeiro elemento

    printf("Caractere na posicao 5: %c\n",s[5]);
    printf("Caractere na posicao 5: %c\n",*(ptr+5)); 
    printf("Caractere na posicao 5: %c\n",*(s+5));
    printf("Caractere na posicao 5: %c\n",ptr[5]); // endereçar ponteiros por vetores também é aceitável

    // Nome do vetor é um ponteiro para o primeiro elemento desse vetor + aritmética de ponteiros
    // vetor[n] == *(vetor +n)

    // Um vetor é alocado em posições contíguas de memória, sendo o seu nome um ponteiro para o endereço do primeiro elemento
    // Quando um vetor é passado para uma função como parâmetro, ela recebe o endereço inicial do vetor, pois passamos o nome dele
    // Assim, quando passamos um vetor para uma função, passamos um endereço. Logo, deve haver um ponteiro para recebê-lo
    // Um ponteiro não tem memória própria. Só utilizamos o endereçamento por meio de um ponteiro depois que ele está apontando para um objeto previamente existente

    // Exemplo: strcpy

    char s1[] = "Monitoria de IC2 acontece 2a e 4a as 18:30!";
    char s2[100];

    printf("s2 recebe uma copia de s1, s2 = %s\n", Mystrcpy(s2,s1));
    
     // Outro exemplo: strcat
     char s3[] = "Turma";
     char s4[] = " 3 do BCC";

     printf("Resultado de concatenar s3 e s4: %s\n",Mystrcat(s3,s4)); // copia s4 para o final de s3
    return 0;
}

char *Mystrcpy(char *dest, char *orig)
{
    /*
        dest recebe o endereço inicial de s2
        orig recebe o endereço inicial de s1
        tmp aponta para o mesmo endereço que dest
    */
    char *tmp = dest; 
    
    while(*dest++ = *orig++) // Primeiro, acontece a atribuição, depois as variáveis são incrementadas
        ;
    // dest avançou ao longo do loop, seu endereço inicial se perdeu
    // Sendo assim, é retornado o endereço guardado por tmp, que é o endereço inicial de tmp


    return tmp;
}

char *Mystrcat(char *dest, char *orig)
{
    Mystrcpy(dest+strlen(dest),orig); // endereço de dest a partir do ponto onde deve começar a concatenação, endereço inicial da string de origem
    return dest;
}