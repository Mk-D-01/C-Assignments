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
int front = 0;
int rear = -1;

void enqueue(int val) {
    if (rear >= MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    queue[++rear] = val;
}

int dequeue() {
    if (front > rear) {
        printf("Queue Underflow\n");
        return -1;
    }
    return queue[front++];
}

int getSize() {
    if (front > rear) return 0;
    return rear - front + 1;
}

void printQueue() {
    printf("Queue -");
    for (int i = front; i <= rear; i++) {
        printf(" %d", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, val;
    while (1) {
        if (scanf("%d", &choice) != 1) break;
        if (choice == 1) {
            scanf("%d", &val);
            enqueue(val);
            printQueue();
        } else if (choice == 2) {
            dequeue();
            printQueue();
        } else if (choice == 3) {
            printf("Size = %d\n", getSize());
        } else if (choice == 4) {
            break;
        }
    }
    return 0;
}
