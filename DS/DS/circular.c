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
    tmp->next=&start;
    if (start==NULL){
        start=tmp;
    }
    else{
        struct Node *curr=start;
        while(curr->next!=&start){
            curr=curr->next;
        }
        curr->next=tmp;
    }

}
void printAll(){
    struct Node *p=start;
    while(p!=&start){
        printf("%d->",p->data);
        p=p->next;
    }
    if(p==&start){
        printf("%d\n",&p->next);
    }
    printf("%d\n",&start);

}

void Search(){

    int num;
    int flag=0;
    printf("Enter No. to search : ");
    scanf("%d",&num);
    struct Node *p=start;
    while(p!=&start){
        if (num==p->data){
            printf("YES!");
            flag=1;
            break;
        }
    p=p->next;
    }
    if(flag==0){
        printf("not found");
    }
}

void delete(){

	int todelete;
	int flag=0;
	printf("Enter No. to delete");
	scanf("%d",&todelete);
	struct Node *curr,*pre=start;
	if(todelete==start->data){
		start=start->next;
		free(pre);
		flag=1;

	}
	else{
		curr=start->next;
		pre=start;
		while(curr!=&start){
			if(todelete==curr->data){
				pre->next=curr->next;
				free(curr);
                flag=1;
				break;
			}
            curr=curr->next;
			pre=pre->next;
		}

	}
	if(flag==0){
        printf("not found");
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
        //printf("no");
        printAll();

    }
    else if(choise==3){
        //printf("no");
        Search();
    }
    else if(choise==4){
        delete();
        //delete();
    }
    else if(choise==5){
        break;
    }
    }

}
