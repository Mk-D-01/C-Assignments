#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode* buildTreeFromArray(int arr[], int n, int idx) {
    if (idx >= n || arr[idx] == -1) return NULL;
    TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
    root->data = arr[idx];
    root->left = buildTreeFromArray(arr, n, 2 * idx + 1);
    root->right = buildTreeFromArray(arr, n, 2 * idx + 2);
    return root;
}

int getHeight(TreeNode *root) {
    if (root == NULL) return -1;
    int leftH = getHeight(root->left);
    int rightH = getHeight(root->right);
    return 1 + (leftH > rightH ? leftH : rightH);
}

int getSize(TreeNode *root) {
    if (root == NULL) return 0;
    return 1 + getSize(root->left) + getSize(root->right);
}

void printLevelOrder(TreeNode *root) {
    if (root == NULL) return;
    TreeNode *queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;

    printf("Tree:");
    while (front < rear) {
        TreeNode *curr = queue[front++];
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

    TreeNode *root = buildTreeFromArray(arr, n, 0);

    int choice, val;
    while (1) {
        if (scanf("%d", &choice) != 1) break;
        if (choice == 1) {
            scanf("%d", &val);
        } else if (choice == 2) {
            scanf("%d", &val);
        } else if (choice == 3) {
            break;
        }
    }

    printLevelOrder(root);
    printf("Height = %d\n", getHeight(root));
    printf("Size = %d\n", getSize(root));

    free(arr);
    return 0;
}
