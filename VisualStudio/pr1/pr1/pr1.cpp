#include <iostream>
#include <cctype>
#include <Algorithm>

using namespace std;

struct MyStruct
{
    int a;
    char b;
};

void VariableSett(int* arr) {
	arr[0] = 1;
	arr[2] = 2;
}
int main() {
	/*char a = 'a';
	a=a+3;
	int b = (int)a;
	cout << b;*/
	/*int arr[5];
	VariableSett(arr);
	cout << arr[1];*/
    //int arr[4];
    //int size = 4;
    //int hold, j, k;
    //int counter = 0, bribes = 0; // to find no. of bribes
    //for (int i = 1; i < size; i++) {
    //    hold = arr[i];
    //    k = i;
    //    j = i - 1;
    //    while (j >= 0) {
    //        if (hold < arr[j]) {
    //            swap(arr[k], arr[j]);
    //            counter++;
    //        }
    //        j = j - 1;
    //        k = k - 1;
    //        bribes = bribes + counter;
    //        counter = 0;
    //    }
    //}
    /*MyStruct* arr=new MyStruct[3];
    arr[0].a = 3;
    arr[1].a = 2;
    arr[2].a = 1;
    arr[0].b = 'a';
    arr[1].b = 'v';
    arr[2].b = 'c';
    swap(arr[0], arr[1]);
    for (int i = 0; i < 3; i++) {
        cout << arr[i].a;
    }*/
    int arr[3];
    cout << arr[0];
}
