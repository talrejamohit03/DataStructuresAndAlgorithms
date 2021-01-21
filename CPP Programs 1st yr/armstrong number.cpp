#include <iostream>
using namespace std;
int main(){
    int n,test,digit,sum=0;
    cout<<"Enter any number: ";
    cin>>n;
    test=n;
    while(test!=0){
        digit=test%10;
        sum+=digit*digit*digit;
        test/=10;
    }
    if(sum==n)
        cout<<"Armstrong number";
    else
        cout<<"Not an Armstrong number";
    return 0;
}

