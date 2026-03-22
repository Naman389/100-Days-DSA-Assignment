#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);
    
    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    
    return root;
}

int search(struct Node* root, int key) {
    if (root == NULL)
        return 0;
    
    if (root->data == key)
        return 1;
    
    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

int main() {
    int n, i, key, val;
    struct Node* root = NULL;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    scanf("%d", &key);

    if (search(root, key))
        printf("Found");
    else
        printf("Not Found");

    return 0;
}