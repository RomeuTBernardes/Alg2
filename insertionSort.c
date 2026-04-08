#include <stdio.h>
#include <stdlib.h>

int Busca(int x, int vetor[], int a, int b)
{
	if(a > b) return a - 1;
	if(x >= vetor[b]) return b;
	return Busca(x, vetor, a, b - 1);
}

int* Insere(int vetor[], int a, int b)
{
	int p = Busca(vetor[b], vetor, a, b - 1);
	for(int i = b; i > p + 1; i--)
	{
		int temp = vetor[i];
		vetor[i] = vetor[i - 1];
		vetor[i - 1] = temp;
	}

	return vetor;
}

int* InsertionSort(int vetor[], int posInicio, int posFim)
{
	if(posInicio >= posFim) return vetor;
	InsertionSort(vetor, posInicio, posFim - 1);
	Insere(vetor, posInicio, posFim);
	return vetor;
}

int main()
{
	int v[10] = {4, 19, 32, 1, 31, 76, 54, 90, 89, 15};
	InsertionSort(v, 0, 9);
	for(int i = 0; i < 10; i++)
	{
		printf("%d\n", v[i]);
	}

	return 0;
}

