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

void storeInorder(BSTNode *root, int nodes[], int *index) {
    if (root == NULL) return;
    storeInorder(root->left, nodes, index);
    nodes[(*index)++] = root->data;
    storeInorder(root->right, nodes, index);
}

BSTNode* buildBalancedBST(int nodes[], int start, int end) {
    if (start > end) return NULL;
    int mid = (start + end) / 2;
    BSTNode *root = createNode(nodes[mid]);
    root->left = buildBalancedBST(nodes, start, mid - 1);
    root->right = buildBalancedBST(nodes, mid + 1, end);
    return root;
}

void printLevelOrder(BSTNode *root, const char *title) {
    if (root == NULL) return;
    BSTNode *queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;

    printf("%s:", title);
    while (front < rear) {
        BSTNode *curr = queue[front++];
        printf(" %d", curr->data);
        if (curr->left != NULL) queue[rear++] = curr->left;
        if (curr->right != NULL) queue[rear++] = curr->right;
    }
    printf("\n");
}

int findMin(BSTNode *root) {
    while (root->left != NULL) root = root->left;
    return root->data;
}

int findMax(BSTNode *root) {
    while (root->right != NULL) root = root->right;
    return root->data;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int *arr = (int *)malloc(n * sizeof(int));
    BSTNode *root = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] != -1) {
            root = insert(root, arr[i]);
        }
    }

    printLevelOrder(root, "Initial BST");

    int nodes[1000];
    int index = 0;
    storeInorder(root, nodes, &index);

    BSTNode *balancedRoot = buildBalancedBST(nodes, 0, index - 1);
    printLevelOrder(balancedRoot, "Balanced BST");

    printf("Maximum element: %d\n", findMax(balancedRoot));
    printf("Minimum element: %d\n", findMin(balancedRoot));

    free(arr);
    return 0;
}
