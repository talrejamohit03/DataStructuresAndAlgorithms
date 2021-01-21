#include <iostream>
using namespace std;

int main(){
    int T,outp[100],N;
    int order=1;
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>N;
        int *a;
        a=new int[N];
        for(int j=0;j<N;j++)
            cin>>a[j];
        int n=N-1;
        if(a[N/2]!=7){
            outp[i]=0;
            continue;
            delete [] a;
        }
        for(int m=0;m<N/2;m++){
            if(a[m]==a[n]&&a[m]==order){
                n--;
                if(a[m+1]!=a[m])
                    order++;
            }else{
                outp[i]=0;
                break;
            }
            outp[i]=1;
        }
        delete [] a;
    }
    for(int i=0;i<T;i++){
        if(outp[i])
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    return 0;
}
