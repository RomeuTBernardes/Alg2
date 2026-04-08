#include <stdio.h>

int Minimo(int vet[], int posInicio, int posFim)
{
	if(posInicio == posFim)
		return posInicio;
	int posMenor = Minimo(vet, posInicio, posFim - 1);
	if(vet[posFim] < vet[posMenor])
		posMenor = posFim;
	return posMenor;
}

int* SelectionSort(int vetor[], int posInicio, int posFim)
{
	if(posInicio >= posFim) return vetor;
	int temp = vetor[posInicio];
	int min = Minimo(vetor, posInicio, posFim);
	vetor[posInicio] = vetor[min];
	vetor[min] = temp;
	return SelectionSort(vetor, posInicio + 1, posFim);
}

int main()
{
	int v[10] = {4, 19, 32, 1, 31, 76, 54, 90, 89, 15};

	SelectionSort(v, 0, 9);
	for(int i = 0; i < 10; i++)
	{
		printf("%d\n", v[i]);
	}
	return 0;
}
