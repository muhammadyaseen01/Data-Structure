#include<iostream>
#include<string>
#include<cstdlib>
#include<queue>

using namespace std;
int main()
{
    queue <int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.pop();
    q.push(40);
    q.push(50);

    while(!q.empty()){
        cout<< q.front()<<", ";
        q.pop();
    }

    return 0;
}