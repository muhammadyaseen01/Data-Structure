//Aoun Ullah Khan
//B20103013
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct BTNode{
    int data;
    struct BTNode *leftchild;
    struct BTNode *rightchild;
};
struct BTNode *root=NULL;


struct BTNode* Insert(struct BTNode *root,int n){
    struct BTNode *tmp=(struct BTNode*)malloc(sizeof(struct BTNode));
    tmp->data=n;
    tmp->leftchild=NULL;
    tmp->rightchild=NULL;
    if(root==NULL){
        root=tmp;
        return root;
    }
    else {
            if(n < root->data )
            root->leftchild = Insert(root->leftchild,n);
        else if(n > root->data )
            root->rightchild = Insert(root->rightchild,n);
        return(root);
    }
}


void InOrder(struct BTNode *Node){
    if(Node!=NULL){
        InOrder(Node->leftchild);
        printf("%d ",Node->data);
        InOrder(Node->rightchild);
    }
}
void PreOrder(struct BTNode *Node){
    if(Node!=NULL){
        printf("%d ",Node->data);
        PreOrder(Node->leftchild);
        PreOrder(Node->rightchild);
    }
}
void PostOrder(struct BTNode *Node){
    if(Node!=NULL){
        PostOrder(Node->leftchild);
        PostOrder(Node->rightchild);
        printf("%d ",Node->data);
    }
}

void search(struct BTNode *root,int value){
        int flag=0;
        if(value<root->data){
            search(root->leftchild,value);
        }
        else if(value>root->data){
            search(root->rightchild,value);
        }
        else if(value==root->data){
            flag=1;
            printf("yes\n");
        }
        if(flag==0){
            printf("Not Found");
        }
}

void main(){
    int choise,n;
    for(;;){
    printf("Enter 1 for insert 2 for InOrder,3 for PreOrder,4 for PostOrder and 5 for Search : \n");
    scanf("%d",&choise);
    if (choise==1){
        printf("Enter Number");
        scanf("%d",&n);
        root=Insert(root,n);
    }
    else if(choise==2){
        InOrder(root);
    }
    else if(choise==3){
        PreOrder(root);
    }
    else if(choise==4){
        PostOrder(root);
    }
    else if(choise==5){
        int value;
        printf("Enter Number");
        scanf("%d",&value);
        search(root,value);
    }
}
}
