/*
Name- Yuvraj Singh
Roll no.- 59
Section- ML2
Course-B.tech CSE with specialization in AI and ML
Branch-B.tech CSE'''
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct BSTNode {
    int data;
    struct BSTNode *left;
    struct BSTNode *right;
} BSTNode;

BSTNode* createNode(int data) {
    BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

BSTNode* insert(BSTNode *root, int data) {
    if (root == NULL) return createNode(data);
    if (data < root->data) root->left = insert(root->left, data);
    else if (data > root->data) root->right = insert(root->right, data);
    return root;
}

BSTNode* buildTreeFromArray(int arr[], int n) {
    BSTNode *root = NULL;
    for (int i = 0; i < n; i++) {
        if (arr[i] != -1) {
            root = insert(root, arr[i]);
        }
    }
    return root;
}

int getHeight(BSTNode *root) {
    if (root == NULL) return -1;
    int leftH = getHeight(root->left);
    int rightH = getHeight(root->right);
    return 1 + (leftH > rightH ? leftH : rightH);
}

int search(BSTNode *root, int key) {
    if (root == NULL) return 0;
    if (root->data == key) return 1;
    if (key < root->data) return search(root->left, key);
    return search(root->right, key);
}

void printLevelOrder(BSTNode *root) {
    if (root == NULL) return;
    BSTNode *queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;

    printf("BST:");
    while (front < rear) {
        BSTNode *curr = queue[front++];
        printf(" %d", curr->data);
        if (curr->left != NULL) queue[rear++] = curr->left;
        if (curr->right != NULL) queue[rear++] = curr->right;
    }
    printf("\n");
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    BSTNode *root = buildTreeFromArray(arr, n);

    int choice, key = -1, searched = 0;
    while (1) {
        if (scanf("%d", &choice) != 1) break;
        if (choice == 1) {
            int val; scanf("%d", &val);
            root = insert(root, val);
        } else if (choice == 2) {
            int val; scanf("%d", &val);
        } else if (choice == 3) {
            printf("Enter key: ");
            scanf("%d", &key);
            searched = 1;
        } else if (choice == 4) {
            break;
        }
    }

    printLevelOrder(root);
    int h = getHeight(root);
    printf("Height = %d\n", h);
    printf("Depth = %d\n", h);
    if (searched) {
        if (search(root, key)) printf("%d - present\n", key);
        else printf("Not present\n");
    }

    free(arr);
    return 0;
}
