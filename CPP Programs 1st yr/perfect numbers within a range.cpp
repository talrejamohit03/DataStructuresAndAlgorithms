#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int sum=1,x,lo,up,f;
    cout<<"Enter upper limit: ";
    cin>>up;
    cout<<"Enter lower limit: ";
    cin>>lo;
    for(int i=1;sum*x<=up;i++){
        x=pow(2,i);
        sum+=x;
        f=1;
        for(int j=2;j<sum;j++){
            if(sum%j==0){
                f=0;
                break;
            }
        }
        if(f==1)
            cout<<sum*x<<" ";
    }
    return 0;
}
