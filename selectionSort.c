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

	SelectionSort(v, 0, n - 1);
	
	for(int i = 0; i < n; i++) printf("%d ", v[i]);

	printf("\n");

	return 0;
}
