#include<iostream>
using namespace std;
struct node{
    int x=0;
    struct node* next;
    struct node* last;
};
struct node* tail=NULL;
void push(int x){
    struct node* t=(struct node*)malloc(sizeof(struct node));
    t->x=x;t->last=NULL;t->next=NULL;
    if(tail==NULL){
        tail=t;
        tail->next=NULL;
        tail->last=NULL;
    }else{
        t->last=tail;
        t->next=NULL;
        tail->next=t;
        tail=t;
    }
}
int pop(){
    if(tail==NULL){
        cout<<"The double linked list is empty!";
        exit(0);
    }
    int tmp=tail->x;
    tail=tail->last;
    return tmp;
}
int main(){
    push(1);push(2);
    cout<<pop()<<endl<<pop()<<endl;
    return 0;
}