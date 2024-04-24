#include <stdio.h>

#define MAX_VERTICES 100

void bfs(int graph[][MAX_VERTICES], int vertices, int start);

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

    bfs(graph, vertices, start);

    return 0;
}

void bfs(int graph[][MAX_VERTICES], int vertices, int start) {
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
}
