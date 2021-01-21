#include <iostream>
using namespace std;

int main(){
    int i=0;
    while(i<=127){
        cout<<i++<<"\t"<<char(i)<<endl;
    }
    return 0;
}
