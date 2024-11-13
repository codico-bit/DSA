#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 100
#define INF INT_MAX

int vertices;
int dist[MAX];
int parent[MAX];

// Structure to represent edges (needed for Bellman-Ford)
struct Edge {
    int src, dest, weight;
} edges[MAX * MAX];  // Maximum possible edges
int edge_count = 0;

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
            printf("\n%d -> %d\t\t", src, i);
            if(dist[i] == INF)
                printf("INF\t\t");
            else
                printf("%d\t\t%d", dist[i], src);
            if(dist[i] != INF)
                printPath(i);
        }
    }
    printf("\n");
}

bool bellmanFord(int src) {
    // Initialize distances
    for(int i = 0; i < vertices; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }
    dist[src] = 0;
    
    // Relax all edges |V| - 1 times
    for(int i = 1; i <= vertices - 1; i++) {
        for(int j = 0; j < edge_count; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;
            
            if(dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
            }
        }
    }
    
    // Check for negative-weight cycles
    for(int i = 0; i < edge_count; i++) {
        int u = edges[i].src;
        int v = edges[i].dest;
        int weight = edges[i].weight;
        
        if(dist[u] != INF && dist[u] + weight < dist[v]) {
            printf("Graph contains negative weight cycle\n");
            return false;
        }
    }
    
    printSolution(src);
    return true;
}

int main() {
    int e;
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter number of edges: ");
    scanf("%d", &e);
    
    printf("Enter edges and weights (format: source destination weight):\n");
    for(int i = 0; i < e; i++) {
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
        edge_count++;
    }
    
    printf("\nEnter source vertex: ");
    int source;
    scanf("%d", &source);
    
    printf("\nShortest paths from vertex %d using Bellman-Ford Algorithm:", source);
    if(bellmanFord(source)) {
        printf("No negative weight cycles found\n");
    }
    
    return 0;
} 