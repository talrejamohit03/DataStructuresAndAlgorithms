#include <iostream>
using namespace std;

int main(){
    for(int i=0;i<7;i++){
        for(int j='A';j<=('G'-i);j++)
            cout<<(char) j;
        for(int m=0;m<2*i-1;m++)
            cout<<" ";
        if(i==0){
            for(int k='F';k>='A';k--)
                cout<<(char) k;
        }else{
            for(int k='G'-i;k>='A';k--)
                cout<<(char) k;
        }
        cout<<"\n";
    }
    return 0;
}
