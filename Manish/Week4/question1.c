#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

void reverseStringUsingStack(char *str) {
    int len = strlen(str);
    char stack[MAX];
    int top = -1;

    for (int i = 0; i < len; i++) {
        stack[++top] = str[i];
    }

    for (int i = 0; i < len; i++) {
        str[i] = stack[top--];
    }
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    char str[MAX];
    while (t--) {
        scanf("%s", str);
        reverseStringUsingStack(str);
        printf("%s\n", str);
    }
    return 0;
}
