#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*

Monitoria de IC2 - 2021
Maria Vitoria



Dados n triangulos e seus 3 lados, imprime os triangulos ordenador em ordem crescente de acordo com a sua area
1 - Nao eh necessario criar nenhuma outra estrutura de dado
2 - Pesquise algum metodo simples de ordenacao
3 - Modifique apenas a funcao dada e teste

Casos de teste:

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