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

int isMirror(struct Node* left, struct Node* right) {
    if (left == NULL && right == NULL)
        return 1;

    if (left == NULL || right == NULL)
        return 0;

    return (left->data == right->data) &&
           isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
}

int isSymmetric(struct Node* root) {
    if (root == NULL)
        return 1;
    return isMirror(root->left, root->right);
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Node* nodes[n];

    for (int i = 0; i < n; i++) {
        if (arr[i] != -1)
            nodes[i] = newNode(arr[i]);
        else
            nodes[i] = NULL;
    }

    for (int i = 0; i < n; i++) {
        if (nodes[i] != NULL) {
            int leftIndex = 2*i + 1;
            int rightIndex = 2*i + 2;

            if (leftIndex < n)
                nodes[i]->left = nodes[leftIndex];
            if (rightIndex < n)
                nodes[i]->right = nodes[rightIndex];
        }
    }

    return nodes[0];
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    if (isSymmetric(root))
        printf("YES");
    else
        printf("NO");

    return 0;
}