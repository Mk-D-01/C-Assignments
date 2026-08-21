/*
Name- Yuvraj Singh
Roll no.- 59
Section- ML2
Course-B.tech CSE with specialization in AI and ML
Branch-B.tech CSE'''
*/
#include <stdio.h>
#include <stdlib.h>

void findOddOccurrence(int arr[], int n) {
    int res = 0;
    for (int i = 0; i < n; i++) {
        res ^= arr[i];
    }
    // Check if res occurs odd number of times
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == res) count++;
    }
    if (count % 2 != 0) {
        printf("%d\n", res);
    } else {
        printf("No such element present\n");
    }
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
        findOddOccurrence(arr, n);
        free(arr);
    }
    return 0;
}
