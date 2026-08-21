#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode* buildTree(int arr[], int n, int idx) {
    if (idx >= n || arr[idx] == -1) return NULL;
    TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
    root->data = arr[idx];
    root->left = buildTree(arr, n, 2 * idx + 1);
    root->right = buildTree(arr, n, 2 * idx + 2);
    return root;
}

void inorder(TreeNode *root) {
    if (root == NULL) return;
    inorder(root->left);
    printf(" %d", root->data);
    inorder(root->right);
}

void postorder(TreeNode *root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf(" %d", root->data);
}

void preorder(TreeNode *root) {
    if (root == NULL) return;
    printf(" %d", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    TreeNode *root = buildTree(arr, n, 0);

    printf("Inorder :");
    inorder(root);
    printf("\n");

    printf("Postorder :");
    postorder(root);
    printf("\n");

    printf("Preorder :");
    preorder(root);
    printf("\n");

    free(arr);
    return 0;
}
