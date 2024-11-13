#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define MAX_EDGES 10000

int parent[MAX];
int rank[MAX];
int vertices;

// Structure for edges (kept minimal for sorting)
typedef struct {
    int src, dest, weight;
} Edge;

Edge edges[MAX_EDGES];
Edge result[MAX];  // To store MST

// Find with path compression
int find(int i) {
    if(parent[i] != i)
        parent[i] = find(parent[i]);
    return parent[i];
}

// Union by rank
void unionSets(int x, int y) {
    int xroot = find(x);
    int yroot = find(y);
    
    if(rank[xroot] < rank[yroot])
        parent[xroot] = yroot;
    else if(rank[xroot] > rank[yroot])
        parent[yroot] = xroot;
    else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

// Compare function for qsort
int compareEdges(const void* a, const void* b) {
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

void kruskalMST(int edges_count) {
    // Initialize disjoint sets
    for(int i = 0; i < vertices; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
    
    // Sort edges by weight
    qsort(edges, edges_count, sizeof(Edge), compareEdges);
    
    int e = 0;  // Index for result[]
    int i = 0;  // Index for sorted edges
    int totalWeight = 0;
    
    printf("\nEdges in MST:\n");
    while(e < vertices - 1 && i < edges_count) {
        Edge next_edge = edges[i++];
        
        int x = find(next_edge.src);
        int y = find(next_edge.dest);
        
        if(x != y) {
            result[e++] = next_edge;
            unionSets(x, y);
            printf("%d -- %d == %d\n", next_edge.src, next_edge.dest, next_edge.weight);
            totalWeight += next_edge.weight;
        }
    }
    
    // Print total weight of the MST
    printf("Total MST Weight: %d\n", totalWeight);
    
    // Print the edges of the MST
    printf("Edges included in the Minimum Spanning Tree:\n");
    for (int j = 0; j < e; j++) {
        printf("%d -- %d == %d\n", result[j].src, result[j].dest, result[j].weight);
    }
}

int main() {
    int edges_count;
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter number of edges: ");
    scanf("%d", &edges_count);
    
    printf("Enter edges and weights (format: source destination weight):\n");
    for(int i = 0; i < edges_count; i++) {
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }
    
    printf("\nMinimum Spanning Tree using Kruskal's Algorithm:");
    kruskalMST(edges_count);
    
    return 0;
} 