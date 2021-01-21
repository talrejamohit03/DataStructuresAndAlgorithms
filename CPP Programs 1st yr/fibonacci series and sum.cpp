#include <iostream>
using namespace std;
int main(){
    int first=0,second=1,third,n,sum=1;
    cout<<"Enter the number of terms: ";
    cin>>n;
    cout<<first<<" "<<second<<" ";
    for(int i=1;i<=(n-2);i++){
        third=first+second;
        first=second;
        second=third;
        cout<<third<<" ";
        sum+=third;
    }
    cout<<"The sum of the series is: "<<sum;
    return 0;
}
