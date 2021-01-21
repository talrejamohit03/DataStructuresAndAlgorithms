//sum of series x+(x^^3)/3!+(x^^5)/5!+...+(x^^2n-1)/(2n-1)!
#include <iostream>
#include <cmath>
using namespace std;
int main(){
    float x,n,sum=0,term,f=1;
    cout<<"x+(x^^3)/3!+(x^^5)/5!+...+(x^^2n-1)/(2n-1)!";
    cout<<"\nEnter the value of x: ";
    cin>>x;
    cout<<"Enter number of terms in the series: ";
    cin>>n;
    for(int i=1;i<=(2*n-1);i+=2){
        f=1;
        for(int j=1;j<=i;j++)
            f*=j;
        term=pow(x,i)/f;
        if(i==(2*n-1))
            cout<<term;
        else
            cout<<term<<" + ";
        sum+=term;
    }
    cout<<"\nSum of the series is: "<<sum;
    return 0;
}

