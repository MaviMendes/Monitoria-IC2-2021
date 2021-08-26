/*
Bibliografia:
- Linguagem C, Luís Damas, 10a edição
- Cap 10
Monitoria de IC2, 2021/2, Maria Vitória
*/

#include <stdio.h>

int main()
{
    int x = 5;
    int *p1 = &x;
    int **p2 = &p1; // ponteiro para o ponteiro 1

    printf("x = %d\np1 = %ld\n*p1 = %d\n",x,p1,*p1);
    printf("p2 = %ld\n*p2 = %ld\n**p2 = %d",p2,*p2,**p2);
    return 0;
}