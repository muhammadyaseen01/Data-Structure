#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
char postfix[30];
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
int prece(char alpha){
    if(alpha=="+"|| alpha=="-"){
        return 1;
    }
    else if(alpha=="*"|| alpha=="/"){
        return 2;
    }
    else if(alpha=="<"|| alpha==">"){
        return 3;
    }
    else if(alpha=="&"|| alpha=="|"){
        return 4;
    }
}

void evalut(){
    for(int i=0;i<30;i++){
    if(postfix[i]>= 'a' && postfix[i]<= 'z'){
        push(postfix[i]);
    }
    else{
        int R=pop();
        int L=pop();
        char operato=postfix[i]
        int result= R operato L;
        push(result);
    }
}
}


void main(){

    printf("Enter Postfix Experssion");
    scanf("%c",&postfix);
    printf("%c",postfix);
}
