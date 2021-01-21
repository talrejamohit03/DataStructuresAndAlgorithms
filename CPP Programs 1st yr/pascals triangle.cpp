#include <iostream>
using namespace std;
int main(){
    int n,c;
    cout<<"Enter the number of lines: ";cin>>n;
    for(int i=1;i<=n;i++){
        c=1;
        for(int k=1;k<=n-i;k++)
            cout<<" ";
        for(int j=1;j<=i;j++){
            cout<<c<<" ";
            c=c*(i-j)/j;
        }
        cout<<"\n";
    }
    return 0;
}

