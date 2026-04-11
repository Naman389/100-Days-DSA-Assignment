#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int u, v, w;
};

int main() {
    int n, m;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    struct Edge edges[m];

    printf("Enter edges (u v w):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    int source;
    printf("Enter source vertex: ");
    scanf("%d", &source);

    int dist[n];

    for (int i = 0; i < n; i++) {
        dist[i] = 1000000000; // INF
    }
    dist[source] = 0;

    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != 1000000000 && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (int j = 0; j < m; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if (dist[u] != 1000000000 && dist[u] + w < dist[v]) {
            printf("NEGATIVE CYCLE\n");
            return 0;
        }
    }

    printf("Shortest distances from source %d:\n", source);
    for (int i = 0; i < n; i++) {
        if (dist[i] == 1000000000)
            printf("%d -> INF\n", i);
        else
            printf("%d -> %d\n", i, dist[i]);
    }

    return 0;
}