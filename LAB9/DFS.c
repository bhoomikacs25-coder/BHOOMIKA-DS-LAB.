#include <stdio.h>

#define MAX 10

int visited[MAX];
int adj[MAX][MAX];
int n;

/* DFS function */
void DFS(int v)
{
    int i;
    visited[v] = 1;
    printf("%d ", v);

    for (i = 0; i < n; i++)
    {
        if (adj[v][i] == 1 && !visited[i])
        {
            DFS(i);
        }
    }
}

int main()
{
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    /* Initialize visited array */
    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("DFS Traversal starting from vertex 0:\n");
    DFS(0);

    return 0;
}
