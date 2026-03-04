#include <stdio.h>
#include <stdlib.h>

int mccarthy(int n)
{
	if(n > 100)
		return n - 10;
	return mccarthy(mccarthy(n + 11));
}

int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		printf("Passe o valor que será usado como argumento.\n");
		return 1;
	}

	int x = atoi(argv[1]);
	int res = mccarthy(x);
	printf("%d\n", res);
	return 0;
}
