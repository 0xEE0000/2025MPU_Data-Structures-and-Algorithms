#include<iostream>
using namespace std;
struct node{
    int x;
    struct node* last;
    struct node* next;
};
struct node* head=NULL;
void front_push(int x){
    struct node* t=(struct node*)malloc(sizeof(struct node));
    t->x=x;t->last=NULL;t->next=NULL;
    if(head==NULL){
        head=t;
        head->last=head;
        head->next=NULL;
    }else{
        t->last=head->last;
        head->last->next=t;
        t->next=head;
        head->last=t;
        head=t;
    }
}
void back_push(int x){
    struct node* t=(struct node*)malloc(sizeof(struct node));
    t->x=x;t->last=NULL;t->next=NULL;
    if(head==NULL){
        head=t;
        head->last=head;
        head->next=NULL;
    }else{
        t->last=head->last;
        t->next=head;
        head->last->next=t;
        head->last=t;
    }
}
int back_pop(){
    if(head==NULL){
        cout<<"This circular double linked list is empty!";
        exit(0);
    }
    int tmp=head->last->x;
    head->last=head->last->last;
    head->last->next=head;
    return tmp;
}
int front_pop(){
    if(head==NULL){
        cout<<"This circular double linked list is empty!";
        exit(0);
    }
    int tmp=head->x;
    head->last->next=head->next;
    head->next->last=head->last;
    head=head->next;
    return tmp;
}
int main(){
    front_push(1);back_push(3);back_push(4);front_push(2);
    //cout<<front_pop()<<endl<<front_pop()<<endl<<front_pop()<<endl<<front_pop()<<endl;
    cout<<back_pop()<<endl<<back_pop()<<endl<<back_pop()<<endl<<back_pop()<<endl;
    return 0;
}