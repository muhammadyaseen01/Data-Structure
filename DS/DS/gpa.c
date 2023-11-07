#include<stdio.h>

int main(){
int n;
printf("Enter students");
scanf("%d",&n);
int marks[n];
for(int i=0;i<n;i++){
    printf("Enter No.");
    scanf("%d",&marks[i]);
}
float gpa[n];
for(int i=0;i<n;i++){
    if(marks[i]>=85){
        gpa[i]=4.0;
    }
    else if(marks[i]>=80){
        gpa[i]=3.8;
    }
    else if(marks[i]>=75){
        gpa[i]=3.4;
    }
    else if(marks[i]>=71){
        gpa[i]=3.0;
    }
    else if(marks[i]>=68){
        gpa[i]=2.8;
    }
    else if(marks[i]>=64){
        gpa[i]=2.4;
    }
    else if(marks[i]>=61){
        gpa[i]=2.0;
    }
    else if(marks[i]>=57){
        gpa[i]=1.8;
    }
    else if(marks[i]>=53){
        gpa[i]=1.4;
    }
    else if(marks[i]>=50){
        gpa[i]=1.0;
    }
    else{
        gpa[i]=0.0;
    }
}

for(int i=0;i<n;i++){
    printf("%f  ",gpa[i]);
 }

return 0;
}
