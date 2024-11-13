#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int adj[MAX][MAX];
int vertices;
int inDegree[MAX];
bool visited[MAX];

void topologicalSort() {
    // Calculate in-degree for each vertex
    for(int i = 0; i < vertices; i++) {
        inDegree[i] = 0;
        for(int j = 0; j < vertices; j++) {
            if(adj[j][i]) {
                inDegree[i]++;
            }
        }
    }
    
    int queue[MAX];
    int front = 0, rear = -1;
    
    // Add vertices with 0 in-degree to queue
    for(int i = 0; i < vertices; i++) {
        if(inDegree[i] == 0) {
            queue[++rear] = i;
        }
    }
    
    printf("Topological Sort Order: ");
    while(front <= rear) {
        int current = queue[front++];
        printf("%d ", current);
        
        for(int i = 0; i < vertices; i++) {
            if(adj[current][i]) {
                inDegree[i]--;
                if(inDegree[i] == 0) {
                    queue[++rear] = i;
                }
            }
        }
    }
    printf("\n");
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
    
    printf("Enter directed edges (format: from_vertex to_vertex):\n");
    for(int i = 0; i < edges; i++) {
        int from, to;
        scanf("%d %d", &from, &to);
        adj[from][to] = 1;  // Directed edge
    }
    
    topologicalSort();
    return 0;
} 