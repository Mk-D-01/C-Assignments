#include <stdio.h>
#include <stdlib.h>

typedef struct CircularQueue {
    int *arr;
    int front;
    int rear;
    int size;
    int count;
} CircularQueue;

CircularQueue* createCQ(int size) {
    CircularQueue *cq = (CircularQueue *)malloc(sizeof(CircularQueue));
    cq->size = size;
    cq->arr = (int *)malloc(size * sizeof(int));
    cq->front = -1;
    cq->rear = -1;
    cq->count = 0;
    return cq;
}

void enqueue(CircularQueue *cq, int val) {
    if (cq->count == cq->size) {
        printf("Queue Full\n");
        return;
    }
    if (cq->count == 0) {
        cq->front = 0;
        cq->rear = 0;
    } else {
        cq->rear = (cq->rear + 1) % cq->size;
    }
    cq->arr[cq->rear] = val;
    cq->count++;
}

void dequeue(CircularQueue *cq) {
    if (cq->count == 0) {
        printf("Queue Empty\n");
        return;
    }
    if (cq->front == cq->rear) {
        cq->front = -1;
        cq->rear = -1;
    } else {
        cq->front = (cq->front + 1) % cq->size;
    }
    cq->count--;
}

void printCQ(CircularQueue *cq) {
    printf("Circular Queue :");
    for (int i = 0; i < cq->count; i++) {
        int idx = (cq->front + i) % cq->size;
        printf(" %d", cq->arr[idx]);
    }
    printf("\n");
}

int main() {
    int size;
    if (scanf("%d", &size) != 1) return 0;
    CircularQueue *cq = createCQ(size);

    int choice, val;
    while (1) {
        if (scanf("%d", &choice) != 1) break;
        if (choice == 1) {
            scanf("%d", &val);
            enqueue(cq, val);
            printCQ(cq);
        } else if (choice == 2) {
            dequeue(cq);
            printCQ(cq);
        } else if (choice == 3) {
            if (cq->count > 0) printf("Front : %d\n", cq->arr[cq->front]);
        } else if (choice == 4) {
            if (cq->count > 0) printf("Rear : %d\n", cq->arr[cq->rear]);
        } else if (choice == 5) {
            break;
        }
    }

    free(cq->arr);
    free(cq);
    return 0;
}
