#include <iostream>
using namespace std;
int main(){
    int n,i=2,flag;
    cout<<"Enter n: ";
    cin>>n;
    while(n!=1){
        flag=0;
        for(int j=2;j<i/2;j++){
            if(i%j==0){
                flag=1;break;
            }
        }
        if(flag==0){
            if(n%i==0){
                cout<<i<<" ";
                n=n/i;
            }else{
                i++;continue;
            }
        }else{i++;}
    }
    return 0;
}
