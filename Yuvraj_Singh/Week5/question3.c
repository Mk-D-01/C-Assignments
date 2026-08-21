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

typedef struct Deque {
    int arr[MAX];
    int front;
    int rear;
    int count;
} Deque;

Deque* createDeque() {
    Deque *dq = (Deque *)malloc(sizeof(Deque));
    dq->front = -1;
    dq->rear = -1;
    dq->count = 0;
    return dq;
}

int isFull(Deque *dq) {
    return (dq->count == MAX);
}

int isEmpty(Deque *dq) {
    return (dq->count == 0);
}

void insertFront(Deque *dq, int val) {
    if (isFull(dq)) return;
    if (isEmpty(dq)) {
        dq->front = 0;
        dq->rear = 0;
    } else {
        dq->front = (dq->front - 1 + MAX) % MAX;
    }
    dq->arr[dq->front] = val;
    dq->count++;
}

void insertEnd(Deque *dq, int val) {
    if (isFull(dq)) return;
    if (isEmpty(dq)) {
        dq->front = 0;
        dq->rear = 0;
    } else {
        dq->rear = (dq->rear + 1) % MAX;
    }
    dq->arr[dq->rear] = val;
    dq->count++;
}

void deleteFront(Deque *dq) {
    if (isEmpty(dq)) return;
    if (dq->front == dq->rear) {
        dq->front = -1;
        dq->rear = -1;
    } else {
        dq->front = (dq->front + 1) % MAX;
    }
    dq->count--;
}

void deleteEnd(Deque *dq) {
    if (isEmpty(dq)) return;
    if (dq->front == dq->rear) {
        dq->front = -1;
        dq->rear = -1;
    } else {
        dq->rear = (dq->rear - 1 + MAX) % MAX;
    }
    dq->count--;
}

void printFront(Deque *dq) {
    printf("Contents of queue from front - \n");
    for (int i = 0; i < dq->count; i++) {
        int idx = (dq->front + i) % MAX;
        printf("%d%c", dq->arr[idx], (i == dq->count - 1) ? '\n' : ' ');
    }
}

void printEnd(Deque *dq) {
    printf("Contents of queue from end - \n");
    for (int i = 0; i < dq->count; i++) {
        int idx = (dq->rear - i + MAX) % MAX;
        printf("%d%c", dq->arr[idx], (i == dq->count - 1) ? '\n' : ' ');
    }
}

int main() {
    Deque *dq = createDeque();
    int choice, val;

    while (1) {
        if (scanf("%d", &choice) != 1) break;
        if (choice == 1) {
            scanf("%d", &val);
            insertFront(dq, val);
        } else if (choice == 2) {
            scanf("%d", &val);
            insertEnd(dq, val);
        } else if (choice == 3) {
            deleteFront(dq);
        } else if (choice == 4) {
            deleteEnd(dq);
        } else if (choice == 5) {
            break;
        }
    }

    printFront(dq);
    printEnd(dq);

    free(dq);
    return 0;
}
