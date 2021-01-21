#include <iostream>
using namespace std;
bool eqcheck(int A[],int s){
    bool flag;
    for(int i=0;i<s-1;i++){
        if(A[i]!=A[i+1]){
            flag=0;
            return flag;
        }else{
            flag=1;
        }
    }
    return flag;
}
int main(){
    int t,w[100],n,out[100];
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        for(int j=0;j<n;j++)
            cin>>w[j];
        int x=0;
        /*bool rflag=eqcheck(w,n);
        while(rflag==0){
            int m=0;//index of loser-worker
            for(int j=0;j<n;j++){
                if(w[j]>w[m])
                    m=j;
            }
            for(int k=0;k<n;k++)
                w[k]++;
            w[m]--;
            x++;
            rflag=eqcheck(w,n);
        }*/
        int m=0;//index of loser-worker
        for(int j=0;j<n;j++){
                if(w[j]>w[m])
                    m=j;
            }
        for(int j=0;j<n;j++){
            x+=w[m]-w[j];
        }
        out[i]=x;
    }
    for(int i=0;i<t;i++)
        cout<<out[i]<<endl;
    return 0;
}
