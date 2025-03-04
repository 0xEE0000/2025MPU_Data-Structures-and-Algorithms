#include<iostream>
using namespace std;
struct node{
    int x;
    struct node* leftchild;
    struct node* rightchild;
};
struct node* root=NULL;
void in_order(struct node* t){
    if(t==NULL) return ;
    in_order(t->leftchild);
    cout<<t->x<<" ";
    in_order(t->rightchild);
}
void insertion(int n,struct node* t){
    if(t==NULL) return ;
    if(t->leftchild==NULL&&n<t->x){
        struct node* tmp=(struct node*)malloc(sizeof(struct node));
        tmp->leftchild=NULL;tmp->rightchild=NULL;tmp->x=n;
        t->leftchild=tmp;
        return ;
    }
    if(t->rightchild==NULL&&n>=t->x){
        struct node* tmp=(struct node*)malloc(sizeof(struct node));
        tmp->leftchild=NULL;tmp->rightchild=NULL;tmp->x=n;
        t->rightchild=tmp;
        return ;
    }
    if(n<t->x) insertion(n,t->leftchild);
    else insertion(n,t->rightchild);
}
struct node* searching(int n,struct node* t){
    if(t==NULL){
        cout<<"This node does not exist."; 
        return NULL;
    }
    if(n==t->x) return t;
    if(n<t->x) return searching(n,t->leftchild);
    else return searching(n,t->rightchild);
}
int find_left_max(struct node* t){
    while(t->rightchild) t=t->rightchild;
    return t->x;
}
void deletion(int n,struct node*& t){
    if(t==NULL) return ;
    if (n<t->x) {
        deletion(n,t->leftchild);
    }else if(n>t->x){
        deletion(n,t->rightchild);
    }else {
        if(t->leftchild&&t->rightchild){
            int node_max=find_left_max(t->leftchild);
            deletion(node_max,t->leftchild);
            t->x=node_max;
        }else if(t->leftchild==NULL){
            t=t->rightchild;
        }else if(t->rightchild==NULL){
            t=t->leftchild;
        }else t=NULL;
    }
}
int main(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        if(i==1){
            root=(struct node*)malloc(sizeof(struct node));
            root->leftchild=NULL;root->rightchild=NULL;root->x=x;
        }else insertion(x,root);
    }
    in_order(root);cout<<endl;
    cout<<searching(4,root)->x<<endl;
    //cout<<searching(13,root)->x<<endl;
    deletion(3,root);
    in_order(root);
    return 0;
}
/*
Test Data: 
12
7 5 8 2 6 1 4 3 10 9 11 12
*/