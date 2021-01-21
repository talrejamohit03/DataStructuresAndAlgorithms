#include <iostream>
using namespace std;
int main(){
    for(int i=1;i<=7;i++){
        for(int j=6;j>=i;j--)
            cout<<"  ";
        for(int k=1;k<=(2*i-1);k++)
            cout<<"*"<<" ";
        cout<<"\n";
    }
    for(int i=6;i>=1;i--){
        for(int j=1;j<=7-i;j++)
            cout<<"  ";
        for(int k=1;k<=(2*i-1);k++)
            cout<<"*"<<" ";
        cout<<"\n";
    }
    return 0;
}
