#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int adj[MAX][MAX];
int transpose[MAX][MAX];
int vertices;
bool visited[MAX];

void DFS(int vertex) {
    visited[vertex] = true;
    
    for(int i = 0; i < vertices; i++) {
        if(adj[vertex][i] && !visited[i]) {
            DFS(i);
        }
    }
}

void DFS_Transpose(int vertex) {
    visited[vertex] = true;
    
    for(int i = 0; i < vertices; i++) {
        if(transpose[vertex][i] && !visited[i]) {
            DFS_Transpose(i);
        }
    }
}

bool isStronglyConnected() {
    // Step 1: Do DFS from vertex 0
    for(int i = 0; i < vertices; i++) {
        visited[i] = false;
    }
    DFS(0);
    
    // Check if all vertices were visited
    for(int i = 0; i < vertices; i++) {
        if(!visited[i]) return false;
    }
    
    // Step 2: Create transpose graph
    for(int i = 0; i < vertices; i++) {
        for(int j = 0; j < vertices; j++) {
            transpose[i][j] = adj[j][i];
        }
    }
    
    // Step 3: Do DFS on transpose graph
    for(int i = 0; i < vertices; i++) {
        visited[i] = false;
    }
    DFS_Transpose(0);
    
    // Check if all vertices were visited
    for(int i = 0; i < vertices; i++) {
        if(!visited[i]) return false;
    }
    
    return true;
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
            transpose[i][j] = 0;
        }
    }
    
    printf("Enter directed edges (format: from_vertex to_vertex):\n");
    for(int i = 0; i < edges; i++) {
        int from, to;
        scanf("%d %d", &from, &to);
        adj[from][to] = 1;  // Directed edge
    }
    
    if(isStronglyConnected()) {
        printf("Graph is strongly connected\n");
    } else {
        printf("Graph is not strongly connected\n");
    }
    
    return 0;
} 