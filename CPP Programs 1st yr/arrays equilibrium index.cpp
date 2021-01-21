#include <iostream>
using namespace std;

int main(){
    int A[10]={1,-5,4,4,-6,5,1};
    for(int i=0;i<7;i++){
        int suml=0,sumh=0;
        for(int j=0;j<i;j++)
            suml+=A[j];
        for(int k=i+1;k<7;k++)
            sumh+=A[k];
        if(suml==sumh)
            cout<<"Equilibrium index: "<<i;
        }
    return 0;
}
