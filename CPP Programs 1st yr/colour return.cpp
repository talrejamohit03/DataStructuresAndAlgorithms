#include <iostream>
using namespace std;
int main(){
    char ch;
    cout<<"Enter character from VIBGYOR: ";
    cin>>ch;
    switch (ch){
    case('V'):
        cout<<"Violet";
        break;
    case('I'):
        cout<<"Indigo";
        break;
    case('B'):
        cout<<"Blue";
        break;
    case('G'):
        cout<<"Green";
        break;
    case('Y'):
        cout<<"Yellow";
        break;
    case('O'):
        cout<<"Orange";
        break;
    case('R'):
        cout<<"Red";
        break;
    }
    return 0;
}
