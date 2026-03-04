// este código reliza uma potência, de uma forma otimizada 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int potencia(int a, int b)
{
	if(b == 0)
		return 1;
	if(b % 2 == 0)
		return potencia(a*a, floor(b/2));
	return potencia(a*a, floor(b/2)) * a;
}

int main(int argc, char *argv[])
{
	if(argc < 3)
	{
		printf("Insira os valores a serem usados como argumentos.\n");
		return 1;
	}

	int x = atoi(argv[1]);
	int y = atoi(argv[2]);
	
	int res = potencia(x, y);
	
	printf("%d\n", res);
	return 0;
}

