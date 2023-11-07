#include<stdio.h>
#include<conio.h>

void main(){
int len;
printf("Enter the length of the array : ");
scanf("%d",&len);
int arr[len];

for(int i=0;i<len;i++){
    printf("Enter the No. in index %d : ",i);
    scanf("%d",&arr[i]);
}
int choise;
printf("Enter 1 for ascending order and 2 for descending order : ");
scanf("%d",&choise);
if(choise==1){
for (int i=1;i<len;i++){
    int temp=arr[i];
    int j=i-1;
    while(j>=0 && arr[j]>temp){
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=temp;
}
}

else if(choise==2){
    for (int i=1;i<len;i++){
    int temp=arr[i];
    int j=i-1;
    while(j>=0 && arr[j]<temp){
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=temp;
}
}
for (int k=0;k<len;k++){
    printf("%d  ",arr[k]);
}

}
