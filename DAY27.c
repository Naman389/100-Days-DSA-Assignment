#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

struct Node* getIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    struct Node* temp1 = head1;
    struct Node* temp2 = head2;

    if (len1 > len2) {
        for (int i = 0; i < diff; i++)
            temp1 = temp1->next;
    } else {
        for (int i = 0; i < diff; i++)
            temp2 = temp2->next;
    }

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->data == temp2->data)
            return temp1;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return NULL;
}

int main() {
    int n, m, i, value;
    struct Node *head1 = NULL, *head2 = NULL, *temp, *tail;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        temp = createNode(value);
        if (head1 == NULL) {
            head1 = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        scanf("%d", &value);
        temp = createNode(value);
        if (head2 == NULL) {
            head2 = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    struct Node* intersection = getIntersection(head1, head2);

    if (intersection != NULL)
        printf("%d", intersection->data);
    else
        printf("No Intersection");

    return 0;
}