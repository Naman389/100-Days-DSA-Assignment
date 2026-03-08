#include <stdio.h>

#define MAX 100

int main() {
    int queue[MAX];
    int front = 0, rear = -1;
    int n, m, i;

    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        rear = (rear + 1) % MAX;
        queue[rear] = x;
    }

    scanf("%d", &m);

    for(i = 0; i < m; i++) {
        front = (front + 1) % MAX;
        rear = (rear + 1) % MAX;
        queue[rear] = queue[(rear - n + MAX) % MAX];
    }

    for(i = 0; i < n; i++) {
        printf("%d ", queue[(front + i) % MAX]);
    }

    return 0;
}