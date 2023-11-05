#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int binarySearch(int arr[], int left, int right, int x) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x) {
            return mid;
        } else if (arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    int capacity, x;
    cout << "Enter how many elements you want to enter: ";
    cin >> capacity;
    int arr[capacity];

    for (int i = 0; i < capacity; i++) {
        cout << "Enter element: ";
        cin >> arr[i];
    }

    cout << "Enter element to search for: ";
    cin >> x;

    int left = 0;              // Initialize left to 0
    int right = capacity - 1;  // Initialize right to the last index

    int result = binarySearch(arr, left, right, x);

    if (result != -1) {
        cout << "Value has been found at index: " << result << endl;
    } else {
        cout << "Value not found in the array." << endl;
    }

    return 0;
}
