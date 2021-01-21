#include <iostream>
#include <string>
using namespace std;

int main(){
    string *p;
    string s;
    cout<<"Enter string: ";
    cin>>s;
    p=&s;
    cout<<*p;
    return 0;
}
