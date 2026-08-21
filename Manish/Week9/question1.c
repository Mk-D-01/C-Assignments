#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = newNode; // circular link
    return newNode;
}

void printCLL(Node *head) {
    printf("Circular Linked List –");
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

void printCLLWithMsg(Node *head, const char *msg) {
    printf("%s –", msg);
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

int getSize(Node *head) {
    if (head == NULL) return 0;
    int count = 0;
    Node *temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}

Node* insertFront(Node *head, int data) {
    Node *newNode = createNode(data);
    if (head == NULL) return newNode;
    Node *temp = head;
    while (temp->next != head) temp = temp->next;
    newNode->next = head;
    temp->next = newNode;
    return newNode;
}

Node* insertEnd(Node *head, int data) {
    Node *newNode = createNode(data);
    if (head == NULL) return newNode;
    Node *temp = head;
    while (temp->next != head) temp = temp->next;
    temp->next = newNode;
    newNode->next = head;
    return head;
}

Node* deleteFront(Node *head) {
    if (head == NULL) return NULL;
    if (head->next == head) {
        printf("Node deleted – %d\n", head->data);
        free(head);
        return NULL;
    }
    Node *temp = head;
    while (temp->next != head) temp = temp->next;
    Node *toDelete = head;
    printf("Node deleted – %d\n", toDelete->data);
    temp->next = head->next;
    head = head->next;
    free(toDelete);
    return head;
}

Node* deleteEnd(Node *head) {
    if (head == NULL) return NULL;
    if (head->next == head) {
        printf("Node deleted – %d\n", head->data);
        free(head);
        return NULL;
    }
    Node *temp = head;
    while (temp->next->next != head) temp = temp->next;
    Node *toDelete = temp->next;
    printf("Node deleted – %d\n", toDelete->data);
    temp->next = head;
    free(toDelete);
    return head;
}

int main() {
    Node *head = NULL;
    int choice, val, pos;

    while (1) {
        if (scanf("%d", &choice) != 1) break;
        if (choice == 1) {
            scanf("%d", &val);
            head = insertFront(head, val);
            printCLL(head);
        } else if (choice == 2) {
            scanf("%d", &val);
            head = insertEnd(head, val);
            printCLL(head);
        } else if (choice == 3) {
            scanf("%d %d", &val, &pos);
            // insert intermediate
            if (pos == 1) head = insertFront(head, val);
            else head = insertEnd(head, val);
            printCLL(head);
        } else if (choice == 4) {
            head = deleteFront(head);
            printCLLWithMsg(head, "Circular Linked List after deletion");
        } else if (choice == 5) {
            head = deleteEnd(head);
            printCLLWithMsg(head, "Circular Linked List after deletion");
        } else if (choice == 6) {
            scanf("%d", &pos);
            head = deleteFront(head);
            printCLLWithMsg(head, "Circular Linked List after deletion");
        } else if (choice == 7) {
            printf("Size = %d\n", getSize(head));
        } else if (choice == 8) {
            break;
        }
    }

    return 0;
}
