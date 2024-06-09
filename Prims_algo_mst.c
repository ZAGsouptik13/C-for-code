#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_VERTICES 100

int minKey(int key[], bool mstSet[], int vertices) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < vertices; v++)
        if (!mstSet[v] && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

void printMST(int parent[], int graph[MAX_VERTICES][MAX_VERTICES], int vertices) {
    int t_weight=0;
    printf("Edge \tWeight\n");
    for (int i = 1; i < vertices; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]],t_weight+=graph[i][parent[i]]);

    printf("Total weight : %d", t_weight);
}

void primMST(int graph[MAX_VERTICES][MAX_VERTICES], int vertices) {
    int parent[MAX_VERTICES], key[MAX_VERTICES];
    bool mstSet[MAX_VERTICES];
    for (int i = 0; i < vertices; i++)
        key[i] = INT_MAX, mstSet[i] = false;
    key[0] = 0, parent[0] = -1;

    for (int count = 0; count < vertices - 1; count++) {
        int u = minKey(key, mstSet, vertices);
        mstSet[u] = true;
        for (int v = 0; v < vertices; v++)
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
    printMST(parent, graph, vertices);
}

int main() {
    int vertices, graph[MAX_VERTICES][MAX_VERTICES];
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            scanf("%d", &graph[i][j]);
    primMST(graph, vertices);
    return 0;
}
