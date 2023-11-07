#include<stdio.h>
#include<conio.h>

void main(){

int size,choice;
printf("Enter the size of the array : ");
scanf("%d",&size);
int arr[size];

for(int i=0;i<size;i++){
    printf("Enter the number in index %d :",i);
    scanf("%d",&arr[i]);
}
printf("Enter 1 for the ascending order and 2 for the descending order : ");
scanf("%d",&choice);

//For Ascending Order
if(choice==1){
for(int i=0;i<size-1;i++){
    for(int j=0;j<size-i-1;j++){
        if(arr[j]>arr[j+1]){
            int tem=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=tem;
        }
    }
}
}
//For Descending Order
else if(choice==2){
for(int i=0;i<size-1;i++){
    for(int j=0;j<size-i-1;j++){
        if(arr[j]<arr[j+1]){
            int tem=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=tem;
        }
    }
}
}

for (int i=0;i<size;i++){
    printf("%d  ",arr[i]);
}

}
