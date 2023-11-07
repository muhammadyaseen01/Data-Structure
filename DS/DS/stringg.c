#include<stdio.h>
#include<conio.h>
#include<string.h>
void main(){
char name[]="aoun";
//scanf("Enter name %s",name);
//gets(name);
char vowel[]={"aeiou"};
//char charac[]={""}
int vo,con,total,length,space;
vo,con,total,space=0;
length=strlen(name);
for(int i=0;i<=length;i++){
    for(int j=0;j<=4;j++){
    if (name[i]==vowel[j]){
        vo+=1;
    }

    total=i;
    }
}
con=total-vo;
printf("Vowels are %d \n",vo);
printf("Consonents are %d \n",con);
printf("Total alphbats are %d \n",total);
printf("Total space are %d ",space);
}
