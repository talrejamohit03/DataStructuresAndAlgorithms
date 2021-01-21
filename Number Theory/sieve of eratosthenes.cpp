#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    bool sieve[n+1];
    for(int i=0;i<=n;i++)
        sieve[i]=1;
    for(int i=2;i*i<=n;i++){
        if(sieve[i]){
            for(int j=2*i;j<=n;j+=i){
                sieve[j]=0;
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(sieve[i])
            cout<<i<<" ";
    }
    return 0;
}
