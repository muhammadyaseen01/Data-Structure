#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct BTNode{
    char data;
    struct BTNode *leftchild;
    struct BTNode *rightchild;
};
struct BTNode *root=NULL;

struct BTNode *stack[10];
int top=0;

void push(struct BTNode *node){
    if(top==10){
        printf("Stack Overflow");
    }

    else{
        stack[top]=node;
        top++;
    }
}

struct BTNode* pop(){
    if(top==0){
        printf("Stack Underflow");
    }
    else{
        top--;
        return stack[top];
    }
}
void operand(char b){
    struct BTNode *tmp=(struct BTNode*)malloc(sizeof(struct BTNode));
    tmp->data=b;
    tmp->leftchild=NULL;
    tmp->rightchild=NULL;
    push(tmp);
}
void operators(char a){
    struct BTNode *tmp=(struct BTNode*)malloc(sizeof(struct BTNode));
    tmp->data=a;
    tmp->leftchild=pop();
    tmp->rightchild=pop();
    push(tmp);
}

void PostOrder(struct BTNode *Node){
    if(Node!=NULL){
        PostOrder(Node->leftchild);
        PostOrder(Node->rightchild);
        printf("%d ",Node->data);
    }
}
/*
void ExpTree(char n){
    struct BTNode *tmp=(struct BTNode*)malloc(sizeof(struct BTNode));
    tmp->data=n;
    tmp->leftchild=NULL;
    tmp->rightchild=NULL;
    char symbol[10];
    for(int i=0;i<30;i++){
    if(infix[i]>= 'A' && infix[i]<= 'Z'){
        push(infix [i]);
    }
    else if(infix[i]=="+"||infix[i]=="-"||infix[i]=="*"||infix[i]=="/"){
        symbol[i]=infix[i];
    }
    else if(top!=NULL){
        rchild=pop();
        lxhild=pop();
    }
}
}
*/
void main(){
    char infix[]={"A+B*C"};
    for(int i=0;i<5;i++){
        if(infix[i]>= 'A' && infix[i]<= 'Z'){
            operand(infix[i]);
        }
        else if(infix[i]=="+"||infix[i]=="-"||infix[i]=="*"||infix[i]=="/"){
            operators(infix[i]);
        }
    }
PostOrder(stack[top]);
}
    //PostOrder(root);

