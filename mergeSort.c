#include <stdio.h>
#include <math.h>

int* Intercalar(int v[], int a, int m, int b)
{
	if(a >= b) return v;
	
	int i = a;
	int j = m + 1;
	int u[b - a + 1];

	for(int k = 0; k <= b - a; k++)
	{
		if(j > b || (i <= m && v[i] <= v[j]))
		{
			u[k] = v[i];
			i++;
		}
		
		else
		{
			u[k] = v[j];
			j++;
		}
	}

	for(int l = 0; l <= b - a; l++)
		v[a + l] = u[l];

	return v;
}

int* mergeSort(int v[], int a, int b)
{
	if(a >= b) return v;

	int m = floor((a+b)/2);

	mergeSort(v, a, m);
	mergeSort(v, m + 1, b);

	return Intercalar(v, a, m, b);
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

	mergeSort(v, 0, n - 1);

	for(int i = 0; i < n; i++) printf("%d ", v[i]);

	printf("\n");

	return 0;
}












