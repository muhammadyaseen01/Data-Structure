#include <iostream>
using namespace std;

void process(int *arr, int n){
    for (int i = 0;i < n; i++){
        cout << (arr + i) <<": ";
        cout <<*(arr +i)<<endl;
    }
    *(arr + 1) = 55;
}

int main(){
    int arr [3] = {5,1,12};
    process(arr , 3);
    
    for (int i = 0; i<3; i++){
        cout << arr[i]<<"  ";
    }
    return 0;
}