#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct QN{
    int data;
    struct QN *next;
};
struct QN *front=NULL;
struct QN *rear=NULL;

void EnQueue(int value){
    struct QN*tmp=(struct QN*)malloc(sizeof(struct QN));
    tmp->next=NULL;
    tmp->data=value;

    if(front==NULL){
        front=tmp;
        rear=tmp;
        //tmp->next=NULL;
    }
    else{
        //tmp->next=NULL
        rear->next=tmp;
        rear=tmp;
    }
    //printf("%d",rear->data);
}
void DeQueue(){
    if(front==NULL){
        printf("Queue Empty");
    }
    else{
    struct QN *tmp=front;
    front=front->next;
    free(tmp);
    }
}
void printAll(){
    struct QN *p=front;
    while(p!=NULL){
        printf("%d->",p->data);
        p=p->next;
    }
}

void main(){

    for(;;){
    int num;
    printf("Enter 1 for EnQueue or 2 for DeQueue and 3 for print and 5 for exit : ");
    scanf("%d",&num);
    if(num==1){
        int val;
        printf("Enter value : ");
        scanf("%d",&val);
        EnQueue(val);
    }
    else if(num==2){
        DeQueue();

    }
    else if(num==3){
        printAll();
    }
    else if(num==4){
        break;
    }
    }
}
