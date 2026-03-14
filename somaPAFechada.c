#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if(argc < 4)
	{
		printf("Digite n, a e r como argumentos, respectivamente");
		return 1;
	}

	int n = atoi(argv[1]);
	int a = atoi(argv[2]);
	int r = atoi(argv[3]);

	int res = r * ((n * n - n) / 2) + a * n;

	printf("%d\n", res);
}
