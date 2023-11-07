#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void Matrix_Multiplication(){
    int r1, c1;
    cout << "enter no.of rows element of r1: ";
    cin >> r1;
    cout << "enter no.of columns element of c1: ";
    cin >> c1;

    int A[r1][c1];

    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            cin >> A[i][j];
        }
    }

    int r2, c2;
    cout << "enter no.of rows element of r2: ";
    cin >> r2;
    cout << "enter no.of columns element of c2: ";
    cin >> c2;

    int B[r2][c2];

    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            cin >> B[i][j];
        }
    }

    if (c1 != r2)
    {
        cout << "matrix multiplication not possible: " << endl;
    }
    int C[r1][c2];
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            int ans = 0;
            for (int k = 0; k < r2; k++)
            { // r2 and c1 are equal koi bhi le sakte
                ans += A[i][k] * B[k][j];
            }
            C[i][j] = ans;
        }
    }
    // display
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{

    Matrix_Multiplication();

    return 0;
}