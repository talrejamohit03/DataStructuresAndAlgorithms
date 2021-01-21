#include <iostream>
using namespace std;
int main(){
    int n,dig,rev=0;
    cout<<"Enter a number: ";
    cin>>n;
    while(n!=0){
        dig=n%10;
        rev=rev*10+dig;
        n=n/10;
    }
    cout<<"Reverse of the number is: "<<rev;
    return 0;
}
