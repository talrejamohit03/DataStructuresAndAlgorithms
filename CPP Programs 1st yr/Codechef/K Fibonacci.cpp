#include <iostream>
using namespace std;

int main(){
    long long int n,k;
    cin>>n>>k;
    long long int arr[n];
    for (long long int i=0;i<n;i++){
        if(i<k)
            arr[i]=1;
        else if(i==k)
            arr[i]=k;
        else{
            /*long long int sum=0;
            for(long long int j=i-k;j<i;j++)
                sum+=arr[j];
            arr[i]=sum;*/
            arr[i]=(2*arr[i-1]-arr[i-1-k])%(1000000007);
        }
    }
    cout<<arr[n-1];
    return 0;
}
