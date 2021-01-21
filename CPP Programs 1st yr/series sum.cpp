//sum of series x+(x^^2)/2+(x^^3)/3+...+(x^^n)/n
#include <iostream>
#include <cmath>
using namespace std;
int main(){
    float x,n,sum=0,term;
    cout<<"x+(x^^2)/2+(x^^3)/3+...+(x^^n)/n";
    cout<<"\nEnter the value of x: ";
    cin>>x;
    cout<<"Enter the value of n: ";
    cin>>n;
    for(int i=1;i<=n;i++){
        term=pow(x,i)/i;
        if(i==n)
            cout<<term;
        else
            cout<<term<<" + ";
        sum+=term;
    }
    cout<<"\nSum of the series is: "<<sum;
    return 0;
}
