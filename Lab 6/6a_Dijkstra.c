#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

int adj[MAX][MAX];
int vertices;
int dist[MAX];
bool sptSet[MAX];
int parent[MAX];

int minDistance() {
    int min = INF, min_index;
    
    for(int v = 0; v < vertices; v++) {
        if(!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void printPath(int j) {
    if(parent[j] == -1)
        return;
    
    printPath(parent[j]);
    printf(" -> %d", j);
}

void printSolution(int src) {
    printf("\nVertex\t\tDistance\tPath");
    for(int i = 0; i < vertices; i++) {
        if(i != src) {
            printf("\n%d -> %d\t\t%d\t\t%d", src, i, dist[i], src);
            printPath(i);
        }
    }
    printf("\n");
}

void dijkstra(int src) {
    // Initialize distances and sets
    for(int i = 0; i < vertices; i++) {
        dist[i] = INF;
        sptSet[i] = false;
        parent[i] = -1;
    }
    
    dist[src] = 0;
    
    for(int count = 0; count < vertices - 1; count++) {
        int u = minDistance();
        sptSet[u] = true;
        
        for(int v = 0; v < vertices; v++) {
            if(!sptSet[v] && adj[u][v] && 
               dist[u] != INF && 
               dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
                parent[v] = u;
            }
        }
    }
    
    printSolution(src);
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
    
    printf("Enter edges and weights (format: source destination weight):\n");
    for(int i = 0; i < edges; i++) {
        int src, dest, weight;
        scanf("%d %d %d", &src, &dest, &weight);
        adj[src][dest] = weight;
        adj[dest][src] = weight;  // For undirected graph
    }
    
    printf("\nEnter source vertex: ");
    int source;
    scanf("%d", &source);
    
    printf("\nShortest paths from vertex %d using Dijkstra's Algorithm:", source);
    dijkstra(source);
    
    return 0;
} 