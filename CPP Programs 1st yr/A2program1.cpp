#include <iostream>
using namespace std;
int exponent(int a, int b){
    int x=1;
    for(int i=1;i<=b;i++)
        x*=a;
    return x;
}

int main(){
    int x,y;
    cout<<"Enter base: ";
    cin>>x;
    cout<<"Enter exponent: ";
    cin>>y;
    cout<<x<<" raised to "<<y<<" equals "<<exponent(x,y);
    return 0;
}
