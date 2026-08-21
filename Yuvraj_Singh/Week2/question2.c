/*
Name- Yuvraj Singh
Roll no.- 59
Section- ML2
Course-B.tech CSE with specialization in AI and ML
Branch-B.tech CSE'''
*/
#include <stdio.h>
#include <stdlib.h>

void maxOnesRow(int **matrix, int m, int n) {
    int max_row_idx = -1;
    int j = n - 1; // start from top right

    for (int i = 0; i < m; i++) {
        while (j >= 0 && matrix[i][j] == 1) {
            j--;
            max_row_idx = i;
        }
    }

    if (max_row_idx == -1) {
        printf("Not Present\n");
    } else {
        printf("row - %d\n", max_row_idx + 1);
    }
}

int main() {
    int m, n;
    if (scanf("%d %d", &m, &n) != 2) return 0;
    int **matrix = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    maxOnesRow(matrix, m, n);

    for (int i = 0; i < m; i++) free(matrix[i]);
    free(matrix);
    return 0;
}
