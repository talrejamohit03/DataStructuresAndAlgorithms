#include <bits/stdc++.h>
using namespace std;

int main(){
int A;
cin>>A;
vector<bool> sieve(A+1,1);
    sieve[0]=0;
    sieve[1]=0;
    for(int i=2;i*i<=A;i++){
        if(sieve[i]){
            for(int j=2*i;j<=A;j+=i)
                sieve[j]=0;
        }
    }
    int i=2;
    vector<int> pfpow;
    while(A>1){
        while(!sieve[i])i++;
        if(A%i!=0){
            i++;
            continue;
        }
        int p=0;
        while(A>1 && A%i==0){
            p++;
            A/=i;
        }
        pfpow.push_back(p);
        i++;
    }
    for(int i=0;i<pfpow.size()-1;i++){
        if(pfpow[i]!=pfpow[i+1])
            return 0;
    }
    return 0;
}
