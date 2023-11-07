#include<stdio.h>
#include<conio.h>
#define N 5

int queue[N];
int rear=0;
int front=0;
void EnQueue(int value){

    if(rear==N){
        printf("Queue Full");
        rear=0;
    }
    else{
        queue[rear]=value;
        rear++;
    }
}
void DeQueue(){
    if(rear==0){
        printf("Queue Empty");

    }
    else if(front<=N){
        queue[front]=queue[rear];
        front++;


    }
    else{
        printf("Index Ont");
    }
}
void main(){
    for(;;){
    int num;
    printf("Enter 1 for EnQueue or 2 for DeQueue and 3 for print and 4 for exit : ");
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
        int i;
        for(i=0;i<5;i++){
            printf("%d ",queue[i]);
        }
    }
    else if(num==4){
        break;
    }
    }
}
