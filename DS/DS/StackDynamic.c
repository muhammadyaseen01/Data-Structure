#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct SD{
    int data;
    struct SD *next;
};
struct SD *top;
struct SD *start;

void push(int value){
    struct SD *tmp=(struct SD*)malloc(sizeof(struct SD));
    tmp->data=value;
    tmp->next=NULL;
    if(top==NULL){
        top=tmp;

    }
    else{
        tmp->next=top;
        top=tmp;
    //printf("\n%d",start->data);
    }
}

void pop(){
    if(top==NULL){
        printf("Stack Underflow");
    }
    else{
        struct SD *tmp;
        tmp=top;
        top=top->next;
        free(tmp);

    }
}

void printAll(){
    struct SD *p=top;
    while(p!=NULL){
        printf("%d->",p->data);
        p=p->next;
    }
    }


void main(){
    for(;;){
    int num;
    printf("Enter 1 for push 2 for pop and 3 for exit : ");
    scanf("%d",&num);
    if(num==1){
        int val;
        printf("Enter Number : ");
        scanf("%d",&val);
        push(val);
    }
    else if(num==2){
        pop();
        //int a;
        //a=pop();
        //printf("%d",a);
    }
    else if(num==3){
        printAll();
    }
    }
}

