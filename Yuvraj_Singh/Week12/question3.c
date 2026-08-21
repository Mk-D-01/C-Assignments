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

void findLevelWithMaxNodes(BSTNode *root) {
    if (root == NULL) return;

    BSTNode *queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;

    int level = 1;
    int maxLevel = 1;
    int maxNodes = 0;
    int levelCounts[100];
    int totalLevels = 0;

    while (front < rear) {
        int count = rear - front;
        levelCounts[level] = count;
        totalLevels = level;

        if (count > maxNodes) {
            maxNodes = count;
            maxLevel = level;
        }

        for (int i = 0; i < count; i++) {
            BSTNode *curr = queue[front++];
            if (curr->left != NULL) queue[rear++] = curr->left;
            if (curr->right != NULL) queue[rear++] = curr->right;
        }
        level++;
    }

    int allEqual = 1;
    for (int i = 1; i <= totalLevels; i++) {
        if (levelCounts[i] != levelCounts[1]) {
            allEqual = 0;
            break;
        }
    }

    if (allEqual && totalLevels > 1) {
        printf("Equal no. Of nodes on all levels\n");
    } else {
        printf("Level %d has %d nodes\n", maxLevel, maxNodes);
    }
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

    printLevelOrder(root);
    findLevelWithMaxNodes(root);

    free(arr);
    return 0;
}
