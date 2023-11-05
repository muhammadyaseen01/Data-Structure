#include<iostream>
#include<string>
#include<cstdlib>
#include<stack>
#include<queue>
using namespace std;


int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

//agar before reversing bhi print krna h to queue ko dosri queue me dalna parega phr usse agr kaam


    stack <int> st;

    while(!q.empty()){
        st.push(q.front());
        q.pop();
    }

    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
    cout<< "after reversing: ";
    while(!q.empty()){
        cout<<q.front()<<", ";
        q.pop();
    }

    return 0;
}