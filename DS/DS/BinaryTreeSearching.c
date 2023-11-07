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

void insert(int n){
    struct BTNode *tmp=(struct BTNode*)malloc(sizeof(struct BTNode));

    tmp->data=n;
    tmp->leftchild=NULL;
    tmp->rightchild=NULL;

    if(root==NULL){
        root=tmp;
    }
    else{
        struct BTNode *curr=root;
        while(1){
            if(tmp->data<curr->data){
                if(curr->leftchild==NULL){
                    curr->leftchild=tmp;
                    break;
                }
                else{
                    curr=curr->leftchild;
                }
            }
            else{
                if(curr->rightchild==NULL){
                    curr->rightchild=tmp;
                    break;
                }
                else{
                    curr=curr->rightchild;
                }
            }
        }
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

void Search(int value){
    struct BTNode *tmp=root;
    int flag=0;
    while (1){
        if(value<tmp->data){
            tmp=tmp->leftchild;
        }
        else if(value>tmp->data){
            tmp=tmp->rightchild;
        }
        else if(value==tmp->data){
            printf("YES");
            flag=1;
            break;
        }
    }
}
struct BTNode* Ssmall(struct BTNode *right){
        struct BTNode *curr=right;
        while(curr->leftchild!=NULL){
                curr=curr->leftchild;
            }
            return curr;
        }

struct BTNode* delete(struct BTNode *tmp,int todelete){
    if(root==NULL){
        printf("Not Found\n");
        return root;
    }
    else{
        if(todelete<tmp->data){
           tmp->leftchild=delete(tmp->leftchild,todelete);
        }
        else if(todelete>tmp->data){
            tmp->rightchild=delete(tmp->rightchild,todelete);
        }
        else if(todelete==tmp->data){
            if(tmp->leftchild==NULL && tmp->rightchild==NULL){
                free(tmp);
                tmp=NULL;
                return tmp;
        }
            else if(tmp->leftchild==NULL){
                struct BTNode *curr=tmp->rightchild;
                free(tmp);
                return curr;
            }
            else if(tmp->rightchild==NULL){
                struct BTNode *curr=tmp->leftchild;
                free(tmp);
                return tmp;
            }
            else{
                struct BTNode *curr=Ssmall(tmp->rightchild);
                tmp->data=curr->data;
                tmp->rightchild=delete(tmp->rightchild,curr->data);

            }

    }
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
        insert(n);
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
        Search(value);
    }
    else if(choise==6){
        int value;
        printf("Enter Number");
        scanf("%d",&value);
        root=delete(root,value);
    }
}
}
