#include <iostream>
using namespace std;

void change(int D[],int d,int n,int i){
    //static int i=0;
    if(D[i]<=n && n>0){
        cout<<D[i]<<" ";
        change(D,d,n-D[i],i);
    }
    else if(D[i]>n && n>0){
        change(D,d,n,++i);
    }
}

int main(){
    int A[8]={200,100,50,20,10,5,2,1},x;
    cout<<"Enter the number: ";
    cin>>x;
    change(A,8,x,0);
    return 0;
}
