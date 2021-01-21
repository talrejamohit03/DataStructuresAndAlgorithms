#include <iostream>
using namespace std;
void swap(int &x,int &y){
    int t;
    t=x;
    x=y;
    y=t;
}
int main(){
    int A[7]={6,3,8,2,9,4,7};
    int l=0,h=6;
    while(l<h){
        while(A[l]%2==0)l++;
        while(A[h]%2!=0)h--;
        if(l>h)break;
        swap(A[l],A[h]);
    }
    for(int i=0;i<7;i++)
        cout<<A[i]<<" ";
}
