#include<stdio.h>
#include<conio.h>

int Binay(int arr[],int L,int R,int num);
void main(){

int len,L,R,num;
scanf("%d",&len);
int arr[len];
for (int i=0;i<len;i++){
    scanf("%d",&arr[i]);
}
printf("Enter No. to search : ");
scanf("%d",&num);
L=0;
R=len;
Binay(arr[len],L,R,num);
}
int Binay(int arr[],int L,int R,int num){
    int mid =(L+R)/2 ;
    if (L>R){
        return -1;
    }
    else if (num==arr[mid]){
        return mid;
    }
    else if (num<arr[mid]){
        return Binay(arr,L,mid-1,num);
    }
    else{
        return Binay(arr,mid+1,R,num);
    }

}

