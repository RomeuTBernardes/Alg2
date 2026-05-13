#include <stdio.h>

void _bin(int v[], int i, int n)
{
    if(i == n)
    {
        for(int j = 0; j < n; j++) printf("%d", v[j]);
        printf("\n");
        return;
    }

    v[i] = 0;
    _bin(v, i+1, n);
    v[i] = 1;
    _bin(v, i+1, n);
}

void bin(int n)
{
    int v[50];
    _bin(v, 0, n);
}

void main()
{
    printf("tamanho do vetor: ");
    int n;
    scanf("%d", &n);
    bin(n);
}
