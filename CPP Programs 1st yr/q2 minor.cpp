#include <iostream>
using namespace std;
int main(){
    int x,n=x,rev=0,dig;
    cout<<"Enter x: ";
    cin>>x;
    while(rev!=x-1){
        rev=0;
        n=x;
        while(n>0){
            dig=n%10;
            rev=rev*10+dig;
            n=n/10;
        }
        x+=1;
    }
    cout<<"Answer: "<<x-1;
    return 0;
}
