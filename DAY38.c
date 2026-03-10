 #include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;
int count = 0;

void push_front(int value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->prev = NULL;
    temp->next = front;

    if(front == NULL)
        rear = temp;
    else
        front->prev = temp;

    front = temp;
    count++;
}

void push_back(int value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;
    temp->prev = rear;

    if(rear == NULL)
        front = temp;
    else
        rear->next = temp;

    rear = temp;
    count++;
}

void pop_front() {
    if(front == NULL) {
        printf("Deque Empty\n");
        return;
    }

    struct Node* temp = front;
    front = front->next;

    if(front == NULL)
        rear = NULL;
    else
        front->prev = NULL;

    free(temp);
    count--;
}

void pop_back() {
    if(rear == NULL) {
        printf("Deque Empty\n");
        return;
    }

    struct Node* temp = rear;
    rear = rear->prev;

    if(rear == NULL)
        front = NULL;
    else
        rear->next = NULL;

    free(temp);
    count--;
}

void get_front() {
    if(front == NULL)
        printf("-1\n");
    else
        printf("%d\n", front->data);
}

void get_back() {
    if(rear == NULL)
        printf("-1\n");
    else
        printf("%d\n", rear->data);
}

void size() {
    printf("%d\n", count);
}

void empty() {
    if(front == NULL)
        printf("True\n");
    else
        printf("False\n");
}

void display() {
    struct Node* temp = front;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, value;

    while(1) {
        printf("\n1 push_front\n2 push_back\n3 pop_front\n4 pop_back\n5 front\n6 back\n7 size\n8 empty\n9 display\n0 exit\n");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                scanf("%d", &value);
                push_front(value);
                break;

            case 2:
                scanf("%d", &value);
                push_back(value);
                break;

            case 3:
                pop_front();
                break;

            case 4:
                pop_back();
                break;

            case 5:
                get_front();
                break;

            case 6:
                get_back();
                break;

            case 7:
                size();
                break;

            case 8:
                empty();
                break;

            case 9:
                display();
                break;

            case 0:
                exit(0);
        }
    }
}