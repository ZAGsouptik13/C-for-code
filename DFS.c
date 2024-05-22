#include <stdio.h>
#include <stdlib.h>

void dfs(int **graph, int vertices, int start) {
    int *visited = (int *)calloc(vertices, sizeof(int));
    int *stack = (int *)malloc(vertices * sizeof(int));
    int top = -1;

    stack[++top] = start;
    visited[start] = 1;

    while (top >= 0) {
        int current = stack[top--];
        printf("%d ", current);

        for (int i = vertices - 1; i >= 0; i--) {
            if (graph[current][i] && !visited[i]) {
                stack[++top] = i;
                visited[i] = 1;
            }
        }
    }

    free(visited);
    free(stack);
}

int main() {
    int vertices, start;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    int **graph = (int **)malloc(vertices * sizeof(int *));
    for (int i = 0; i < vertices; i++) {
        graph[i] = (int *)malloc(vertices * sizeof(int));
    }

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the start vertex: ");
    scanf("%d", &start);

    printf("DFS starting from vertex %d:\n", start);
    dfs(graph, vertices, start);

    for (int i = 0; i < vertices; i++) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}
