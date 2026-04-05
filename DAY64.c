#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

int isEmpty() {
    return (front == -1 || front > rear);
}

void BFS(int n, int adj[MAX][MAX], int s) {
    int visited[MAX] = {0};

    enqueue(s);
    visited[s] = 1;

    while (!isEmpty()) {
        int current = dequeue();
        printf("%d ", current);

        for (int i = 0; i < n; i++) {
            if (adj[current][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int n, m, u, v, s;
    int adj[MAX][MAX] = {0};

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; 
    }

    printf("Enter source vertex: ");
    scanf("%d", &s);

    printf("BFS Traversal: ");
    BFS(n, adj, s);

    return 0;
}