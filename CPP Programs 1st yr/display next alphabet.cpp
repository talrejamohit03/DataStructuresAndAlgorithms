#include <iostream>
using namespace std;
int main(){
    char ch;
    cout<<"Enter any character: ";
    cin>>ch;
    cout<<"The next character is: "<<char(ch+1);
    return 0;
}
