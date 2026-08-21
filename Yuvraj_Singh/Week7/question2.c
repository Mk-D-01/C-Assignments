/*
Name- Yuvraj Singh
Roll no.- 59
Section- ML2
Course-B.tech CSE with specialization in AI and ML
Branch-B.tech CSE'''
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *front;
    Node *rear;
    int size;
} Queue;

Queue* createQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

void enqueue(Queue *q, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
}

int dequeue(Queue *q) {
    if (q->front == NULL) return -1;
    Node *temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    q->size--;
    return data;
}

void printQueue(Queue *q) {
    printf("Queue -");
    Node *temp = q->front;
    while (temp != NULL) {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue *q = createQueue();
    int choice, val;

    while (1) {
        if (scanf("%d", &choice) != 1) break;
        if (choice == 1) {
            scanf("%d", &val);
            enqueue(q, val);
            printQueue(q);
        } else if (choice == 2) {
            dequeue(q);
            printQueue(q);
        } else if (choice == 3) {
            printf("Size = %d\n", q->size);
        } else if (choice == 4) {
            break;
        }
    }

    return 0;
}
