#include<iostream>
using namespace std;
int func(int n){
    if(n==1) return 2;
    return func(n-1)+n;
}
int main(){
    cout<<func(7);
    return 0;
}