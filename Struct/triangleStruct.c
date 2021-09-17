#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*

Monitoria de IC2 - 2021
Maria Vitoria



Dados n triangulos e seus 3 lados, imprime os triangulos ordenados em ordem crescente de acordo com a sua area
1 - Nao eh necessario criar nenhuma outra estrutura de dado
2 - Pesquise algum metodo simples de ordenacao
3 - Modifique apenas a funcao dada e teste
4 - Pesquise uma função para calcular a área de um triângulo que seja conveniente para esse problema

Casos de teste:
3
7 24 25
5 12 13
3 4 5

5
5 6 8
2 3 4
8 15 17
10 15 10
4 6 9


*/

struct triangulo
{
	int a;
	int b;
	int c;
};

typedef struct triangulo triangulo;

/*
* Adicione outros metodos aqui, se necessario
*/

void ordenarPelaArea(triangulo* tr, int n) {
	/**
	* Ordene os triangulos de tr de acordo com a area
	*/

    // Adicione sua solucao aqui
    
}

int main()
{
	int n;
	scanf("%d", &n);
	triangulo *tr = malloc(n * sizeof(triangulo));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	ordenarPelaArea(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}