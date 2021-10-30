/*
Se as chaves estiverem ordenadas, eh possivel usar busca binaria
Chave de busca:
1)igual a chave do  vetor/registro
->fim da busca
2)maior que  a chave do  vetor/registro
-> ignorar elementos com indice menor ou igual ao indice do registro em questao
olhar elementos adiante
3)menor que a chave do  vetor/registro
ignorar elementos de indice maior ou igual ao do registro em questao
olhar elementos antes
Solucao otima: eliminar o maior numero possivel de elementos em futuras buscas.
Escolher um elemento do meio ou proximo do meio
IMPORTANTE
Se, ao terminar o loop, a condicao a[R] = x for satisfeita, entao o elemento procurado por encontrado na posicao R
Caso contrario, ele nao foi encontrado
*/

int buscaBinariaRecursiva(int *v,int cb, int menor, int maior)//menor =0, maior = n-1
{
    int meio;
    if(menor>maior)
     return -1;
    meio = (maior+menor)/2;
    if(v[meio]==cb)
     return meio;
    else
    {
        if(v[meio]>cb)
            buscaBinariaRecursiva(v,cb,menor,meio-1);
        else
            buscaBinariaRecursiva(v,cb,meio+1,maior);
        
    }
    
}

int buscaBinaria(int *v, int n, int cb)
{
    int L = 0;
    int R = n-1;
    int m;
    int sucesso = 0;

    while((L<=R) && (sucesso==0))
    {
        m = (R+L)/2;
        if(v[m]==cb)
        {
            sucesso =1;
            return m;
        }
        else 
        {
            if(v[m]<cb)
                L = m +1;
            else 
                R = m - 1;
        }
    }
    return -1;
}
/*
Se (L<=R) nao for testado sempre no loop, a eficiencia pode ser ligeiramente melhorada
Pode-se abandonar a meta de terminar a busca no instante exato em que o elemento procurado for encontrado
O ganho em eficiencia em cada passo sera maior do que a perda ocasionada pela comparacao de alguns poucos elementos adicionais

*/

int buscaBinariaRapida(int *v, int n, int cb)
{
    int L=0;
    int R = n-1;
    int m;
    while(L<R)
    {
        m = (R+L)/2;

        if(v[m]<cb)
            L = m+1;
        
        else 
            R = m;
    }

    if(v[R]==cb)//chegou a L = R
      return R;
    else
        return -1;
    
}

// restante do programa a ser implementado por quem for utilizar