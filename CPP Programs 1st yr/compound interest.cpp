#include <iostream>
#include <cmath>
using namespace std;
int main(){
    double p,r,t,ci;
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(5);
    cout<<"Enter Principal amount: ";
    cin>>p;
    cout<<"Enter Rate of Interest: ";
    cin>>r;
    cout<<"Enter time: ";
    cin>>t;
    ci=p*pow((1+r/100),t)-p;
    cout<<"Compound Interest is: "<<ci;
    return 0;
}
