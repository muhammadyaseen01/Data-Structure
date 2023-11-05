#include <iostream>
using namespace std;

void linearSearch(int a[], int size, int n) {
    int temp = -1;

    for (int i = 0; i < size; i++) {
        if (a[i] == n) {
            cout << "Element found at position: " << i + 1 << endl;
            temp = 0;
            break;
        }
    }
    if (temp == -1) {
        cout << "No Element Found" << endl;
    }
}

int main() {
    int capacity;
    cout << "Enter capacity: ";
    cin >> capacity;
    int arr[capacity];
    for (int i = 0; i < capacity; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }
    cout << "Please enter an element to search: ";
    int num;
    cin >> num;

    linearSearch(arr, capacity, num);

    return 0;
}
