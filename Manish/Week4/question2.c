#include <stdio.h>
#include <stdlib.h>

typedef struct TwoStacks {
    int *arr;
    int size;
    int top1;
    int top2;
} TwoStacks;

TwoStacks* createTwoStacks(int n) {
    TwoStacks *ts = (TwoStacks *)malloc(sizeof(TwoStacks));
    ts->size = n;
    ts->arr = (int *)malloc(n * sizeof(int));
    ts->top1 = -1;
    ts->top2 = n;
    return ts;
}

void push1(TwoStacks *ts, int val) {
    if (ts->top1 < ts->top2 - 1) {
        ts->arr[++(ts->top1)] = val;
    } else {
        printf("Stack Overflow in Stack 1\n");
    }
}

void push2(TwoStacks *ts, int val) {
    if (ts->top1 < ts->top2 - 1) {
        ts->arr[--(ts->top2)] = val;
    } else {
        printf("Stack Overflow in Stack 2\n");
    }
}

int pop1(TwoStacks *ts) {
    if (ts->top1 >= 0) {
        return ts->arr[(ts->top1)--];
    }
    return -1;
}

int pop2(TwoStacks *ts) {
    if (ts->top2 < ts->size) {
        return ts->arr[(ts->top2)++];
    }
    return -1;
}

void printStacks(TwoStacks *ts) {
    printf("stack 1:");
    for (int i = 0; i <= ts->top1; i++) {
        printf(" %d", ts->arr[i]);
    }
    printf("\n");

    printf("stack 2:");
    for (int i = ts->size - 1; i >= ts->top2; i--) {
        printf(" %d", ts->arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    TwoStacks *ts = createTwoStacks(n);

    int choice, val;
    while (1) {
        if (scanf("%d", &choice) != 1) break;
        if (choice == 1) {
            scanf("%d", &val);
            push1(ts, val);
        } else if (choice == 2) {
            pop1(ts);
        } else if (choice == 3) {
            scanf("%d", &val);
            push2(ts, val);
        } else if (choice == 4) {
            pop2(ts);
        } else if (choice == 5) {
            break;
        }
    }
    printStacks(ts);

    free(ts->arr);
    free(ts);
    return 0;
}
