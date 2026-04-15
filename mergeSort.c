#include <stdio.h>
#include <math.h>

int* Intercalar(int v[], int a, int m, int b)
{
	if(a >= b) return v;
	
	int i = a;
	int j = m + 1;
	int u[b - a + 1];

	for(int k = 0; k <= b - a; k++)
	{
		if(j > b || (i <= m && v[i] <= v[j]))
		{
			u[k] = v[i];
			i++;
		}
		
		else
		{
			u[k] = v[j];
			j++;
		}
	}

	for(int l = 0; l <= b - a; l++)
		v[a + l] = u[l];

	return v;
}

int* mergeSort(int v[], int a, int b)
{
	if(a >= b) return v;

	int m = floor((a+b)/2);

	mergeSort(v, a, m);
	mergeSort(v, m + 1, b);

	return Intercalar(v, a, m, b);
}

int main()
{
	int v[10] = {4, 19, 32, 1, 31, 76, 54, 90, 89, 15};

	mergeSort(v, 0, 9);

	for(int i = 0; i < 10; i++)
		printf("%d\n", v[i]);

	return 0;
}












