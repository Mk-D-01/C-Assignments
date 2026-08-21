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

void splitCLL(Node *head, int k, Node **head1, Node **head2) {
    if (head == NULL) return;

    Node *temp = head;
    for (int i = 1; i < k && temp->next != head; i++) {
        temp = temp->next;
    }

    *head1 = head;
    *head2 = temp->next;

    Node *last = temp->next;
    while (last->next != head) last = last->next;

    temp->next = *head1;
    last->next = *head2;
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
    Node *head = NULL;
    int choice, val, k;

    while (1) {
        if (scanf("%d", &choice) != 1) break;
        if (choice == 1) {
            scanf("%d", &val);
            head = insertEnd(head, val);
        } else if (choice == 2) {
            break;
        }
    }
    scanf("%d", &k);

    printCLL(head, "Original List");

    Node *head1 = NULL, *head2 = NULL;
    splitCLL(head, k, &head1, &head2);

    printCLL(head1, "First part of list");
    printCLL(head2, "Second part of list");

    return 0;
}
