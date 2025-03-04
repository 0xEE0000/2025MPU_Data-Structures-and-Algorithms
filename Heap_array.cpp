#include<iostream>
using namespace std;
class MIN_Heap{
    public:
        int tree[1001]={},root=1,tail=1;
        int get_top();
        int deletion();
        void insertion(int n);
};
int MIN_Heap::get_top(){
    return tree[root];
}
int MIN_Heap::deletion(){
    if(tail==1) return 0;
    int top=tree[root],node=root;
    tree[root]=tree[tail-1];
    tree[tail-1]=0;tail--;
    while((tree[node]>tree[node*2]||tree[node]>tree[node*2+1])&&node<tail&&node*2<tail&&node*2+1<tail){
        if(tree[node*2]<tree[node*2+1]) {swap(tree[node],tree[node*2]);node=node*2;}
        else {swap(tree[node*2+1],tree[node]);node=node*2+1;}
    }
    return top;
}
void MIN_Heap::insertion(int n){
    int node=tail;
    tree[tail++]=n;
    while(node>=1){
        if(tree[node/2]>tree[node]){
            swap(tree[node/2],tree[node]);
            node/=2;
        }else return ;
    }
}
class MAX_Heap{
    public:
        int tree[1001],root=1,tail=1;
        int get_top();
        int deletion();
        void insertion(int n);
};
int MAX_Heap::get_top(){
    return tree[root];
}
int MAX_Heap::deletion(){
    if(tail==1) return 0;
    int top=tree[root],node=root;
    tree[root]=tree[tail-1];
    tree[tail-1]=0;tail--;
    while((tree[node]<tree[node*2]||tree[node]<tree[node*2+1])&&node<tail&&node*2<tail&&node*2+1<tail){
        if(tree[node*2]>tree[node*2+1]) {swap(tree[node],tree[node*2]);node=node*2;}
        else {swap(tree[node*2+1],tree[node]);node=node*2+1;}
    }
    return top;
}
void MAX_Heap::insertion(int n){
    int node=tail;
    tree[tail++]=n;
    while(node>=1){
        if(tree[node/2]<tree[node]){
            swap(tree[node/2],tree[node]);
            node/=2;
        }else return ;
    }
}
int main(){
    int n;cin>>n;
    //MIN_Heap heap1;
    // for(int i=1;i<=n;i++){
    //     int x;cin>>x;
    //     heap1.insertion(x);
    // }
    // for(int i=1;i<=n;i++){
    //     cout<<heap1.deletion()<<" ";
    // }
    MAX_Heap heap2;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        heap2.insertion(x);
    }
    for(int i=1;i<=n;i++){
        cout<<heap2.deletion()<<" ";
    }
    return 0;
}
/*
Test Data:
12
2 5 3 11 23 7 31 19 13 29 37 17
*/