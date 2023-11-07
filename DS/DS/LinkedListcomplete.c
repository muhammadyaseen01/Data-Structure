#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
struct Node *start=NULL;

int insert(){

    struct Node*tmp=(struct Node*)malloc(sizeof(struct Node));
    int n;
    printf("Enter Number");
    scanf("%d",&n);
    tmp->data=n;
    tmp->next=NULL;
    if (start==NULL){
        start=tmp;
    }
    else{
        struct Node*curr=start;
        while(curr->next!=NULL){
            curr=curr->next;
        }
        curr->next=tmp;
    }
}

void delete(){
	int todelete;
	printf("Enter No. to delete");
	scanf("%d",&todelete);
	struct Node *curr,*pre=start;
	if(todelete==start->data){
		start=start->next;
		free(pre);
	}
	else{
		curr=start->next;
		pre=start;
		while(curr!=NULL){
			if(todelete==curr->data){
				pre->next=curr->next;
				free(curr);
				break;
			}
            curr=curr->next;
			pre=pre->next;
		}

	}
}



//Print Linked List
void printAll(int *start){
    struct Node *p=start;
    while(p!=NULL){
        printf("%d->",p->data);
        p=p->next;
    }
    }
//Search Linked List
void Search(int *start){
    int num;
    printf("Enter No. to search : ");
    scanf("%d",&num);
    struct Node *p=start;
    while(p!=NULL){
        if (num==p->data){
            printf("YES!");
            break;
        }
    p=p->next;
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
        printAll(start);

    }
    else if(choise==3){
           Search(start);
    }
    else if(choise==4){
        delete();
    }
    else if(choise==5){
        break;
    }
    }

}
