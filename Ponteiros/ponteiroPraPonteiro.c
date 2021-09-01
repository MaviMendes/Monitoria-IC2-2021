/*
Bibliografia:
- Linguagem C, Luís Damas, 10a edição
- Cap 8
Monitoria de IC2, 2021/2, Maria Vitória
*/

#include <stdio.h>

int main()
{
    int x = 5;
    int *p1 = &x;
    int **p2 = &p1; // ponteiro para o ponteiro 1

    printf("Valor de x x = %d\nEndereco de x, &x = %p\n",x,&x);
    printf("Endereco de x, &x = %p = Valor de p1 = %p\nValor de x=%d = Valor apontado por p1, *p1 = %d\n",&x,p1,x,*p1);
    printf("p2 guarda o endereco de p1. p2 = &p1?(valor em p2 = endereco de p1?)\nValor de p2 = %p\nEndereco de p1, &p1 = %p\n",p2,&p1);
    printf("Endereço de p2: &p2 = %p\n",&p2);
    printf("p2 aponta para p1, e p1 contem o endereco de x, logo Valor apontado por p2, *p2 = Endereco de x, &x, que eh o valor contido em p1. Verificando:\nValor em p2, *p2 = %p\nEndereco de x, &x = %p\n",*p2,&x);
    printf("Valor apontado pelo ponteiro para o qual p2 aponta (p1), **p2 = %d = Valor de x, x = %d\n",**p2,x);
    printf("\n______________________________\n");
    
    printf("\nResumo:\n");
    printf("x = %d\n&x = %p\n",x,&x);
    printf("*p1 = %d\np1 = %p\n&p1 = %p\n",*p1,p1,&p1);
    printf("**p2 = %d\np2 = %p\n*p2 = %p\n&p2 = %p",**p2,p2,*p2,&p2);
    return 0;
}