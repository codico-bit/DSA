#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

int adj[MAX][MAX];
int vertices;
bool mstSet[MAX];
int parent[MAX];
int key[MAX];

int findMinKey() {
    int min = INF, min_index;
    
    for(int v = 0; v < vertices; v++) {
        if(!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void printMST() {
    int totalWeight = 0;
    printf("\nEdge \tWeight\n");
    for(int i = 1; i < vertices; i++) {
        printf("%d - %d \t%d\n", parent[i], i, adj[i][parent[i]]);
        totalWeight += adj[i][parent[i]];
    }
    printf("Total MST Weight: %d\n", totalWeight);
}

void primMST() {
    // Initialize all keys as infinite
    for(int i = 0; i < vertices; i++) {
        key[i] = INF;
        mstSet[i] = false;
    }
    
    key[0] = 0;
    parent[0] = -1;
    
    for(int count = 0; count < vertices - 1; count++) {
        int u = findMinKey();
        mstSet[u] = true;
        
        for(int v = 0; v < vertices; v++) {
            if(adj[u][v] && !mstSet[v] && adj[u][v] < key[v]) {
                parent[v] = u;
                key[v] = adj[u][v];
            }
        }
    }
    
    printMST();
}

int main() {
    int edges;
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    
    // Initialize adjacency matrix
    for(int i = 0; i < vertices; i++) {
        for(int j = 0; j < vertices; j++) {
            adj[i][j] = 0;
        }
    }
    
    printf("Enter edges and weights (format: vertex1 vertex2 weight):\n");
    for(int i = 0; i < edges; i++) {
        int v1, v2, weight;
        scanf("%d %d %d", &v1, &v2, &weight);
        adj[v1][v2] = adj[v2][v1] = weight;
    }
    
    printf("\nMinimum Spanning Tree using Prim's Algorithm:");
    primMST();
    
    return 0;
} 