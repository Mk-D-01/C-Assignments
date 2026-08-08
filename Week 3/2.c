#include <stdio.h>
#include <string.h>
int max = 5;
int top;
void create(){
    top = -1;

}
void push(int arr[],int num){
    
    if(top == max-1){printf("Over Flow");}
    else if(top == -1){top = 0;arr[top] == num;}
    else{top++;arr[top] = num;}
}

int pop(int arr[]){
    if(top == -1){printf("Under Flow");}
    
    return arr[top--];
}

void emt(){
    if(top == -1){printf("Stack Is Empty Mate");}else{printf("Ain't Empty Mate");}}

void size(){printf("Mate the Stack is of %d layers thick",top+1);}

void p(int arr[]){
    for(int i = top; i>=0; i--){
        printf("%d ",arr[i]);
    }
}
int main(){
    
    char entry[] = {"({{[]}})"};
    int arr[strlen(entry)];
    create();


    for(int i = 0; i < strlen(entry); i++){
        if((entry[i] == ']' || entry[i] == ')'|| entry[i] == '}') & top==-1 ) {
            printf("Unequal");
        }
        else if(entry[i] == '{' || entry[i] == '('|| entry[i] == '[' ){
            push(&arr[max],entry[i]);
        }
        else if(entry[i] == "{" && arr[top] == "}"){pop(&arr[max]);}
        else if(entry[i] == ")" && arr[top] == ")"){pop(&arr[max]);}
        else if(entry[i] == "[" && arr[top] == "]"){pop(&arr[max]);}
    }

    p(arr);
    if(top == -1){printf("Unequal");}
    else{printf("equal");}
}