#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* insertEnd(Node *head, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = newNode;
    if (head == NULL) return newNode;
    Node *temp = head;
    while (temp->next != head) temp = temp->next;
    temp->next = newNode;
    newNode->next = head;
    return head;
}

Node* concatenateCLL(Node *head1, Node *head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    Node *last1 = head1;
    while (last1->next != head1) last1 = last1->next;

    Node *last2 = head2;
    while (last2->next != head2) last2 = last2->next;

    last1->next = head2;
    last2->next = head1;

    return head1;
}

void printCLL(Node *head, const char *title) {
    printf("%s :", title);
    if (head == NULL) {
        printf("\n");
        return;
    }
    Node *temp = head;
    do {
        printf(" %d", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    Node *head1 = NULL;
    Node *head2 = NULL;
    int choice, val;

    // Read list 1
    while (1) {
        if (scanf("%d", &choice) != 1) break;
        if (choice == 1) {
            scanf("%d", &val);
            head1 = insertEnd(head1, val);
        } else if (choice == 2) {
            break;
        }
    }

    // Read list 2
    while (1) {
        if (scanf("%d", &choice) != 1) break;
        if (choice == 1) {
            scanf("%d", &val);
            head2 = insertEnd(head2, val);
        } else if (choice == 2) {
            break;
        }
    }

    printCLL(head1, "First circular linked list");
    printCLL(head2, "Second circular linked list");

    Node *concat = concatenateCLL(head1, head2);
    printCLL(concat, "Final Concatenaed linked list");

    return 0;
}
