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
    struct Node *prev;
    struct Node *next;
} Node;

Node* insertEnd(Node *head, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (head == NULL) return newNode;
    Node *temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

Node* reverseDLL(Node *head) {
    Node *temp = NULL;
    Node *current = head;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL) {
        head = temp->prev;
    }
    return head;
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
    int choice, val;

    while (1) {
        if (scanf("%d", &choice) != 1) break;
        if (choice == 1) {
            scanf("%d", &val);
            head = insertEnd(head, val);
        } else if (choice == 2) {
            break;
        }
    }

    printList(head, "Doubly Linked List");
    head = reverseDLL(head);
    printList(head, "Rversed Doubly Linked List");

    return 0;
}
