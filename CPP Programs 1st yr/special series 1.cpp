//sum of series 1+1/2!+1/3!+...+1/n!
#include <iostream>
using namespace std;
int main(){
    double n,f=1,sum=0;
    cout<<"Enter the value of n in 1+1/2!+1/3!+...+1/n! : ";
    cin>>n;
    cout<<"\n";
    for(int i=1;i<=n;i++){
        f=1;
        for(int j=1;j<=i;j++)
            f*=j;
        if(i==n)
            cout<<1/f;
        else
            cout<<1/f<<" + ";
        sum+=1/f;
    }
    cout<<"\nSum of series is "<<sum;
    return 0;
}
