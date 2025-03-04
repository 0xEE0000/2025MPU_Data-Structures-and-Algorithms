#include<iostream>
using namespace std;
struct node{
    int x=0;
    struct node* next=NULL;
};
class Queue{
    public:
        struct node* head=NULL;
        struct node* tail=NULL;
        void push(int x);
        int pop();
};
void Queue::push(int x){
    struct node* t=(struct node*)malloc(sizeof(struct node));
    t->x=x;t->next=NULL;
    if(tail==NULL){
        tail=t;
        tail->next=NULL;
        head=tail;
    }else{
        tail->next=t;
        tail=t;
    }
}
int Queue::pop(){
    if(head==NULL){
        cout<<"The queue is empty!";
        exit(0);
    }
    int tmp=head->x;
    head=head->next;
    return tmp;
}
int main(){
    Queue queue;
    queue.push(1);queue.push(2);
    cout<<queue.pop()<<endl<<queue.pop()<<endl;
    return 0;
}