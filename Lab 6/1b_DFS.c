#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int adj[MAX][MAX];
int vertices;
bool visited[MAX];
int path[MAX], pathLen;

void DFS_Display(int vertex) {
    visited[vertex] = true;
    printf("%d ", vertex);
    
    for(int i = 0; i < vertices; i++) {
        if(adj[vertex][i] && !visited[i]) {
            DFS_Display(i);
        }
    }
}

void DFS_Search(int vertex, int key) {
    visited[vertex] = true;
    path[pathLen++] = vertex;
    
    if(vertex == key) {
        printf("Path found: ");
        for(int i = 0; i < pathLen; i++) {
            printf("%d ", path[i]);
        }
        printf("\n");
        return;
    }
    
    for(int i = 0; i < vertices; i++) {
        if(adj[vertex][i] && !visited[i]) {
            DFS_Search(i, key);
        }
    }
    pathLen--;
}

bool DFS_Connect() {
    for(int i = 0; i < vertices; i++) {
        visited[i] = false;
    }
    
    DFS_Display(0);
    
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
        }
    }
    
    printf("Enter edges (format: vertex1 vertex2):\n");
    for(int i = 0; i < edges; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        adj[v1][v2] = adj[v2][v1] = 1;
    }
    
    // Operations
    printf("\nDFS Traversal:\n");
    for(int i = 0; i < vertices; i++) visited[i] = false;
    DFS_Display(0);
    printf("\n");
    
    printf("\nEnter vertex to search: ");
    int key;
    scanf("%d", &key);
    for(int i = 0; i < vertices; i++) visited[i] = false;
    pathLen = 0;
    DFS_Search(0, key);
    
    printf("\nChecking if graph is connected:\n");
    if(DFS_Connect()) {
        printf("Graph is connected\n");
    } else {
        printf("Graph is not connected\n");
    }
    
    return 0;
} 