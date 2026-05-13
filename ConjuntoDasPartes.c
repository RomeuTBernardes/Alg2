#include <stdio.h>

void _bin(int v[], int conj[], int i, int n)
{
    if(i == n)
    {
        for(int j = 0; j < n; j++) 
        {
           if(v[j]) printf("%d ", conj[j]); 
        }
        
        printf("\n");
        return;
    }

    v[i] = 0;
    _bin(v, conj, i+1, n);
    v[i] = 1;
    _bin(v, conj, i+1, n);
}

void ConjuntoDasPartes(int conj[], int n)
{
    int v[50];
    _bin(v, conj, 0, n);
}

void main()
{
    printf("tamanho do vetor: ");
    int n;
    scanf("%d", &n);
    int conjunto[50];
    for(int i = 0; i < n; i++) scanf("%d", &conjunto[i]);
    ConjuntoDasPartes(conjunto, n);
}
