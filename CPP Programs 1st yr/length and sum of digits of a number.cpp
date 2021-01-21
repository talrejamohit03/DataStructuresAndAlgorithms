#include <iostream>
using namespace std;
int main(){
    int n,c=0,dig,sum=0;
    cout<<"Enter a number: ";
    cin>>n;
    while(n!=0){
        dig=n%10;
        n=n/10;
        sum+=dig;
        c+=1;
    }
    cout<<"Length of integer is: "<<c
    <<"\nSum of digits is: "<<sum;
    return 0;
}
