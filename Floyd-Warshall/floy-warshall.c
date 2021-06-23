#include <stdio.h>
#define nV 4
#define INF 999

void print(int a[][nV]);
void floy_warshall(int graph[][nV])
{
    int a[nV][nV], i, j, k;
    for (i = 0; i < nV; i++)
        for (j = 0; j < nV; j++)
            a[i][j] = graph[i][j];
    for (k = 0; k < nV; k++)
    {
        for (i = 0; i < nV; i++)
        {
            for (j = 0; j < nV; j++)
            {
                if (a[i][k] + a[k][j] < a[i][j])
                    a[i][j] = a[i][k] + a[k][j];
            }
        }
    }
    print(a);
}

void print(int a[][nV])
{
    for (int i = 0; i < nV; i++)
    {
        for (int j = 0; j < nV; j++)
        {
            if (a[i][j] == INF)
                printf("%4s", "INF");
            else
                printf("%4d", a[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int graph[nV][nV] = {{0, 3, INF, 5},
                         {2, 0, INF, 4},
                         {INF, 1, 0, INF},
                         {INF, INF, 2, 0}};
    floy_warshall(graph);
}
