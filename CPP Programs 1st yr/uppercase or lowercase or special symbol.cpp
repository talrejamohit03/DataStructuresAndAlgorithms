#include <iostream>
using namespace std;
int main(){
    while(true){
        char ch;
        cout<<"\nEnter a character: ";
        cin>>ch;
        if(ch>='A'&&ch<='Z')
            cout<<"Uppercase letter";
        else if(ch>='a'&&ch<='z')
            cout<<"Lowercase letter";
        else if(ch>='0' && ch<='9')
            cout<<"Digit";
        else
            cout<<"Special character";
    }
    return 0;
}
