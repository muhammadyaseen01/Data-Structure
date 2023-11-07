//Aoun Ullah Khan
//B20103013
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct BTNode{
    char character;
    struct BTNode* left;
    struct BTNode* right;

} BTNode;

BTNode * stack[100];
int top = -1;

BTNode * newBTNode (char character){
    BTNode * temp = (BTNode*)malloc(sizeof(BTNode));
    temp->character = character;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void push( BTNode * character){
    if ( top >= 99){
        return;
    }
    else {
        top ++;
        stack[top] = character;
    }
}

BTNode * pop(){
    if (top <= -1 ){
        printf("stack is empty ");
    }
    else {
        BTNode* a= stack[top];
        top-=1;
        return a;
    }
}

void displayStack(){
    if (top >= 0 ){
        for (int i = top; i>=0; i--){
            printf(" %c ", stack[i]->character);
        }
    }
}
void printInorder(struct BTNode* node){

    if (node == NULL)
        return;
    else{
        printInorder(node->left);

        printf("%c ", node->character);

        printInorder(node->right);
    }
}

void printPostOrder(BTNode * node){

    if (node == NULL){
        return;
    }
    else{
        printPostOrder(node->left);
        printPostOrder(node->right);
        printf("%c ", node->character);
    }
}





void main(){
    char s[] = {'A','B','C','*','+','D','/'};   //expression here
    int size = sizeof(s)/sizeof(s[0]);
    BTNode * x;
    BTNode *  y;
    BTNode *  z;

    for (int i= 0; i<=size-1; i++){
        if (s[i] == '+' || s[i] == '-' || s[i] == '*'|| s[i] == '/' || s[i] == '^'){
            z = newBTNode(s[i]);
            x = pop();
            y = pop();
            z->right = x;
            z->left = y;
            push(z);
        }
        else{
            z = newBTNode(s[i]);
            push(z);
        }
    }
    printf("Post order: ");
    printPostOrder(z);
    printf("\nInorder: ");
    printInorder(z);

}
