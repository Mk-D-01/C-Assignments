/*
Name- Yuvraj Singh
Roll no.- 59
Section- ML2
Course-B.tech CSE with specialization in AI and ML
Branch-B.tech CSE'''
*/
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyMax(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapifyMax(arr, n, largest);
    }
}

int findKthLargest(int arr[], int n, int k) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifyMax(arr, n, i);
    }

    int kth = -1;
    for (int i = 0; i < k; i++) {
        kth = arr[0];
        arr[0] = arr[n - 1 - i];
        heapifyMax(arr, n - 1 - i, 0);
    }
    return kth;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int k;
    scanf("%d", &k);

    int ans = findKthLargest(arr, n, k);
    printf("K = %d, largest element : %d\n", k, ans);

    free(arr);
    return 0;
}
