#include<iostream>
using namespace std;
class Queue{
    public:
        int queue[1000]={};
        int tail=-1,head=0;
        void enqueue(int x);
        int dequeue();
};
void Queue::enqueue(int x){queue[++tail%1000]=x;}
int Queue::dequeue(){return queue[head++];}
int main(){
    Queue queue;
    queue.enqueue(1);queue.enqueue(2);
    cout<<queue.dequeue()<<endl<<queue.dequeue();
    return 0;
}