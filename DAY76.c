#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node* adjLists[MAX];
};

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    for (int i = 1; i <= vertices; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void DFS(struct Graph* graph, int v, int visited[]) {
    visited[v] = 1;

    struct Node* temp = graph->adjLists[v];
    while (temp) {
        if (!visited[temp->vertex])
            DFS(graph, temp->vertex, visited);
        temp = temp->next;
    }
}

int countComponents(struct Graph* graph) {
    int visited[MAX] = {0};
    int count = 0;

    for (int i = 1; i <= graph->numVertices; i++) {
        if (!visited[i]) {
            DFS(graph, i, visited);
            count++;
        }
    }
    return count;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Graph* graph = createGraph(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    printf("%d\n", countComponents(graph));

    return 0;
}