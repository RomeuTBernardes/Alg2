#include <stdio.h>

void maxheapfy(int *v, int i, int n)
{
	int esq = i * 2 + 1;
	int dir = i * 2 + 2;
	int maior;
	int temp;

	if(esq <= n && v[esq] > v[i]) maior = esq;
	else maior = i;
	
	if(dir <= n && v[dir] > v[maior]) maior = dir;

	if(maior != i)
	{
		temp = v[i];
		v[i] = v[maior];
		v[maior] = temp;
		maxheapfy(v, maior, n);
	}
}

void construirHeap(int *v, int n)
{
	for(int i = n/2 + 1; i >= 0; i--) maxheapfy(v, i, n);
}

void heapSort(int *v, int n)
{
	int temp;
	construirHeap(v, n);
	for(int i = n; i >= 1; i--)
	{
		temp = v[0];
		v[0] = v[i];
		v[i] = temp;
		maxheapfy(v, 0, i - 1);
	}
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

	heapSort(v, n - 1);

	for(int i = 0; i < n; i++) printf("%d ", v[i]);
	printf("\n");

	return 0;
}
