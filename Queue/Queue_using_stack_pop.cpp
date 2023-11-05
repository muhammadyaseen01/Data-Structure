// POP efficient means push ki T.C = O(1)
// PUSH ki T.C - O(n)

#include <iostream>
#include <string>
#include <cstdlib>
#include <stack>
using namespace std;
stack<int> st;

void push(int x)
{
    stack<int> temp;
    while (!st.empty())
    {
        temp.push(st.top());
        st.pop();
    }
    st.push(x);
    while (!temp.empty())
    {
        st.push(temp.top());
        temp.pop();
    }
}
//write code for stack?
void pop()
{
    if (st.empty())
        return;
    st.pop();
}

bool isEmpty()
{
    return st.empty();
}

int front()
{
    if (st.empty())
        return -1;
    return st.top();
}

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    pop();
    pop();
    while (!isEmpty())
    {
        cout << front() << ", ";
        pop();
    }

    return 0;
}