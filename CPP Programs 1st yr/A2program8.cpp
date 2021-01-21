#include <iostream>
using namespace std;
int i=1;
int hanoi(int n, int src,int dest, int temp){
    if(n==1){
        cout<<"\nMove "<<n<<" from "<<src<<" to "<<dest;
        cout<<"\n"<<i++;
    }
    else{
        hanoi(n-1,src,temp,dest);
        cout<<"\nMove "<<n<<" from "<<src<<" to "<<dest;
        cout<<"\n"<<i++;
        hanoi(n-1,temp,dest,src);
    }
}
int main(){
    int s,t,d,x;
    cout<<"enter source, temporary and destination variables: ";
    cin>>s>>t>>d;
    cout<<"Enter number of discs: ";
    cin>>x;
    hanoi(x,s,t,d);
    return 0;
}
