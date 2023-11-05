//PUSH efficient means push ki T.C = O(1)
//POP ki T.C - O(n)


#include<iostream>
#include<string>
#include<cstdlib>
#include<stack>
using namespace std;
stack <int> st;

void push(int x){
    st.push(x);
}

void pop(){
    if(st.empty())
        return;
    stack <int> temp;
    while(st.size() > 1){
        temp.push(st.top());
        st.pop();
    }
    //now size is 1 adn we are at bottom of stack
    st.pop();
    while(!temp.empty()){
        st.push(temp.top());
        temp.pop();
    }
}

bool isEmpty(){
    return st.empty();
}

int front(){
    if(st.empty())
        return -1;
    stack <int> temp;
    while(st.size() > 1){
        temp.push(st.top());
        st.pop();
    }
    //now size is 1 adn we are at bottom of stack
    int result = st.top();
    while(!temp.empty()){
        st.push(temp.top());
        temp.pop();
    }

    return result;
}


int main()
{   
    push(10);
    push(20);
    push(30);
    push(40);
    pop();
    while(!isEmpty()){
        cout<<front()<<", ";
        pop();
    }


    return 0;
}