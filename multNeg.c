#include <stdio.h>
#include <stdlib.h>

int _mult(int n, int m)
{
	if(m == 0)
		return 0;
	else if(m < 0)
		return -n + _mult(n, m + 1);
	return n + _mult(n, m - 1);
}

int mult(int n, int m)
{
	if(abs(n) < abs(m)) return _mult(m, n);
	else return _mult(n, m);
}

int main(int argc, char *argv[])
{
	if(argc < 3)
	{
		printf("Insira os valores a serem usados como argumentos.\n");
		return 1;
	}

	int res = mult(atoi(argv[1]), atoi(argv[2]));

	printf("%d\n", res);
	return 0;
}

