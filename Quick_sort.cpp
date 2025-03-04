#include<iostream>
using namespace std;
void quick_sort(int l,int r,int q[]){
    if(l>=r) return ;
    int mid=(l+r)>>1;
    int mid_num=q[mid];
    int i=l-1,j=r+1;
    while(i<j){
        do i++; while(q[i]<mid_num);
        do j--; while(q[j]>mid_num);
        if(i<j) swap(q[i],q[j]);
    }
    quick_sort(l,j,q);quick_sort(j+1,r,q);
}
int main(){
    int q[10]={2,3,455,231,3,123,1,3,5,6};
    quick_sort(0,9,q);
    for(int i=0;i<10;i++) cout<<q[i]<<" ";
    return 0;
}