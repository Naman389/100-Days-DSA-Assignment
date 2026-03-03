#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == MAX - 1;
}

void push(int value) {
    if (isFull()) {
        return;
    }
    stack[++top] = value;
}

void pop() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
    } else {
        printf("%d\n", stack[top--]);
    }
}

void display() {
    if (isEmpty()) {
        return;
    }
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int n, op, value;
    scanf("%d", &n);

    while (n--) {
        scanf("%d", &op);

        if (op == 1) {
            scanf("%d", &value);
            push(value);
        } 
        else if (op == 2) {
            pop();
        } 
        else if (op == 3) {
            display();
        }
    }
    return 0;
}