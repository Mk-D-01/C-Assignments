#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int minDistance(int arr[], int n, int a, int b) {
    int last_a = -1, last_b = -1;
    int min_dist = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (arr[i] == a) {
            last_a = i;
            if (last_b != -1) {
                int dist = abs(last_a - last_b);
                if (dist < min_dist) min_dist = dist;
            }
        }
        if (arr[i] == b) {
            last_b = i;
            if (last_a != -1) {
                int dist = abs(last_a - last_b);
                if (dist < min_dist) min_dist = dist;
            }
        }
    }
    return (min_dist == INT_MAX) ? -1 : min_dist;
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
        int a, b;
        scanf("%d %d", &a, &b);

        int ans = minDistance(arr, n, a, b);
        printf("%d\n", ans);
        free(arr);
    }
    return 0;
}
