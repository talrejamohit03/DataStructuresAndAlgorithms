#include <iostream>
using namespace std;

int flagpole(int n){
    if(n==1) return 3;
    else if(n==2)return 10;
    else return 3*flagpole(n-1)+flagpole(n-2);
}
int main(){
    int x;
    cout<< "Enter the height of the flagpole: ";
    cin>>x;
    cout<<"No. of ways: "<<flagpole(x);
}
