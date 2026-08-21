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

int queue[MAX];
int front = 0, rear = -1;

void enqueue(int val) {
    queue[++rear] = val;
}

int main() {
    int choice, val;
    while (1) {
        if (scanf("%d", &choice) != 1) break;
        if (choice == 1) {
            scanf("%d", &val);
            enqueue(val);
        } else if (choice == 2) {
            break;
        }
    }

    printf("Initial Queue :");
    for (int i = front; i <= rear; i++) {
        printf(" %d", queue[i]);
    }
    printf("\n");

    printf("Reverse Queue :");
    for (int i = rear; i >= front; i--) {
        printf(" %d", queue[i]);
    }
    printf("\n");

    return 0;
}
