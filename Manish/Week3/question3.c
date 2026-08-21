#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000

int longestValidParentheses(char* str) {
    int stack[MAX];
    int top = -1;

    stack[++top] = -1;
    int max_len = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(') {
            stack[++top] = i;
        } else if (str[i] == ')') {
            if (top != -1) {
                top--;
            }
            if (top != -1) {
                int len = i - stack[top];
                if (len > max_len) max_len = len;
            } else {
                stack[++top] = i;
            }
        }
    }
    return max_len;
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    char str[MAX];
    while (t--) {
        scanf("%s", str);
        printf("%d\n", longestValidParentheses(str));
    }
    return 0;
}
