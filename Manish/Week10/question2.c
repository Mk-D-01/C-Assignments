#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* insertEnd(Node *head, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) return newNode;
    Node *temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    return head;
}

void findNthFromEnd(Node *head, int n) {
    Node *fast = head;
    Node *slow = head;

    for (int i = 0; i < n; i++) {
        if (fast == NULL) {
            printf("Position out of bounds\n");
            return;
        }
        fast = fast->next;
    }

    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    printf("Value at position %d from end : %d\n", n, slow->data);
}

void printList(Node *head, const char *title) {
    printf("%s :", title);
    Node *temp = head;
    while (temp != NULL) {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node *head = NULL;
    int choice, val, n;

    while (1) {
        if (scanf("%d", &choice) != 1) break;
        if (choice == 1) {
            scanf("%d", &val);
            head = insertEnd(head, val);
        } else if (choice == 2) {
            break;
        }
    }
    scanf("%d", &n);

    printList(head, "Linked List");
    findNthFromEnd(head, n);

    return 0;
}
