/*
->Utilizada qnd nao tem infos add sobre os dados a serem pesquisados
->Termina quando:
1) o elemento eh encontrado
2) todo o vetor for analisado

*/

int buscaLinear(int *v, int n, int cb)
{
    int i;
    i=0;
    while(i<n && v[i]!=cb)
    {
        i++;
    }
    return i;
}

// restante do programa a ser implementado por quem for utilizar