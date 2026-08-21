/*
Name- Yuvraj Singh
Roll no.- 59
Section- ML2
Course-B.tech CSE with specialization in AI and ML
Branch-B.tech CSE'''
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int val) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = val;
}

int pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

int getSize() {
    return top + 1;
}

void printStack() {
    printf("Stack -");
    for (int i = 0; i <= top; i++) {
        printf(" %d", stack[i]);
    }
    printf("\n");
}

int main() {
    int choice, val;
    while (1) {
        if (scanf("%d", &choice) != 1) break;
        if (choice == 1) {
            scanf("%d", &val);
            push(val);
            printStack();
        } else if (choice == 2) {
            pop();
            printStack();
        } else if (choice == 3) {
            printf("Size = %d\n", getSize());
        } else if (choice == 4) {
            break;
        }
    }
    return 0;
}
