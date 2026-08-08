#include <stdio.h>

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
    int arr[max];
    
    while(1){
        int n;
    printf("1 : Create\n2 : Push\n3 : Pop\n 4 : Is Empty\n5 : Size \n6 : Print");
    printf("\n Enter Choice -> ");scanf("%d",&n);

    switch(n){
        
        case 1 : create();printf("\n");break;
        case 2 : int num; printf("Enter Num ->");scanf("%d",&num);push(arr,num);printf("\n");break;
        case 3 : printf("%d",pop(arr));printf("\n");break;
        case 4 : emt();printf("\n");break;
        case 5 : size();printf("\n");break;
        case 6 : p(arr);printf("\n");break;




    }
}

}