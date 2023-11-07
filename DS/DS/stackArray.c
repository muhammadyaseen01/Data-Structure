#include<stdio.h>
#include<conio.h>

int stack[5];
int top=0;

void push(int value){
    if(top==5){
        printf("Stack Overflow");
    }

    else{
        stack[top]=value;
        top++;
    }
}

int pop(){
    if(top==0){
        printf("Stack Underflow");
    }
    else{
        top--;
        return stack[top];
    }
}

void main(){
    for(;;){
    int num;
    printf("Enter 1 for push or 2 for pop and 3 for print and 4 for exit : ");
    scanf("%d",&num);
    if(num==1){
        int val;
        printf("Enter value : ");
        scanf("%d",&val);
        push(val);
    }
    else if(num==2){
        int a=pop();
        printf("%d\n",a);
    }
    else if(num==3){
        int i;
        for(i=0;i<3;i++){
            printf("%d ",stack[i]);
        }
    }
    else if(num==4){
        break;
    }
    }
}
