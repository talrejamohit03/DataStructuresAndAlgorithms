#include <iostream>
using namespace std;

int main(){
    int A[100];
    for (int i=0;i<100;i++)
        A[i]=i+1;
    for(int j=1;j<100;j++){
        for(int k=2*A[j];k<100;k+=A[j]){
            A[k-1]=0;
        }
    }
    for(int m=0;m<100;m++){
            if(A[m]!=0)
                cout<<A[m]<<" ";
    }
    return 0;
}
