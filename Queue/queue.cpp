#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

struct queue
{
    int val;
    queue *next;
};
queue * front = NULL;
queue * rear = NULL;

void enqueue(int new_val){
    queue *new_node = new queue();
    new_node->val = new_val;
    if (front == NULL){
        front = rear = new_node;
    }
    else{
        rear->next = new_node;
        rear = new_node;
    }
}

void dequeue(){
    if(front == NULL){
        return;
    }
    else{
        queue * old_front = front;
        queue * new_front = front->next;
        front = new_front;
        //agr srf ek hi element tha to new_front NULL ko point krega to rear ko bhi NULL krna preag
        if(front == NULL){
            rear = NULL;
        }
        old_front->next = NULL;
        delete old_front;

    }
}

bool isEmpty(){
    return front == NULL;
}

int getFront(){
    if(front == NULL){
        cout<<"underflow\n";
        // return 1;
        // return INT_MIN; 
    }
    return front->val;
}


int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    dequeue();
    enqueue(40);
    enqueue(50);
    enqueue(60);
    while (!isEmpty()){
        cout<<getFront()<<", ";
        dequeue();
    }


    return 0;
}