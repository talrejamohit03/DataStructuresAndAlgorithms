#include <iostream>
using namespace std;
int main(){
    for(int i=69;i>=65;i--){
        for(char j=65;j<=i;j++)
            cout<<j;
        cout<<"\n";
    }
    return 0;
}
