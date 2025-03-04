#include<stdio.h>
#include<iostream>
using namespace std;
struct node{
    int x=0;
    struct node* last=NULL;
}; 
class Stack{
    public:
        struct node* top=NULL;
        void push(int x);
        int pop();
};
void Stack::push(int x){
    struct node* t=(struct node*)malloc(sizeof(struct node));
    t->x=x;t->last=NULL;
    if(top==NULL){
        top=t;
        top->last=NULL;
    }else{
        t->last=top;
        top=t;
    }
}
int Stack::pop(){
    if(top==NULL){
        cout<<"The stack is empty!";
        exit(0);
    }
    int tmp=top->x;
    top=top->last;
    return tmp;
}
int main(){
    Stack stack;
    stack.push(1);stack.push(2);
    cout<<stack.pop()<<endl<<stack.pop();
    return 0;
}