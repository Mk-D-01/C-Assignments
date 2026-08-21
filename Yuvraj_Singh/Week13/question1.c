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

void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifyMax(arr, n, i);
    }
}

void insertHeap(int arr[], int *n, int val) {
    (*n)++;
    int i = *n - 1;
    arr[i] = val;

    while (i != 0 && arr[(i - 1) / 2] < arr[i]) {
        swap(&arr[i], &arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int deleteMax(int arr[], int *n) {
    if (*n <= 0) return -1;
    int root = arr[0];
    arr[0] = arr[*n - 1];
    (*n)--;
    heapifyMax(arr, *n, 0);
    return root;
}

void printHeap(int arr[], int n, const char *title) {
    printf("%s:", title);
    for (int i = 0; i < n; i++) {
        printf(" %d", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int arr[100];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    buildMaxHeap(arr, n);
    printHeap(arr, n, "Initial Priority Queue");
    printf("Max Priority: %d\n", arr[0]);

    int choice, val;
    while (1) {
        if (scanf("%d", &choice) != 1) break;
        if (choice == 1) {
            scanf("%d", &val);
            insertHeap(arr, &n, val);
            printHeap(arr, n, "Updated Priority Queue");
        } else if (choice == 2) {
            int del = deleteMax(arr, &n);
            printf("Priority of element deleted: %d\n", del);
            printHeap(arr, n, "Updated Priority Queue");
        } else if (choice == 3) {
            break;
        }
    }

    return 0;
}
