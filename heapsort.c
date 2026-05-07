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

void main()
{
	int v[7] = {4, 19, 32, 1, 31, 76, 54};
	heapSort(v, 6);

	for(int i = 0; i < 7; i++) printf("%d ", v[i]);
	printf("\n");
}
