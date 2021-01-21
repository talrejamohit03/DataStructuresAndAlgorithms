#include <iostream>
using namespace std;
int main(){
    int n,f=1;
    cout<<"Enter a number: ";
    cin>>n;
    for(int i=2;i<n;i++){
        if(n%i==0){
            f=0;
            break;
        }
    }
    if(f==1)
        cout<<"Prime number";
    else
        cout<<"Composite number";

    return 0;
}
