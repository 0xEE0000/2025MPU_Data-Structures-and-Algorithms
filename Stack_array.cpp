#include<iostream>
using namespace std;
class Stack{
    public:
        int stack[1000]={};
        int top=-1;
        void push(int x);
        int pop();
};
void Stack::push(int x){stack[++top]=x;}
int Stack::pop(){return stack[top--];}
int main(){
    Stack stack;
    stack.push(1);stack.push(2);
    cout<<stack.pop()<<endl<<stack.pop();
    return 0;
}