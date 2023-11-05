//deque == double ended queue --> we can access it front front and rear both way

#include<iostream>
#include<string>
#include<cstdlib>
#include<queue>
using namespace std;
int main()
{
    deque <int> d;

    d.push_back(20);
    d.push_back(30);
    d.push_back(40);
    d.push_back(50);
    d.push_back(60);

    d.push_front(10);
    d.push_front(5);
    d.push_front(0);

    // while(!d.empty()){
    //     cout<<d.front()<<", ";
    //     d.pop_front();
    // }
    while(!d.empty()){
        cout<<d.back()<<", ";
        d.pop_back();
    }

    return 0;
}