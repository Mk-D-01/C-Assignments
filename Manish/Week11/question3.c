#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

void infixToPostfix(char *infix) {
    char stack[1000];
    int top = -1;
    char postfix[1000];
    int p = 0;

    for (int i = 0; infix[i] != '\0' && infix[i] != '\n'; i++) {
        char ch = infix[i];
        if (isalnum(ch)) {
            postfix[p++] = ch;
        } else if (ch == '(') {
            stack[++top] = ch;
        } else if (ch == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[p++] = stack[top--];
            }
            if (top != -1) top--; // pop '('
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(ch)) {
                if (ch == '^' && stack[top] == '^') break; // Right associative
                postfix[p++] = stack[top--];
            }
            stack[++top] = ch;
        }
    }

    while (top != -1) {
        postfix[p++] = stack[top--];
    }
    postfix[p] = '\0';
    printf("%s\n", postfix);
}

int main() {
    int t;
    if (scanf("%d\n", &t) != 1) return 0;
    char infix[1000];
    while (t--) {
        if (fgets(infix, sizeof(infix), stdin) != NULL) {
            // Trim whitespace/newline
            infix[strcspn(infix, "\r\n")] = 0;
            if (strlen(infix) == 0) {
                t++;
                continue;
            }
            infixToPostfix(infix);
        }
    }
    return 0;
}
