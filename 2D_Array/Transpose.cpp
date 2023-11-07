#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void transpose_matrix()
{
    int r, c;
    cout << "enter no.of rows element of r: ";
    cin >> r;
    cout << "enter no.of columns element of c: ";
    cin >> c;

    int array[r][c];

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> array[i][j];
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }cout<< " transpose of the above matrix is: ";
    
    int transpose [c][r];

    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
        {
            transpose [i][j] = array [j][i];
        }
        cout << endl;
    }

    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
        {
            cout << transpose[i][j] << " ";
        }
        cout << endl;
    }


}

int main()
{
    transpose_matrix();
    return 0;
}