/*
Name- Yuvraj Singh
Roll no.- 59
Section- ML2
Course-B.tech CSE with specialization in AI and ML
Branch-B.tech CSE'''
*/
#include <stdio.h>
#include <stdlib.h>

void rotateMatrixClockwise(int **mat, int n) {
    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;

    while (top < bottom && left < right) {
        int prev = mat[top + 1][left];

        // Move elements of top row
        for (int i = left; i <= right; i++) {
            int curr = mat[top][i];
            mat[top][i] = prev;
            prev = curr;
        }
        top++;

        // Move elements of right column
        for (int i = top; i <= bottom; i++) {
            int curr = mat[i][right];
            mat[i][right] = prev;
            prev = curr;
        }
        right--;

        // Move elements of bottom row
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                int curr = mat[bottom][i];
                mat[bottom][i] = prev;
                prev = curr;
            }
        }
        bottom--;

        // Move elements of left column
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                int curr = mat[i][left];
                mat[i][left] = prev;
                prev = curr;
            }
        }
        left++;
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int **mat = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        mat[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    rotateMatrixClockwise(mat, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d%c", mat[i][j], (j == n - 1) ? '\n' : ' ');
        }
    }

    for (int i = 0; i < n; i++) free(mat[i]);
    free(mat);
    return 0;
}
