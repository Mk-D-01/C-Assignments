#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Stack {
    Node *top;
    int size;
} Stack;

Stack* createStack() {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = NULL;
    s->size = 0;
    return s;
}

void push(Stack *s, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = s->top;
    s->top = newNode;
    s->size++;
}

int pop(Stack *s) {
    if (s->top == NULL) return -1;
    Node *temp = s->top;
    int data = temp->data;
    s->top = s->top->next;
    free(temp);
    s->size--;
    return data;
}

void printStack(Stack *s) {
    printf("Stack -");
    // Print stack elements bottom to top to match expected format
    // We can store in array or reverse print
    int *arr = (int *)malloc(s->size * sizeof(int));
    Node *temp = s->top;
    for (int i = s->size - 1; i >= 0; i--) {
        arr[i] = temp->data;
        temp = temp->next;
    }
    for (int i = 0; i < s->size; i++) {
        printf(" %d", arr[i]);
    }
    printf("\n");
    free(arr);
}

int main() {
    Stack *s = createStack();
    int choice, val;

    while (1) {
        if (scanf("%d", &choice) != 1) break;
        if (choice == 1) {
            scanf("%d", &val);
            push(s, val);
            printStack(s);
        } else if (choice == 2) {
            pop(s);
            printStack(s);
        } else if (choice == 3) {
            printf("Size = %d\n", s->size);
        } else if (choice == 4) {
            break;
        }
    }

    return 0;
}
