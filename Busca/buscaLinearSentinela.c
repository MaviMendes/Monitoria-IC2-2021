/*
->Simplifica a expressao booleana: menos 2 operacoes realizadas n vezes
-> introduz um elemento adicional no final do vetor
-> um elemento e sempre retornado
-> retira a necessidade de verificar se chegou no fim do vetor
*/


int buscaLinear(int *v, int n, int cb)
{
    int i;
    i=0;
    v[n]=cb;
    while(v[i]!=cb)
    {
        i++;
    }
    if(i<n)
     return i;
  else//sentinela encontrado
   return -1;
}

/*
Melhor caso: encontra na primeira posicao
1 comparacao
O(1)
Pior caso:nao acha. A busca para em a[n] -> sentinela
Compara de 0 ate n (n +1 comp)
O(n)
Caso medio: 1+n/2 -> considere vetor de distribuicao uniforme
*/