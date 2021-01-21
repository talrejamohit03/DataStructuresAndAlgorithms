#include <iostream>
using namespace std;

int main(){
    int *p=new int[3];
    p[0]=1;p[1]=2,p[2]=3;
    for(int i=0;i<3;i++)
        cout<<p[i]<<" ";
    return 0;
}
