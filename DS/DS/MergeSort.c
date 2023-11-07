#include<stdio.h>
#include<conio.h>
#define size 5
int arr[size];
int newarr[size];
void merg(int L,int mid,int R){
    int i,j,k;
    i=L;
    j=mid+1;
    k=L;
    while(i<=mid && j<=R){
        if(arr[i]<=arr[j]){
            newarr[k]=arr[i];
            i++;
        }
        else{
            newarr[k]=arr[j];
            j++;
        }
        k++;
    }
    if(i>mid){
        while(j<=R){
            newarr[k]=arr[j];
            j++;
            k++;
        }
    }
    else{
        while(j<=mid){
            newarr[k]=arr[i];
            i++;
            k++;
        }
    }

        for(int k=L;k<R;k++){
        arr[k]=newarr[k];
    }
}

void MergeSort(int L,int R){

    if(L<R){
        int mid=(L+R)/2;
        MergeSort(L,mid);
        MergeSort(mid+1,R);
     //   printf("no");
        merg(L,mid,R);

    }
}

void main(){
    int L, R;
    L=0;
    R=size-1;
    for(int i=0;i<size;i++){
        printf("Enter Value at index %d : ",i);
        scanf("%d",&arr[i]);
    }
    MergeSort(L,R);
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}
