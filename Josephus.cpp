#include<iostream>
using namespace std;
int func(int n){
    if(n==2) return 1;
    else if(n==3) return 2;
    if(n%2==0) return 2*func(n/2)-1;
    return 2*func(n/2)+1;
}
int main(){
    cout<<func(10);
    return 0;
}