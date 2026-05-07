#include <stdio.h>

int particiona(int *v, int a, int b, int x)
{
        int temp;
        int m = a - 1;
        for(int i = a; i <= b; i++)
        {
                if(v[i] <= x)
                {
                        m++;
                        temp = v[m];
                        v[m] = v[i];
                        v[i] = temp;
                }
        }
        return m;
}

int* quickSort(int *v, int a, int b)
{
        if(a >= b) return v;
        int m = particiona(v, a, b, v[b]);
        quickSort(v, a, m - 1);
        quickSort(v, m + 1, b);
}

int main()
{
        int v[50];
	int n;
	printf("tamanho do vetor: ");
	scanf("%d", &n);

	if(n > 50)
	{
		printf("TAMANHO MÁXIMO 50!\n");
		return 1;
	}

	for(int i = 0; i < n; i++) scanf("%d", &v[i]);

        quickSort(v, 0, n - 1);
        for(int i = 0; i < n; i++) printf("%d ", v[i]);
        printf("\n");
}
