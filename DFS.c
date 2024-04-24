#include <stdio.h>

#define MAX_VERTICES 100

void dfs(int graph[][MAX_VERTICES], int vertices, int start);

int main() {
    int vertices, edges;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &vertices, &edges);

    int graph[MAX_VERTICES][MAX_VERTICES] = {0};

    printf("Enter the edges (source destination): \n");
    for (int i = 0; i < edges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        graph[src][dest] = 1;
        graph[dest][src] = 1; // For undirected graph
    }

    int start;
    printf("Enter the start vertex: ");
    scanf("%d", &start);

    dfs(graph, vertices, start);

    return 0;
}

void dfs(int graph[][MAX_VERTICES], int vertices, int start) {
    int visited[MAX_VERTICES] = {0};
    int stack[MAX_VERTICES], top = -1;

    stack[++top] = start;

    while (top >= 0) {
        int current = stack[top--];
        if (!visited[current]) {
            visited[current] = 1;
            printf("%d ", current);

            for (int i = vertices - 1; i >= 0; i--) {
                if (graph[current][i] && !visited[i]) {
                    stack[++top] = i;
                }
            }
        }
    }
}
