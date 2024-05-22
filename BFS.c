#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

void bfs(int **graph, int vertices, int start);

int main() {
    int vertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    // Dynamically allocate memory for the adjacency matrix
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

    int start;
    printf("Enter the start vertex: ");
    scanf("%d", &start);

    printf("BFS starting from vertex %d:\n", start);
    bfs(graph, vertices, start);

    // Free the allocated memory
    for (int i = 0; i < vertices; i++) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}

void bfs(int **graph, int vertices, int start) {
    int visited[MAX_VERTICES] = {0};
    int queue[MAX_VERTICES], front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        for (int i = 0; i < vertices; i++) {
            if (graph[current][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}
