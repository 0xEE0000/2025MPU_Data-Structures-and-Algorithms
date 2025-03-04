#include<iostream>
using namespace std;
int hanoi(int n){
    if(n==1) return 1;
    return hanoi(n-1)*2+1;
}
int main(){
    cout<<hanoi(6);
    return 0;
}