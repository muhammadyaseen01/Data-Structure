#include<stdio.h>


void main(){
    int n;
    scanf("%d",&n);
    int fo,f1;
    fo=0;
    f1=1;
    for(int i=0;i<n;i++){
        if (i==0){
            printf("%d %d"0 1);
        }
        else{
            int fib;
            fib=fo+f1;
            printf(" %d " fib)
            fo=f1;
            f1=fib;
        }

    }
}
