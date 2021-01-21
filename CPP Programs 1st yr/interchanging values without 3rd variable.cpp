#include <iostream>
using namespace std;
int main(){
    int A,B;
    cout<<"Enter the value of A: ";
    cin>>A;
    cout<<"\nEnter the value of B: ";
    cin>>B;
    A=A+B;
    B=A-B;
    A=A-B;
    cout<<"\nThe values after interchanging are "
    <<"A = "<<A<<" and B = "<<B;
    return 0;
}
