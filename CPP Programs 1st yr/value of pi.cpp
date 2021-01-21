#include <iostream>
using namespace std;
int main(){
    int n,i=0,sign=1;
    cout<<"Enter the number of terms: ";
    cin>>n;
    float term,sum=0;
    while(i<=n){
        term=(4.0*sign)/(2*i+1);
        sum+=term;
        i+=1;
        sign=sign*-1;
        cout<<"("<<term<<")"<<" + ";
    }
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(3);
    cout<<"\nValue of pi up to "<< n <<" terms is: "<<sum;
    return 0;
}
