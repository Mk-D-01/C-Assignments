#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Stack {
    int arr[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int val) {
    s->arr[++(s->top)] = val;
}

int pop(Stack *s) {
    if (isEmpty(s)) return -1;
    return s->arr[(s->top)--];
}

typedef struct Queue {
    Stack s1;
    Stack s2;
} Queue;

void initQueue(Queue *q) {
    initStack(&q->s1);
    initStack(&q->s2);
}

void enqueue(Queue *q, int val) {
    push(&q->s1, val);
}

int dequeue(Queue *q) {
    if (isEmpty(&q->s1) && isEmpty(&q->s2)) return -1;
    if (isEmpty(&q->s2)) {
        while (!isEmpty(&q->s1)) {
            push(&q->s2, pop(&q->s1));
        }
    }
    return pop(&q->s2);
}

void printQueue(Queue *q) {
    printf("Queue -");
    for (int i = 0; i <= q->s2.top; i++) {
        printf(" %d", q->s2.arr[q->s2.top - i]);
    }
    for (int i = 0; i <= q->s1.top; i++) {
        printf(" %d", q->s1.arr[i]);
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
            enqueue(&q, val);
            printQueue(&q);
        } else if (choice == 2) {
            int removed = dequeue(&q);
            if (removed != -1) {
                printf("Element deleted from queue - %d\n", removed);
                printf("Queue after deletion-");
                for (int i = q.s2.top; i >= 0; i--) {
                    printf(" %d", q.s2.arr[i]);
                }
                for (int i = 0; i <= q.s1.top; i++) {
                    printf(" %d", q.s1.arr[i]);
                }
                printf("\n");
            }
        } else if (choice == 3) {
            break;
        }
    }

    return 0;
}
