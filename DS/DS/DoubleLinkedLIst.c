#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


struct DDLNode{
    int data;
    struct DDLNode *pre;
    struct DDLNode *next;
};
struct DDLNode *start=NULL;

void insert(){
    struct DDLNode *tmp=(struct DDLNode*)malloc(sizeof(struct DDLNode));
    int n;
    printf("Enter Number");
    scanf("%d",&n);
    tmp->data=n;
    tmp->pre=NULL;
    tmp->next=NULL;

    if(start==NULL){
        start=tmp;
    }

    else{
        struct DDLNode *curr=start;
        while(curr->next!=NULL){
            curr=curr->next;
        }
        curr->next=tmp;
        tmp->pre=curr;
    }
}


void FprintAll(){
    struct DDLNode *p=start;
    while(p!=NULL){
        printf("%d->",p->data);
        p=p->next;
    }

    //while(p!=NULL){
    //printf("%d__",p->pre->data);
    //p=p->pre;
    //}

}


void Search(){
    struct DDLNode *p=start;
    int num;
    printf("Enter No. to search : ");
    scanf("%d",&num);
    while(p!=NULL){
    if (num==p->data){
        printf("YES!");
        break;
    }
    p=p->next;
    }
}


void delete(){
	int todelete;
	printf("Enter No. to delete");
	scanf("%d",&todelete);
	struct DDLNode *currr,*pree=start;
	if(todelete==start->data){
        start=start->next;
		currr->pre=NULL;
		free(pree);
	}
	else{
		currr=start->next;
		pree=start;
		while(currr->next!=NULL){
			if(todelete==currr->data){
				pree->next=currr->next;
                currr->next->pre=currr->pre;
				free(currr);
				break;
			}
		}
            currr=currr->next;
			pree=pree->next;


	}
}


void main(){
    int choise;
    int *value;
    for(;;){
    printf("Enter 1 for insert 2 for print 3 for searching 4 for delete & 5 for exit : \n");
    scanf("%d",&choise);
    if (choise==1){
        insert();
    }
    else if(choise==2){
        FprintAll();


    }
    else if(choise==3){
           Search();
    }
    else if(choise==4){
        delete();
    }
    else if(choise==5){
        break;
    }
    }

}
