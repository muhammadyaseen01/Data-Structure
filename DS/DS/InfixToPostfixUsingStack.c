#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
char infix[20],postfix[20];
struct SD{
    char data;
    struct SD *next;
};
struct SD *top;
struct SD *start;

void push(char value){
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

char pop(){
    if(top==NULL){
        printf("Stack Underflow");
    }
    else{
        struct SD *tmp;
        tmp=top;
        top=top->next;
        return top->data;
        free(tmp);

    }
}

void printAll(){
    struct SD *p=top;
    while(p!=NULL){
        printf("%c",p->data);
        p=p->next;
    }
}

int prece(char alpha){
    if(alpha=="+"|| alpha=="-"){
        return 1;
    }
    else if(alpha=="*"|| alpha=="/"){
        return 2;
    }
}
void InfixToPostfix(){
    struct SD *tmp=top;
    for(int i=0;i<5;i++){
        if(infix[i]>= 'a' && infix[i]<= 'z'){
            postfix[i]=infix[i];
        }
        else{
            if(top==NULL){
                push(infix[i]);
            }
            else if(prece(infix[i]>prece(top->data))){
                push(infix[i]);
            }
            else if(prece(infix[i]<prece(top->data))){
                postfix[i]=pop();
                push(infix[i]);
            }
            else if(prece(infix[i])==prece(top)){
                postfix[i]=pop();
                push(infix[i]);
            }
            else{
                postfix[i]=pop();
            }
        }

    }
}


void main(){
    printf("Enter The Expression: ");
    scanf("%s",&infix);
    InfixToPostfix();
    for(int i=0;i<5;i++){
    printf("%c",postfix[i]);
    }

}

