#include <stdio.h>

int particiona(int *v, int a, int b, int x)
{
        int temp;
        int m = a - 1;
        for(int i = a; i <= b; i++)
        {
                if(v[i] <= x)
                {
                        m++;
                        temp = v[m];
                        v[m] = v[i];
                        v[i] = temp;
                }
        }
        return m;
}

int* quickSort(int *v, int a, int b)
{
        if(a >= b) return v;
        int m = particiona(v, a, b, v[b]);
        quickSort(v, a, m - 1);
        quickSort(v, m + 1, b);
}

void main()
{
        int v[10] = {4, 19, 32, 1, 31, 76, 54, 90, 89, 15};
        quickSort(v, 0, 9);
        for(int i = 0; i < 10; i++) printf("%d ", v[i]);
        printf("\n");
}
