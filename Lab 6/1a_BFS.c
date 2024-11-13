#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int adj[MAX][MAX];
int vertices;
bool visited[MAX];

void BFS_Display(int start) {
    int queue[MAX];
    int front = 0, rear = -1;
    
    printf("BFS starting from vertex %d: ", start);
    visited[start] = true;
    queue[++rear] = start;
    
    while(front <= rear) {
        int current = queue[front++];
        printf("%d ", current);
        
        for(int i = 0; i < vertices; i++) {
            if(adj[current][i] && !visited[i]) {
                visited[i] = true;
                queue[++rear] = i;
            }
        }
    }
    printf("\n");
}

void BFS_Search(int start, int key) {
    int queue[MAX], parent[MAX];
    int front = 0, rear = -1;
    bool found = false;
    
    for(int i = 0; i < vertices; i++) {
        visited[i] = false;
        parent[i] = -1;
    }
    
    visited[start] = true;
    queue[++rear] = start;
    
    while(front <= rear && !found) {
        int current = queue[front++];
        if(current == key) {
            found = true;
            break;
        }
        
        for(int i = 0; i < vertices; i++) {
            if(adj[current][i] && !visited[i]) {
                visited[i] = true;
                parent[i] = current;
                queue[++rear] = i;
            }
        }
    }
    
    if(found) {
        printf("Path to %d: ", key);
        int path[MAX], pathLen = 0;
        for(int i = key; i != -1; i = parent[i]) {
            path[pathLen++] = i;
        }
        for(int i = pathLen-1; i >= 0; i--) {
            printf("%d ", path[i]);
        }
        printf("\n");
    } else {
        printf("Key not found!\n");
    }
}

bool BFS_Connect() {
    int count = 0;
    for(int i = 0; i < vertices; i++) {
        visited[i] = false;
    }
    
    BFS_Display(0);  // This will mark all reachable vertices
    
    for(int i = 0; i < vertices; i++) {
        if(visited[i]) count++;
    }
    return count == vertices;
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
    printf("\nBFS Traversal:\n");
    for(int i = 0; i < vertices; i++) visited[i] = false;
    BFS_Display(0);
    
    printf("\nEnter vertex to search: ");
    int key;
    scanf("%d", &key);
    BFS_Search(0, key);
    
    printf("\nChecking if graph is connected:\n");
    if(BFS_Connect()) {
        printf("Graph is connected\n");
    } else {
        printf("Graph is not connected\n");
    }
    
    return 0;
} 