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

void splitOddEvenNodes(Node *head, Node **oddList, Node **evenList) {
    if (head == NULL) return;

    Node *oddHead = NULL, *oddTail = NULL;
    Node *evenHead = NULL, *evenTail = NULL;
    Node *curr = head;
    int index = 1;

    while (curr != NULL) {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = curr->data;
        newNode->next = NULL;

        if (index % 2 != 0) { // Odd position
            if (oddHead == NULL) {
                oddHead = oddTail = newNode;
            } else {
                oddTail->next = newNode;
                oddTail = newNode;
            }
        } else { // Even position
            if (evenHead == NULL) {
                evenHead = evenTail = newNode;
            } else {
                evenTail->next = newNode;
                evenTail = newNode;
            }
        }
        curr = curr->next;
        index++;
    }
    *oddList = oddHead;
    *evenList = evenHead;
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

    printList(head, "Original List");

    Node *oddList = NULL, *evenList = NULL;
    splitOddEvenNodes(head, &oddList, &evenList);

    printList(oddList, "Odd numbered nodes list");
    printList(evenList, "Even numbered nodes list");

    return 0;
}
