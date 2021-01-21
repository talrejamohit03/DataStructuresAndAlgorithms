#include <bits/stdc++.h>
using namespace std;
#define MOD 1000003

int fact(int n,int farr[]){
    if(farr[n]!=0)
        return farr[n];
    return (n*fact(n-1,farr))%MOD;
}
int ind(char c){
    return (c>='a') ? 26+c-'a' : c-'A';
}
long long int pwr(int a){
    int p=MOD-2;
    long long int base=(long long int)a,ans=1;
    while(p>0){
		if(p==1)
			return (ans*base)%MOD;
        if(!(p & 1)){
            base=(base*base)%MOD;
            p>>1;
        }else{
            ans=(ans*base)%MOD;
            p--;
        }
    }
    return ans%MOD;
}
int main() {
	string A;
	cin>>A;
    int n=A.length();
    int cnt[52]={0};
    for(int i=0;i<n;i++)
        cnt[ind(A[i])]++;
    long long int pos=1;
    int factorials[n];
    for(int i=0;i<n;i++)
        factorials[i]=0;
    factorials[0]=1;
    factorials[1]=1;
    for(int i=0;i<n;i++){
        int k=ind(A[i]);
        int permu=fact(n-i-1,factorials);
        for(int j=0;j<k;j++){
            if(cnt[j]<1)
                continue;
            long long int rep=1;
            cnt[j]--;
            for(int r=0;r<52;r++){
                if(cnt[r]>1)
                    rep=(rep*pwr(fact(cnt[r],factorials)))%MOD;
            }
            pos+=(permu*rep)%MOD;
            cnt[j]++;
        }
        //cout<<A[i]<<bef<<pos<<" ";
        cnt[k]--;
    }
    cout<< pos%MOD;
    return 0;
}
