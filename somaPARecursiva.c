#include <stdio.h>
#include <stdlib.h>

int somaPA(int n, int a, int r)
{
	if(n == 1)
		return a;
	return somaPA(n - 1, a, r) + r * (n - 1) + a;
}

int main(int argc, char *argv[])
{
	if(argc < 4)
	{
		printf("Digite n, a e r como argumentos, respectivamente");
		return 1;
	}

	int res = somaPA(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));

	printf("%d\n", res);
}
