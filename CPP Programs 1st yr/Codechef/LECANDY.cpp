#include <iostream>
using namespace std;

int main(){
    int N,T,T1,C,A,j=0;
    bool out[1000];
    cin>>T;
    T1=T;
    while(T!=0){
        cin>>N>>C;
        int sum=0;
        for(int i=0;i<N;i++){
            cin>>A;
            sum+=A;
        }
        if(sum<=C)
            out[j]=1;
        else
            out[j]=0;
        j++;
        T--;
    }
    for(int i=0;i<T1;i++){
        if(out[i])
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
