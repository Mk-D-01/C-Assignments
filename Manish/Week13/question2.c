#include <stdio.h>
#include <stdlib.h>

int isHeap(int arr[], int n) {
    // A complete binary tree represented in array form is heap if every node is >= its children
    for (int i = 0; i <= (n - 2) / 2; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[i] < arr[left]) return 0;
        if (right < n && arr[i] < arr[right]) return 0;
    }
    return 1;
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        int n;
        if (scanf("%d", &n) != 1) break;
        int *arr = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        if (isHeap(arr, n)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
        free(arr);
    }
    return 0;
}
