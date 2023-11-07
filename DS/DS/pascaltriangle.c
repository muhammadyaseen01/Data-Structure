#include<stdio.h>
#include<conio.h>

void main(){

int n;
scanf("%d",&n);

for (int i=0;i<n;i++){
    int num;
    int a=(n-1)-i;
    for(int j=0;j<=a;j++){
        printf("%c"," ");
    }
    for (int k=0;k<=i;k++){
        printf("%c"," ");
        num=1;
        num=num+n;
        printf("%d",num-i);
    }
printf("\n");
}

}
