#include <iostream>
using namespace std;
int main(){
    char i,j;
    for(i=69;i>=65;i--){
        for(j=65;j<=i;j++)
            cout<<j;
        cout<<"\n";
    }
    return 0;
}
