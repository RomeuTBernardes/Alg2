#include <stdio.h>
#include <stdbool.h>

#define N 5 // tamanho do tabuleiro

bool ehSeguro(int x, int y, int m[N][N]) 
{
    return (x >= 0 && x < N && y >= 0 && y < N && m[x][y] == -1); 
}

int cUtil(int x, int y, int movei, int m[N][N], int xMove[], int yMove[])
{
    if(movei == N * N) return 1;
    for(int k = 0; k < 8; k++)
    {
        int proxX = x + xMove[k];
        int proxY = y + yMove[k];
        if(ehSeguro(proxX, proxY, m))
        {
            m[proxX][proxY] = movei;
            if(cUtil(proxX, proxY, movei + 1, m, xMove, yMove) == 1) return 1;
            m[proxX][proxY] = -1;
        }
    }

    return 0;
}

void main()
{
    int xMove[8] = {2, 1, -1, -2, -2, -1, 1, 2}; 
    int yMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    int m[N][N];
    
    for(int x = 0; x < N; x++)
        for(int y = 0; y < N; y++)
            m[x][y] = -1; // -1 é uma posição ainda não percorrida
    
    m[0][0] = 0;

    if(cUtil(0, 0, 1, m, xMove, yMove) == 1)
    {
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
                printf("%d ", m[i][j]);
            printf("\n");
        }
    }

    else printf("sem solução!\n");
}
