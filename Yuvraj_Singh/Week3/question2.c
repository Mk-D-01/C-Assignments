/*
Name- Yuvraj Singh
Roll no.- 59
Section- ML2
Course-B.tech CSE with specialization in AI and ML
Branch-B.tech CSE'''
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

int isMatchingPair(char char1, char char2) {
    if (char1 == '(' && char2 == ')') return 1;
    if (char1 == '{' && char2 == '}') return 1;
    if (char1 == '[' && char2 == ']') return 1;
    return 0;
}

int isBalanced(char* str) {
    char stack[MAX];
    int top = -1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            stack[++top] = str[i];
        } else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
            if (top == -1 || !isMatchingPair(stack[top], str[i])) {
                return 0;
            }
            top--;
        }
    }
    return (top == -1);
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    char str[MAX];
    while (t--) {
        scanf("%s", str);
        if (isBalanced(str)) {
            printf("Balance\n");
        } else {
            printf("Unbalanced\n");
        }
    }
    return 0;
}
