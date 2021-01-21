#include <iostream>
using namespace std;
int main(){
    int a,b,c;
    cout<<"Enter the 3 numbers: ";
    cin>>a>>b>>c;
    if((a>b)&&(b>c))
        cout<<"1st number is greatest";
    else if((a<b)&&(b<c))
        cout<<"3rd number is greatest";
    else
        cout<<"2nd number is greatest";
    return 0;
}
