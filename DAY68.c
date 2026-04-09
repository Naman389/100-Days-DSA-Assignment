#include <stdio.h>

#define MAX 100

int n, adj[MAX][MAX], indegree[MAX];

int queue[MAX], front = -1, rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}

void topologicalSort() {
    int i, j, count = 0;

    for (i = 0; i < n; i++) {
        indegree[i] = 0;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (adj[i][j] == 1)
                indegree[j]++;
        }
    }

    for (i = 0; i < n; i++) {
        if (indegree[i] == 0)
            enqueue(i);
    }

    printf("Topological Order: ");

    while (front != -1 && front <= rear) {
        int node = dequeue();
        printf("%d ", node);
        count++;

        for (j = 0; j < n; j++) {
            if (adj[node][j] == 1) {
                indegree[j]--;
                if (indegree[j] == 0)
                    enqueue(j);
            }
        }
    }

    if (count != n) {
        printf("\nCycle detected! Topological sort not possible.\n");
    }
}

int main() {
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    topologicalSort();

    return 0;
}