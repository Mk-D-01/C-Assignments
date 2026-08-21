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

typedef struct Queue {
    int arr[MAX];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

int isEmpty(Queue *q) {
    return q->front > q->rear;
}

void enqueue(Queue *q, int val) {
    q->arr[++(q->rear)] = val;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) return -1;
    return q->arr[(q->front)++];
}

int size(Queue *q) {
    if (isEmpty(q)) return 0;
    return q->rear - q->front + 1;
}

// Implement Stack using 1 Queue
void pushStack(Queue *q, int val) {
    int s = size(q);
    enqueue(q, val);
    for (int i = 0; i < s; i++) {
        enqueue(q, dequeue(q));
    }
}

int popStack(Queue *q) {
    return dequeue(q);
}

void printStack(Queue *q) {
    printf("Stack -");
    // Elements in stack order are front to rear
    for (int i = q->rear; i >= q->front; i--) {
        printf(" %d", q->arr[i]);
    }
    printf("\n");
}

int main() {
    Queue q;
    initQueue(&q);
    int choice, val;

    while (1) {
        if (scanf("%d", &choice) != 1) break;
        if (choice == 1) {
            scanf("%d", &val);
            enqueue(&q, val); // Insert at top
            printStack(&q);
        } else if (choice == 2) {
            if (!isEmpty(&q)) {
                int popped = q.arr[q.rear--];
                printf("Element popped from stack - %d\n", popped);
                printf("Stack after pop operation -");
                for (int i = q.front; i <= q.rear; i++) {
                    printf(" %d", q.arr[i]);
                }
                printf("\n");
            }
        } else if (choice == 3) {
            break;
        }
    }

    return 0;
}
