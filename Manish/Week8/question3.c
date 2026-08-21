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

void removeDuplicates(Node *head) {
    Node *ptr1, *ptr2, *duplicate;
    ptr1 = head;

    while (ptr1 != NULL && ptr1->next != NULL) {
        ptr2 = ptr1;
        while (ptr2->next != NULL) {
            if (ptr1->data == ptr2->next->data) {
                duplicate = ptr2->next;
                ptr2->next = ptr2->next->next;
                if (ptr2->next != NULL) {
                    ptr2->next->prev = ptr2;
                }
                free(duplicate);
            } else {
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
    }
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
    removeDuplicates(head);
    printList(head, "Doubly Linked List after duplicate removal");

    return 0;
}
