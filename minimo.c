#include <stdio.h>
#include <stdlib.h>

int min(int vet[], int posInicio, int posFim)
{
	if(posInicio == posFim)
		return posInicio;
	int posMenor = min(vet, posInicio, posFim - 1);
	if(vet[posFim] < vet[posMenor])
		posMenor = posFim;
	return posMenor;
}

int main()
{
	int tam;
	printf("Tamanho do vetor: ");
	scanf("%d", &tam);
	int v[tam];

	printf("Valores: \n");

	for(int i = 0; i < tam; i++)
		scanf("%d", &v[i]);

	int inicio;
	int fim;

	printf("Posição de início da busca: ");
	scanf("%d", &inicio);
	printf("Posição de fim da busca: ");
	scanf("%d", &fim);

	printf("Posição do menor valor: %d\n", min(v, inicio, fim));

	return 0;
}
