#include <iostream>
using namespace std;
int getone(int n){
    int c=0;
    while(n!=1){
        if(n%2==0){
            n/=2;
            c+=1;
        }else{
            n=3*n+1;
            c+=1;
        }
        cout<<n<<" ";
    }
    return c;
}
int main(){
    int x,n;
    cout<<"Enter the number: ";
    cin>>x;
    n=getone(x);
    cout<<"Number of tries is: "<<n;
    return 0;
}
