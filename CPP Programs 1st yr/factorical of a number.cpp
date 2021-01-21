#include <iostream>
using namespace std;
int main(){
    int n,f=1;
    cout<<"Enter the number: ";
    cin>>n;
    for(int i=1;i<=n;i++)
        f*=i;
    cout<<"Factorial of the number is: "<<f;

    return 0;
}
