#include <iostream>
using namespace std;
int triangle(int n){
    int sum=0,flag=0;
    for(int i=0;i<=n;i++){
        sum+=i;
        if(sum==n){
                flag=1;
                break;
        }
    }
    return flag;
}
int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    if (triangle(n))cout<<"Triangular number";
    else cout<<"Not triangular";
    return 0;
}
