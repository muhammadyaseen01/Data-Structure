#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Student{
    int SID;
    int Semester;
    struct Student *StuNext;
    //struct Student *StuStart;
};

struct Course{
    int CNo;
    char TName;
    struct Student *StuStart;
    struct Course *CNext;
};
struct Course *start=NULL;

void CInsert(){
    struct Course *tmp=(struct Course*)malloc(sizeof(struct Course));
    printf("Enter Teacher Name : ");
    char name[25];
    scanf("%s",&name);
    int curs;
    printf("Enter Course Number");
    scanf("%d",&curs);

    tmp->TName=name;
    tmp->CNo=curs;
    tmp->CNext=NULL;
    tmp->StuStart=NULL;
    if(start==NULL){
        start=tmp;
    }
    else{
        struct Course *curr=start;
        while(curr->CNext!=NULL){
            curr=curr->CNext;
        }
        curr->CNext=tmp;
    }
}


void SInsert(){
    struct Student *tmp=(struct Student*)malloc(sizeof(struct Student));
    int SD,Sem;
    printf("Enter Student ID : ");
    scanf("%d",&SD);
    printf("Enter Semester : ");
    scanf("%d",&Sem);
    int curs;
    printf("Enter Course Number");
    scanf("%d",&curs);

    if(start==NULL){
        printf("Enter Course!\n");
    }
    else{
    tmp->SID=SD;
    tmp->Semester=Sem;
    tmp->StuNext=NULL;
    struct Course *co=start;
    while(co!=NULL){
    if(curs==co->CNo){

        if(co->StuStart==NULL){
        co->StuStart=tmp;

        }
        else{
        struct Student *curr=co->StuStart;
        while(curr->StuNext!=NULL){
            curr=curr->StuNext;
        }
        curr->StuNext=tmp;
        }
    }

    else{
        printf("No\n");
    }
    co=co->CNext;
    }

}

}

void CprintAll(){
    struct Course *p=start;
    while(p!=NULL){
        //printf("%s ",p->TName);
        printf("%d->",p->CNo);
        p=p->CNext;
    }
    }
void SprintAll(){
    struct Course *cou=start;
    struct Student *stu;
    while(cou!=NULL){
    while(cou->StuStart!=NULL){
        printf("%d",cou->StuStart->SID);
        cou->StuStart=cou->StuStart->StuNext;
    }
    cou=cou->CNext;
    }
}

void main(){
    for(;;){
    int choise;
    printf("Enter 1 For COURSE And 2 For STUDENTS Insert : ");
    scanf("%d",&choise);
    if(choise==1){
        CInsert();
    }
    else if(choise==2){
        SInsert();
    }
    else if(choise==3){
       CprintAll();
    }
    else if(choise==4){
       SprintAll();
    }

}
}
