#include<iostream>
#include<queue>
using namespace std;
struct node{
    int x;
    struct node* leftchild;
    struct node* rightchild;
};
struct node* root=NULL;
void preorder(struct node* t){
    if(t==NULL) return ;
    cout<<t->x<<" ";
    preorder(t->leftchild);
    preorder(t->rightchild);
}
void inorder(struct node* t){
    if(t==NULL) return ;
    inorder(t->leftchild);
    cout<<t->x<<" ";
    inorder(t->rightchild);
}
void postorder(struct node* t){
    if(t==NULL) return ;
    postorder(t->leftchild);
    postorder(t->rightchild);
    cout<<t->x<<" ";
}
queue<struct node*> q;
void bfs_recursive(struct node* t){
    if(q.empty()) return;
    cout<<t->x<<" ";q.pop();
    if(t->leftchild) q.push(t->leftchild);
    if(t->rightchild) q.push(t->rightchild);
    bfs_recursive(q.front());
}
void bfs_queue(struct node* t){
    queue<struct node*> q;
    q.push(t);
    while(!q.empty()){
        struct node* node=q.front();q.pop();
        cout<<node->x<<" ";
        if(node->leftchild) q.push(node->leftchild);
        if(node->rightchild) q.push(node->rightchild);
    }
}
int main(){
    struct node* root=(struct node*)malloc(sizeof(struct node));
    root->x=1;root->leftchild=NULL;root->rightchild=NULL;
    struct node* t1=(struct node*)malloc(sizeof(struct node));
    t1->x=2;root->leftchild=t1;t1->leftchild=NULL;t1->rightchild=NULL;
    struct node* t2=(struct node*)malloc(sizeof(struct node));
    t2->x=3;root->rightchild=t2;t2->leftchild=NULL;t2->rightchild=NULL;
    struct node* t3=(struct node*)malloc(sizeof(struct node));
    t3->x=4;t1->leftchild=t3;t3->leftchild=NULL;t3->rightchild=NULL;
    struct node* t4=(struct node*)malloc(sizeof(struct node));
    t4->x=5;t1->rightchild=t4;t4->leftchild=NULL;t4->rightchild=NULL;
    struct node* t5=(struct node*)malloc(sizeof(struct node));
    t5->x=6;t2->leftchild=t5;t5->leftchild=NULL;t5->rightchild=NULL;
    struct node* t6=(struct node*)malloc(sizeof(struct node));
    t6->x=7;t3->leftchild=t6;t6->leftchild=NULL;t6->rightchild=NULL;
    struct node* t7=(struct node*)malloc(sizeof(struct node));
    t7->x=8;t3->rightchild=t7;t7->leftchild=NULL;t7->rightchild=NULL;
    struct node* t8=(struct node*)malloc(sizeof(struct node));
    t8->x=9;t5->leftchild=t8;t8->leftchild=NULL;t8->rightchild=NULL;
    preorder(root);cout<<endl;
    inorder(root);cout<<endl;
    postorder(root);cout<<endl;
    bfs_queue(root);cout<<endl;
    q.push(root);bfs_recursive(root);
    return 0;
}