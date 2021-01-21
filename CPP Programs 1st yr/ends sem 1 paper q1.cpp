#include <iostream>
using namespace std;

int main(){
    int v1,v2;
    int nmax=1,currentmax=1;
    cout<<"Enter the first integer: ";
    cin>>v1;
    do{
        cout<<"Enter the next integer: ";
        cin>>v2;
        if(v2>v1){
            currentmax+=1;
            v1=v2;
        }
        if(currentmax>nmax){
            nmax=currentmax;
        }
        if(v2<v1){
            v1=v2;
            currentmax=1;
        }

    }while(v2!=-1);
    cout<<"Length of maximum non-decreasing subsequence is: "<<nmax;
    return 0;
}
