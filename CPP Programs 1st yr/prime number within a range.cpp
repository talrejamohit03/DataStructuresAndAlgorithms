#include <iostream>
using namespace std;
int main(){
    int lo,up,f=1;
    cout<<"Enter lower limit: ";
    cin>>lo;
    cout<<"Enter upper limit: ";
    cin>>up;
    for(int i=lo;i<=up;i++){
            f=1;
        for(int j=2;j<i;j++){
            if(i%j==0){
                f=0;
                break;
            }
        }
        if(f==1)
            cout<<i<<" ";
    }
    return 0;
}
