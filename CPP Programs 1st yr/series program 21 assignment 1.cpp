#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n,sign=1;
    cout<<"Enter the number of terms: ";
    cin>>n;
    float x,sum=0,term;
    cout<<"Enter value of x: ";
    cin>>x;
    for (int i=1;i<=n;i++){
        int fact=1;
        for (int j=1;j<=(2*i-1);j++)
            fact*=j;
        term=(sign*pow(x,(2*i-1)))/fact;
        sum+=term;
        sign*=-1;
        cout<<"("<<term<<")"<<" + ";
    }
    cout<<"\nSum is: "<<sum;
    return 0;
}
