#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct AVLNode{
    int data;
    struct AVLNode *leftchild;
    struct AVLNode *rightchild;
    int height;
};
struct AVLNode *root=NULL;

struct AVLNode * rotateLeft(struct AVLNode *curr){
    struct AVLNode *tmp=curr;
    curr=curr->rightchild;
    struct AVLNode *tmp2=curr->leftchild;
    curr->leftchild=tmp;
    tmp->rightchild=tmp2;
    return curr;
}
struct AVLNode *rotateRight(struct AVLNode *curr){
    struct AVLNode *tmp=curr;
    curr=curr->leftchild;
    struct AVLNode *tmp2=curr->rightchild;
    curr->rightchild=tmp;
    tmp->leftchild=tmp2;
    return curr;
}
struct AVLNode *rotateRightLeft(struct AVLNode *curr){
    rotateRight(curr->rightchild);
    rotateLeft(curr);
    return curr;
}
struct AVLNode *rotateLeftRight(struct AVLNode *curr){
    rotateLeft(curr->leftchild);
    rotateRight(curr);
    return curr;
}
int maxi(int lh,int rh){
    if(lh>rh){
        return lh;
    }
    else{
        return rh;
    }
}

int height(struct AVLNode* n )
{
    if( n == NULL )
        return -1;
    else
        return n->height;
}
struct AVLNode * insertAVL(struct AVLNode *node,int value){
    struct AVLNode *tmp=(struct AVLNode*)malloc(sizeof(struct AVLNode));
    tmp->data=value;
    tmp->leftchild=NULL;
    tmp->rightchild=NULL;
    tmp->height=0;
    if(node==NULL){
        return tmp;
        }
    if(value < node->data){
        node->leftchild=insertAVL(node->leftchild,value);
        printf("No1");
        if(height(tmp->leftchild) - height(tmp->rightchild)==2){
            printf("No2");
            if(value < node->leftchild->data){
                printf("No3");
                node=rotateRight(node);
                printf("No4");

            }
            else{
                node=rotateLeftRight(node);
                printf("No5");

            }
        }
    }
    else{
        node->rightchild=insertAVL(node->rightchild,value);
        if((height(tmp->leftchild) - height(tmp->rightchild))==2){
            if(value < node->rightchild->data){
                node=rotateLeft(node);
            }
            else{
                node=rotateRightLeft(node);
            }
        }
    }
 node->height=maxi(node->leftchild->height,node->rightchild->height)+1;
 return node;
}

void InOrder(struct AVLNode *Node){
    if(Node!=NULL){
        InOrder(Node->leftchild);
        printf("%d ",Node->data);
        InOrder(Node->rightchild);
    }
}
void PreOrder(struct AVLNode *Node){
    if(Node!=NULL){
        printf("%d ",Node->data);
        PreOrder(Node->leftchild);
        PreOrder(Node->rightchild);
    }
}
void PostOrder(struct AVLNode *Node){
    if(Node!=NULL){
        PostOrder(Node->leftchild);
        PostOrder(Node->rightchild);
        printf("%d ",Node->data);
    }
}
void main(){
   int choise,n;
    for(;;){
    printf("Enter 1 for insert 2 for InOrder,3 for PreOrder,4 for PostOrder and 5 for Search and 6 for delete: \n");
    scanf("%d",&choise);
    if (choise==1){
        printf("Enter Number");
        scanf("%d",&n);
        root=insertAVL(root,n);
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
}
}
