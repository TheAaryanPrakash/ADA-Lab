#include <stdio.h>
#define MAX 10

int visited[MAX], stack[MAX], top = -1;

void dfs(int v, int n, int graph[MAX][MAX]) {
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && !visited[i]) {
            dfs(i, n, graph);
        }
    }

    // Push to stack after visiting all neighbors
    stack[++top] = v;
}

void topologicalSort(int n, int graph[MAX][MAX]) {
    // Initialize visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Call DFS for each unvisited node
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, n, graph);
        }
    }

    // Print stack (topological order)
    printf("Topological Sort Order: ");
    while (top >= 0) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
}

void main() {
    int n, graph[MAX][MAX];

    printf("Enter the Number of Vertices: ");
    scanf("%d", &n);

    printf("Enter the Adjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    topologicalSort(n, graph);
}
