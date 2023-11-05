#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int L_child(int index)
{
    return (2 * index + 1);
}

int R_child(int index)
{
    return (2 * index + 2);
}

int parent(int index)
{
    return ((index - 1) / 2);
}

void max_heapify(int arr[], int index, int &size)
{
    int left_child = L_child(index);
    int right_child = R_child(index);
    int largest = index;

    if (left_child < size && arr[left_child] > arr[largest])
        largest = left_child;

    if (right_child < size && arr[right_child] > arr[largest])
        largest = right_child;

    if (largest != index)
    {
        swap(arr[index], arr[largest]);
        max_heapify(arr, largest, size);
    }
}

void max_build_heap(int arr[], int size)
{
    for (int i = (size - 1) / 2; i >= 0; i--)
    {
        max_heapify(arr, i, size);
    }
}

int max_insert(int arr[], int new_val, int capacity, int size)
{ //&size to size
    if (size == capacity)
        return 0;
    size++;
    arr[size - 1] = new_val;
    for (int i = (size - 1); i != 0 && arr[parent(i)] < arr[i];)
    { // i!=0--> i root node ko point nh kr rha AND child parent se greater h to swap hoga wrna nh
        swap(arr[i], arr[parent(i)]);
        i = parent(i); // it return index of parent node --> phr me usse check krnga wo sahi jaga h ya nh
    }
    return size; // size ko update krna h baar baar is liye size return krna zarori or inki size me store krnga main me agr aisa nh krge to size update srf function me hoga function k bahar value same rahegi (ya phr argument me size ka address pas kr k bhi kia ja sakta h phr return krne ki zarorat nh)
}

void deletion(int arr[], int &size)
{
    if (size == 0)
    {
        cout << "Heap is empty. Deletion not possible." << endl;
        return;
    }

    // Replace the root node with the last element.
    swap(arr[0], arr[size - 1]);
    size--;

    // Restore the max-heap property by calling max_heapify on the root node.
    max_heapify(arr, 0, size);
}

void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

void heap_sort(int arr[], int &size)
{
    if (size == 0)
    {
        cout << "Heap is empty." << endl;
        return;
    }
    for (int i = (size - 1); i > 0; i--)
    {
        swap(arr[0], arr[i]);
        // size--;
        max_heapify(arr, 0, i); // i is liye pass kia h qk size ek kam hojayega last index ko edit nh krnga me

        // step by step k liye ye 3 line (debug)
        // print(arr,size);
        // cout<<endl;
        // cout<<"---------------------------------"<<endl;
    }
}

int main()
{
    
    // cout << "enter how many number you want to enter: ";
    // cin >> n;

    // for (int i = 0; i < n && size != capacity; i++)
    // {
    //     cout << "Enter the value you want to insert: ";
    //     cin >> new_val;
    //     arr[i] = new_val;
    //     size++;
    // }
    // cout << "Before heapify" << endl;
    // print(arr, size);
    // cout << endl;

    // cout << "After heapify" << endl;
    // max_build_heap(arr, size);

    // print(arr, size);
    // cout << endl;
    // cout << "------------------------------------------" << endl;
    // heap_sort(arr, size);
    // cout << "After heap_sort" << endl;
    // print(arr, size);
    // cout << endl;

    // deletion(arr,size);
    // deletion(arr,size);

    // cout << "After deletion" << endl;
    // print(arr, size);
    // cout<<endl;

    int capacity, n, new_val, size = 0;
    cout << "enter capacity :";
    cin >> capacity;
    int arr[capacity];


    int num;
    cout << "1)Press 1 to insert and heapify along with insertion: " << endl;
    cout << "2)Press 2 to insert elements in array unsortedly: " << endl;
    cout << "3)Press 3 to delete Node: " << endl;
    cout << "4)Press 4 to display the sorted tree: " << endl;
    cout << "5)Press 0 to exit from menu: " << endl;
    cin >> num;
    while (num != 0)
    {
        if (num == 1)
        {
            cout << "enter how many number you want to insert: ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                cout << "enter the value you want to insert: ";
                cin >> new_val;
                size = max_insert(arr, new_val, capacity, size); // size me store is liye qk size return kr rha function to yahan update
            }
            // max_insert(arr, new_val, capacity, size);
        }
        else if (num == 2)
        {
            cout << "enter how many number you want to enter: ";
            cin >> n;

            for (int i = 0; i < n && size != capacity; i++)
            {
                cout << "Enter the value you want to insert: ";
                cin >> new_val;
                arr[i] = new_val;
                size++;
            }
        }
        else if (num == 3)
        {
            deletion(arr, size);
        }
        else if (num == 4)
        {
            int number;
            cout << "1)Press 1 if you insert element using heapify insertion: " << endl;
            cout << "2)Press 2 if you insert unsortedly: " << endl;
            cout << "3)Press 0 to exit: " << endl;
            cin>>number;
            while (number != 0)
            {
                if (number == 1)
                {
                    print(arr, size);
                    cout<<endl;
                    break;
                }
                else if (number == 2)
                {
                    max_build_heap(arr, size);
                    print(arr, size);
                    cout<<endl;
                    break;
                }
            }
        }

        cout << "1)Press 1 to insert and heapify along with insertion: " << endl;
        cout << "2)Press 2 to insert elements in array unsortedly: " << endl;
        cout << "3)Press 3 to delete Node: " << endl;
        cout << "4)Press 4 to display the sorted tree: " << endl;
        cout << "5)Press 0 to exit from menu: " << endl;

        cin >> num;
    }

    return 0;
}