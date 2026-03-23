#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return newNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

struct Node* findLCA(struct Node* root, int n1, int n2) {
    if (root == NULL)
        return NULL;

    if (root->data > n1 && root->data > n2)
        return findLCA(root->left, n1, n2);

    if (root->data < n1 && root->data < n2)
        return findLCA(root->right, n1, n2);

    return root;
}

int main() {
    int n, i, x, n1, n2;
    struct Node* root = NULL;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    scanf("%d %d", &n1, &n2);

    struct Node* lca = findLCA(root, n1, n2);

    if (lca != NULL)
        printf("%d\n", lca->data);

    return 0;
}