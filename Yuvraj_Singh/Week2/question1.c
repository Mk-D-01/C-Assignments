/*
Name- Yuvraj Singh
Roll no.- 59
Section- ML2
Course-B.tech CSE with specialization in AI and ML
Branch-B.tech CSE'''
*/
#include <stdio.h>
#include <stdlib.h>

void searchMatrix(int **matrix, int n, int key) {
    int i = 0, j = n - 1;
    while (i < n && j >= 0) {
        if (matrix[i][j] == key) {
            printf("Present\n");
            return;
        }
        if (matrix[i][j] > key) {
            j--;
        } else {
            i++;
        }
    }
    printf("Not Present\n");
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int **matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    int key;
    scanf("%d", &key);

    searchMatrix(matrix, n, key);

    for (int i = 0; i < n; i++) free(matrix[i]);
    free(matrix);
    return 0;
}
