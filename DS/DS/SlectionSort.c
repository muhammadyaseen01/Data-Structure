#include<stdio.h>
#include<conio.h>


void main(){
int size,n,s_index,temp,choice;
printf("Enter the length of the array : ");
scanf("%d",&size);
int arr[size];



for (int i=0;i<size;i++){
    printf("Enter the number in index %d : ",i);
    scanf("%d",&arr[i]);
}

printf("Enter 1 for Ascending Order And 2 for Descending order ");
scanf("%d",&choice);
if(choice==1){
for(int i=0;i<size-1;i++){
    s_index=i;
    for(int j=i+1;j<size;j++){
        if(arr[s_index]>arr[j]){
            s_index=j;
        }
    }
    temp=arr[i];
    arr[i]=arr[s_index];
    arr[s_index]=temp;

}
for(int i=0;i<size;i++){
    printf("%d  ",arr[i]);
}
}
else if(choice==2){

for(int i=0;i<size-1;i++){
    s_index=i;
    for(int j=i+1;j<size;j++){
        if(arr[s_index]<arr[j]){
            s_index=j;
        }
    }
    temp=arr[i];
    arr[i]=arr[s_index];
    arr[s_index]=temp;

}
for(int i=0;i<size;i++){
    printf("%d  ",arr[i]);
}
}
}
