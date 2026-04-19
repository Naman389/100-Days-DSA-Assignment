#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 1000

// Structure for adjacency list
typedef struct Node {
    int vertex, weight;
    struct Node* next;
} Node;

Node* adj[MAX];

// Create new node
Node* createNode(int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

// Add edge (undirected)
void addEdge(int u, int v, int w) {
    Node* n1 = createNode(v, w);
    n1->next = adj[u];
    adj[u] = n1;

    Node* n2 = createNode(u, w);
    n2->next = adj[v];
    adj[v] = n2;
}

// Min Heap structure
typedef struct {
    int vertex, key;
} HeapNode;

HeapNode heap[MAX];
int size = 0;

void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up
void heapifyUp(int i) {
    while (i && heap[i].key < heap[(i - 1) / 2].key) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Heapify down
void heapifyDown(int i) {
    int smallest = i;
    int l = 2 * i + 1, r = 2 * i + 2;

    if (l < size && heap[l].key < heap[smallest].key)
        smallest = l;
    if (r < size && heap[r].key < heap[smallest].key)
        smallest = r;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// Insert in heap
void insert(int v, int key) {
    heap[size].vertex = v;
    heap[size].key = key;
    heapifyUp(size);
    size++;
}

// Extract min
HeapNode extractMin() {
    HeapNode root = heap[0];
    heap[0] = heap[--size];
    heapifyDown(0);
    return root;
}

// Prim's Algorithm
int primMST(int n) {
    bool inMST[MAX] = {false};
    int key[MAX];

    for (int i = 1; i <= n; i++)
        key[i] = 1e9;

    key[1] = 0;
    insert(1, 0);

    int totalWeight = 0;

    while (size > 0) {
        HeapNode minNode = extractMin();
        int u = minNode.vertex;

        if (inMST[u]) continue;

        inMST[u] = true;
        totalWeight += minNode.key;

        Node* temp = adj[u];
        while (temp) {
            int v = temp->vertex;
            int w = temp->weight;

            if (!inMST[v] && w < key[v]) {
                key[v] = w;
                insert(v, w);
            }
            temp = temp->next;
        }
    }

    return totalWeight;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < MAX; i++)
        adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    printf("%d\n", primMST(n));

    return 0;
}