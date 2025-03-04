#include<iostream>
using namespace std;
struct node{
    int x;
    struct node* next;
    struct node* prev;
};
int hashing(int n){
    return n%20;
}
class Chaining_Hasing{
    public:
        struct node* head[20];
        struct node* tail[20];
        Chaining_Hasing(){
            for(int i=0;i<20;i++){
                head[i]=NULL;
                tail[i]=NULL;
            }
        }
        void insertion(int n);
        void deletion(int n);
        void searching(int n);
};
void Chaining_Hasing::insertion(int n){
    int key=hashing(n);
    struct node* t=(struct node*)malloc(sizeof(struct node));
    t->next=NULL;t->prev=NULL;t->x=n;
    if(head[key]==NULL){
        head[key]=t;
        tail[key]=t;
        return ;
    }
    tail[key]->next=t;
    t->prev=tail[key];
    tail[key]=t;
    return ;
}
void Chaining_Hasing::deletion(int n){
    int key=hashing(n);
    struct node* tmp=head[key];
    while(tmp){
        if(tmp->x==n){
            if(tmp==head[key]){
                head[key]=head[key]->next;
                if(head[key]) head[key]->prev=NULL;
                else tail[key]=NULL;
            }else{
                if(tmp->prev) tmp->prev->next=tmp->next;
                if(tmp->next) tmp->next->prev=tmp->prev;
                else tail[key]=tmp->prev;
            }
            return ;
        }
        tmp=tmp->next;
    }
    return ;
}
void Chaining_Hasing::searching(int n){
    int key=hashing(n);
    struct node* tmp=head[key];
    while(tmp){
        if(tmp->x==n){
            cout<<n<<" ";
            return ;
        }
        tmp=tmp->next;
    }
    cout<<"This data does not exist.";
    return ;
}
class Open_Address_Hashing{
    public:
        int hash[20];
        string empty;
        Open_Address_Hashing(){
            for(int i=0;i<20;i++){
                hash[i]=0;
                empty+="0";
            }
        }
        void insertion(int n);
        void deletion(int n);
        void searching(int n);
};
void Open_Address_Hashing::insertion(int n){
    int key=hashing(n);
    while(empty[key]=='1') key=(key+1)%20;
    hash[key]=n;empty[key]='1';
    return ;
}
void Open_Address_Hashing::deletion(int n){
    int key=hashing(n);
    while(hash[key]!=n) key=(key+1)%20;
    hash[key]=0;empty[key]='#';
    return ;
}
void Open_Address_Hashing::searching(int n){
    int key=hashing(n);
    while(hash[key]!=n&&empty[key+1]!='0') key=(key+1)%20;
    if(hash[key]==n) cout<<hash[key];
    else cout<<"This data does not exist.";
    return ;
}
int main(){
    int n;cin>>n;
    // Chaining_Hasing hash1;
    // for(int i=1;i<=n;i++){
    //     int x;cin>>x;
    //     hash1.insertion(x);
    // }
    // hash1.searching(1);cout<<endl;
    // hash1.searching(21);cout<<endl;
    // hash1.deletion(1);
    // hash1.searching(1);
    Open_Address_Hashing hash2;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        hash2.insertion(x);
    }
    hash2.searching(1);cout<<endl;
    hash2.deletion(1);
    hash2.searching(1);cout<<endl;
    hash2.searching(2);cout<<endl;
    hash2.deletion(2);
    hash2.searching(2);
    return 0;
}