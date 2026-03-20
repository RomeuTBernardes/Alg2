#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int buscaBinaria(int x, int vetor[], int inicio, int fim)
{
	if(inicio > fim) return -1;
	
	int m = floor((inicio + fim) / 2);
	
	if(x == vetor[m]) return m;

	if(x < vetor[m]) return buscaBinaria(x, vetor, inicio, m - 1);

	return buscaBinaria(x, vetor, m + 1, fim);
}

int main(int argc, char *argv[])
{
	if(argc < 4)
	{
		printf("poucos argumentos\n");
		return 1;
	}

	int vet[15] = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43};
	int res = buscaBinaria(atoi(argv[1]), vet, atoi(argv[2]), atoi(argv[3]));

	if(res == -1) printf("item não encontrado\n");
	else printf("item na posição: %d\n", res);

	return 0;
}

