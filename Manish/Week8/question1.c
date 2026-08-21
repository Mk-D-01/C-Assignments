#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node* createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void printList(Node *head) {
    printf("Doubly Linked List -");
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
    if (head != NULL) {
        newNode->next = head;
        head->prev = newNode;
    }
    return newNode;
}

Node* insertEnd(Node *head, int data) {
    Node *newNode = createNode(data);
    if (head == NULL) return newNode;
    Node *temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

Node* insertIntermediate(Node *head, int data, int pos) {
    if (pos == 1) return insertFront(head, data);
    Node *newNode = createNode(data);
    Node *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) return head;
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) temp->next->prev = newNode;
    temp->next = newNode;
    return head;
}

Node* deleteFront(Node *head) {
    if (head == NULL) return NULL;
    Node *temp = head;
    printf("Node deleted - %d\n", temp->data);
    head = head->next;
    if (head != NULL) head->prev = NULL;
    free(temp);
    return head;
}

Node* deleteEnd(Node *head) {
    if (head == NULL) return NULL;
    Node *temp = head;
    while (temp->next != NULL) temp = temp->next;
    printf("Node deleted - %d\n", temp->data);
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        head = NULL;
    }
    free(temp);
    return head;
}

Node* deleteIntermediate(Node *head, int pos) {
    if (head == NULL) return NULL;
    if (pos == 1) return deleteFront(head);
    Node *temp = head;
    for (int i = 1; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) return head;
    printf("Node deleted - %d\n", temp->data);
    if (temp->prev != NULL) temp->prev->next = temp->next;
    if (temp->next != NULL) temp->next->prev = temp->prev;
    free(temp);
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
            head = insertIntermediate(head, val, pos);
            printList(head);
        } else if (choice == 4) {
            head = deleteFront(head);
            printListWithMsg(head, "Doubly Linked List after deletion");
        } else if (choice == 5) {
            head = deleteEnd(head);
            printListWithMsg(head, "Doubly Linked List after deletion");
        } else if (choice == 6) {
            scanf("%d", &pos);
            head = deleteIntermediate(head, pos);
            printListWithMsg(head, "Doubly Linked List after deletion");
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
