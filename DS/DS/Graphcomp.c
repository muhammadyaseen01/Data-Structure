#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Edge{
    struct Vertex *ver;
    struct Edge *nextedge;
};
struct Vertex{
    int data;
    struct Vertex *nextvertex;
    struct Edge *edgelist;//isert edge here
};
struct Vertex *start=NULL;
void VerInsert(int value){
    struct Vertex *tmp=(struct Vertex*)malloc(sizeof(struct Vertex));

    tmp->data=value;
    tmp->nextvertex=NULL;
    tmp->edgelist=NULL;
    if(start==NULL){
         start=tmp;
    }
    else{
        struct Vertex *curr=start;
        while(curr->nextvertex!=NULL){
            curr=curr->nextvertex;
        }
        curr->nextvertex=tmp;
    }
}
void VprintAll(){
    struct Vertex *p=start;
    while(p!=NULL){
        //printf("%s ",p->TName);
        printf("%d->",p->data);
        p=p->nextvertex;
    }
    }
struct Vertex* SearchV(int curs){
    struct Vertex *co=start;
    if(start==NULL){
        printf("Enter Course!\n");
    }
    else{
        //struct Course *co=start;
        while(co!=NULL){
            if(curs==co->data){
                //printf("YES");
                return co;
            }
        co=co->nextvertex;

    }
    }
}

void EdgInsert(int ver,int edg){
    struct Edge *tmp=(struct Edge*)malloc(sizeof(struct Edge));
    struct Vertex *currv,*curre,*sta=start;
    while(sta!=NULL){
        if(sta->data==ver){
            currv=SearchV(ver);
        }
        sta=sta->nextvertex;
    }
    curre=SearchV(edg);
    tmp->ver=curre;
    tmp->nextedge=NULL;
   if(currv->edgelist==NULL){
     currv->edgelist=tmp;
   }
   else{
    struct Edge *curr=currv->edgelist;
        while(curr->nextedge!=NULL){
            curr=curr->nextedge;
        }
        curr->nextedge=tmp;
        }

}
void showAll(){

    struct Vertex *curr = start;
    while(curr != NULL){
        printf("\n\n\t%d",curr->data);
        if(curr->edgelist != NULL){
            //cout <<"it has an array";
            if(curr->edgelist->nextedge == NULL){
                printf("\t%d",curr->edgelist->ver->data);
            }
            else{
                struct Edge *ptr = curr->edgelist;
                while(ptr != NULL){
                     printf("\t%d", ptr->ver->data);
                     ptr = ptr->nextedge;
                }
            }
        }
        else{
            printf("\tEmpty");
        }
        curr = curr->nextvertex;
    }
}
//---------STACK----------
struct SD{
    int data;
    struct SD *next;
};
struct SD *top;
struct SD *Start;

void push(int value){
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

void pop(){
    if(top==NULL){
        printf("Stack Underflow");
    }
    else{
        struct SD *tmp;
        tmp=top;
        top=top->next;
        free(tmp);

    }
}
void display(int val){
    printf("%d ",val);
}
void path(int ver1,int ver2){
    struct Vertex *curr1=SearchV(ver1);
    struct Vertex *curr=curr1;
   // struct Vertex *curr2=SearchV(ver2);
   //display(curr1->data);
    struct Vertex *sta=start;
    int flag=0;
    //struct Vertex *curr=curr1->edgelist->ver->data;
    while(curr1->edgelist!=NULL){
    if(curr1->edgelist->ver->data==ver2){
            display(curr1->edgelist->ver->data);
            int flag=1;
            struct SD *tmp=Start;
            while(tmp!=NULL){
                pop();
                tmp=tmp->next;
            }
    }
    else{
        struct Vertex *tmp=curr1->edgelist->ver;
        push(tmp->data);
        display(tmp->data);
        path(tmp->data,ver2);
    }
    curr1->edgelist=curr1->edgelist->nextedge;
}
    if(flag==0){
        if(curr->edgelist->nextedge==NULL){
            struct SD *tmp1=Start;
            while(tmp1!=NULL){
                pop();
                tmp1=tmp1->next;
                printf("y");
        }
        }
        else{
        struct Vertex *tmp=curr->edgelist->ver;
        printf("Y");
        path(tmp->data,ver2);
    }
    }
}
void main(){
    for(;;){
    int choise;
    printf("Enter 1 For Vertex And 2 For Edge Insert : ");
    scanf("%d",&choise);
    if(choise==1){
    int val;
    printf("Enter Vertex Name : ");
    scanf("%d",&val);
    VerInsert(val);
    }
    else if(choise==2){
        VprintAll();
    }
    else if(choise==3){
    int val,edg;
    printf("Enter Vertex : ");
    scanf("%d",&val);
    printf("Enter Edge to insert : ");
    scanf("%d",&edg);
    EdgInsert(val,edg);
    }
    else if(choise==4){
    showAll();
}
    else if(choise==5){
    int var1,var2;
    printf("Enter Vertex 1 : ");
    scanf("%d",&var1);
    printf("Enter Vertex 2 : ");
    scanf("%d",&var2);
    path(var1,var2);
}
}
}
