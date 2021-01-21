#include <iostream>
#include <cmath>
using namespace std;
int main(){
    float n,x,sum,term,fact,sign=-1;
    cout<<"Enter the value of x: ";cin>>x;
    cout<<"Enter the number of terms(n): ";cin>>n;
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(5);
    for(int i=2;i<=2*n;i+=2){
        fact=1;
        for(int j=1;j<=i;j++)
            fact*=j;
        term=sign*pow(x,i)/fact;
        sum+=term;
        if(sign==-1)
            cout<<" "<<term;
        else
            cout<<" + "<<term;
        sign*=-1;
    }
    cout<<"\nSum of the series is: "<<sum;
    return 0;
}
