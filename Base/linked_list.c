#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* push(int val,struct Node *head)
{
   
    struct Node *n = (struct Node *)malloc(sizeof(struct Node *));
    n->data = val;
    n = &head;
    head = &n;
}
 


int main(){
    struct Node *head;
    head->data = NULL;


   
}
