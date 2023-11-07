#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Student{
    int SID;
    int Semester;
    struct Student *StuNext;
    struct Student *StuStart;
};

struct Course{
    int CNo;
    char TName;
    struct Student *StuStart;
    struct Course *CNext;
};
struct Course *start=NULL;

void CInsert(char name[],int curs){
    struct Course *tmp=(struct Course*)malloc(sizeof(struct Course));

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

void CprintAll(){
    struct Course *p=start;
    while(p!=NULL){
        //printf("%s ",p->TName);
        printf("%d->",p->CNo);
        p=p->CNext;
    }
    }

int SearchC(int curs){
    struct Course *co=start;
    if(start==NULL){
        printf("Enter Course!\n");
    }
    else{
        //struct Course *co=start;
        while(co!=NULL){
            if(curs==co->CNo){
                //printf("YES");
                return co->CNo;
            }
        co=co->CNext;

    }
    }
}

void SInsert(int SD,int Sem,int curs){
    struct Student *tmp=(struct Student*)malloc(sizeof(struct Student));
    tmp->SID=SD;
    tmp->Semester=Sem;
    tmp->StuNext=NULL;
    //tmp->StuStart=NULL;
    struct Course *co=start;
    while(co!=NULL){
    if(curs==co->CNo){
        if(co->StuStart==NULL){
        //struct Student *curr;
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
    //else{
     //   printf("No\n");
   // }
    co=co->CNext;
}
}

void SprintAll(int curs){
    struct Student *stu;
    struct Course *cou=start;
    struct Student *st_start=cou->StuStart;
    while(cou!=NULL){
        if(cou->CNo==curs){
            while(st_start!=NULL){
            printf("%d ",st_start->SID);
            st_start=st_start->StuNext;
            }
        }
      cou=cou->CNext;
    }
}

int StuSearch(int cors,int stid){
    struct Course *co=start;
    struct Student *st;
    struct Student *st_start=co->StuStart;
    if(start==NULL){
        printf("Enter Course First\n");
    }
    else{
        while(co!=NULL){
            if(co->CNo==cors){
                while(st_start!=NULL){
                    st_start=st_start->StuNext;
                }
                printf("YES");
                return (co->StuStart->SID);
                //return 1;
            }
        co=co->CNext;
        }
    }
}

void StuDlete(int cour,int stid){
    struct Course *cu=start;
    struct Student *st;
    struct Student *pre=cu->StuStart,*curr=cu->StuStart,*st_start=cu->StuStart;
   // struct Student *st_start,*pre->,*curr=cu->StuStart;
   // if(cu==NULL){
      //  printf("Enter Course First\n");
    //}
    //else{
        while(cu!=NULL){
        if(cu->CNo==cour){
            if(stid==st_start->SID){
                free(st_start);
                curr->StuStart=st_start->StuNext;
                printf("YES1");

            }
            else{
                curr=st_start->StuNext;
                pre=st_start;
                while(curr!=NULL){
                    if(stid==curr->SID){
                    pre->StuNext=curr->StuNext;
                    free(curr);
                    printf("YES");
                    }
                curr=curr->StuNext;
                pre=pre->StuNext;
                }
            }
    }
        cu=cu->CNext;
    }

}


void CouDelete(int curs){
    struct Course *Ccurr=start->CNext,*pre=start;
    struct Student *Scurr;
    //if(start==NULL){
   //     printf("Enter Course First\n");
 //   }
    if(start->CNo==curs){
        Scurr=start->StuStart;
        start=start->CNext;
        free(Ccurr);
        free(Scurr);
        printf("yes1");
    }
    else{
            while(Ccurr!=NULL){
                if(Ccurr->CNo==curs){
                    pre->CNext=Ccurr->CNext;
                    //pre->CNext=curr->CNext;
                    free(Scurr);
                    free(Ccurr);
                    printf("yes");

                }
                Ccurr=Ccurr->CNext;
                pre=pre->CNext;
            }
        }
}



void main(){
    for(;;){
    int choise;
    printf("Enter 1 For COURSE And 2 For STUDENTS Insert : ");
    scanf("%d",&choise);

    if(choise==1){
    printf("Enter Teacher Name : ");
    char name[25];
    scanf("%s",&name);
    int curs;
    printf("Enter Course Number");
    scanf("%d",&curs);

    CInsert(name,curs);
    }
    else if(choise==2){
        int SD,Sem,curs;
        printf("Enter Student ID : ");
        scanf("%d",&SD);
        printf("Enter Semester : ");
        scanf("%d",&Sem);
        printf("Enter Course Number");
        scanf("%d",&curs);
        int a=SearchC(curs);
        SInsert(SD,Sem,curs);
    }
    else if(choise==3){
       CprintAll();
    }
    else if(choise==4){
        int curs;
        printf("Enter Course Number");
        scanf("%d",&curs);
       SprintAll(curs);
    }
    else if(choise==5){
    int curs;
    printf("Enter Course Number");
    scanf("%d",&curs);
    int a=SearchC(curs);
    printf("%d",a);
    }

    else if(choise==6){
    int curs;
    printf("Enter Course Number");
    scanf("%d",&curs);
    int stid;
    printf("Enter Student Number");
    scanf("%d",&stid);
    int a=StuSearch(curs,stid);
    printf("%d",a);
    }

    else if(choise==7){
    int curs;
    printf("Enter Course Number");
    scanf("%d",&curs);
    int stid;
    printf("Enter Student Number");
    scanf("%d",&stid);
    StuDlete(curs,stid);
    }

    else if(choise==8){
    int curs;
    printf("Enter Course Number");
    scanf("%d",&curs);
    CouDelete(curs);
    }

}
}
