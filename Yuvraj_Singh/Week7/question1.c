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

Node* createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(Node *head) {
    printf("Linked List -");
    Node *temp = head;
    while (temp != NULL) {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void printListWithMsg(Node *head, const char *msg) {
    printf("%s -", msg);
    Node *temp = head;
    while (temp != NULL) {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int getSize(Node *head) {
    int size = 0;
    Node *temp = head;
    while (temp != NULL) {
        size++;
        temp = temp->next;
    }
    return size;
}

Node* insertFront(Node *head, int data) {
    Node *newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

Node* insertEnd(Node *head, int data) {
    Node *newNode = createNode(data);
    if (head == NULL) return newNode;
    Node *temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    return head;
}

Node* insertAnywhere(Node *head, int data, int pos) {
    if (pos == 1) return insertFront(head, data);
    Node *newNode = createNode(data);
    Node *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) return head;
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

Node* deleteFront(Node *head) {
    if (head == NULL) return NULL;
    Node *temp = head;
    printf("Node deleted - %d\n", temp->data);
    head = head->next;
    free(temp);
    return head;
}

Node* deleteEnd(Node *head) {
    if (head == NULL) return NULL;
    if (head->next == NULL) {
        printf("Node deleted - %d\n", head->data);
        free(head);
        return NULL;
    }
    Node *temp = head;
    while (temp->next->next != NULL) temp = temp->next;
    printf("Node deleted - %d\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
    return head;
}

Node* deleteAnywhere(Node *head, int pos) {
    if (head == NULL) return NULL;
    if (pos == 1) return deleteFront(head);
    Node *temp = head;
    for (int i = 1; i < pos - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }
    if (temp->next == NULL) return head;
    Node *toDelete = temp->next;
    printf("Node deleted - %d\n", toDelete->data);
    temp->next = toDelete->next;
    free(toDelete);
    return head;
}

void findMiddle(Node *head) {
    if (head == NULL) return;
    Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    printf("Middle element - %d\n", slow->data);
}

int main() {
    Node *head = NULL;
    int choice, val, pos;

    while (1) {
        if (scanf("%d", &choice) != 1) break;
        if (choice == 1) {
            scanf("%d", &val);
            head = insertFront(head, val);
            printList(head);
        } else if (choice == 2) {
            scanf("%d", &val);
            head = insertEnd(head, val);
            printList(head);
        } else if (choice == 3) {
            scanf("%d %d", &val, &pos);
            head = insertAnywhere(head, val, pos);
            printList(head);
        } else if (choice == 4) {
            head = deleteFront(head);
            printListWithMsg(head, "Linked List after deletion");
        } else if (choice == 5) {
            head = deleteEnd(head);
            printListWithMsg(head, "Linked List after deletion");
        } else if (choice == 6) {
            scanf("%d", &pos);
            head = deleteAnywhere(head, pos);
            printListWithMsg(head, "Linked List after deletion");
        } else if (choice == 7) {
            printf("Size = %d\n", getSize(head));
        } else if (choice == 8) {
            findMiddle(head);
        } else if (choice == 9) {
            break;
        }
    }

    return 0;
}
