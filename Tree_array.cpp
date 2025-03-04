#include<iostream>
#include<queue>
using namespace std; 
int tree[101],address[101];
queue<int> q;
void preoreder(int n){
    if(!tree[n]) return ;
    cout<<tree[n]<<" ";
    preoreder(2*n);
    preoreder(2*n+1);
}
void inorder(int n){
    if(!tree[n]) return ;
    inorder(2*n);
    cout<<tree[n]<<" ";
    inorder(2*n+1);
}
void postorder(int n){
    if(!tree[n]) return ;
    postorder(2*n);
    postorder(2*n+1);
    cout<<tree[n]<<" ";
}
void bfs_recursive(int n){
    if(q.empty()) return ;
    cout<<n<<" ";q.pop();
    int node=address[n];
    if(tree[2*node]) q.push(tree[2*node]);
    if(tree[2*node+1]) q.push(tree[2*node+1]);
    bfs_recursive(q.front());
}
void bfs_queue(int n){
    q.push(tree[n]);
    while(!q.empty()){
        int node=q.front();q.pop();
        int add=address[node];
        cout<<node<<" ";
        if(tree[add*2]) q.push(tree[add*2]);
        if(tree[add*2+1]) q.push(tree[add*2+1]);
    }
}
int main(){
    tree[1]=1;address[1]=1;
    tree[2]=2;address[2]=2;
    tree[3]=3;address[3]=3;
    tree[4]=4;address[4]=4;
    tree[5]=5;address[5]=5;
    tree[8]=7;address[7]=8;
    tree[9]=8;address[8]=9;
    tree[6]=6;address[6]=6;
    tree[12]=9;address[9]=12;
    preoreder(1);cout<<endl;
    inorder(1);cout<<endl;
    postorder(1);cout<<endl;
    bfs_queue(1);cout<<endl;
    q.push(1);bfs_recursive(1);
    return 0;
}