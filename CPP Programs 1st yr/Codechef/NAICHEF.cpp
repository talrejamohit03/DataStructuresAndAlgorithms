#include <iostream>
using namespace std;

int main(){
    int t,n,a,b;
    cin>>t;
    float *prob;
    prob=new float[t];
    for(int i=0;i<t;i++){
        cin>>n>>a>>b;
        int na=0,nb=0,x;
        for(int j=0;j<n;j++){
            cin>>x;
            if(x==a && x==b){
                na++;
                nb++;
            }
            else if(x==a)
                na++;
            else if(x==b)
                nb++;
        }
        prob[i]=((na*1.0)/n)*((nb*1.0)/n);
    }
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(10);
    for(int i=0;i<t;i++)
        cout<<prob[i]<<endl;
    delete []prob;
    return 0;
}
