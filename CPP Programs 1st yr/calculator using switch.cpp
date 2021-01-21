#include <iostream>
using namespace std;
int main(){
    char ch='y';
    do{
        int n;
        float x,y;
        cout<<"Enter first number: ";
        cin>>x;
        cout<<"Enter second number: ";
        cin>>y;
        cout<<"Enter your choice: \n"<<"1. + \n"
        <<"2. - \n"<<"3. * \n"<<"4. / \n";
        cin>>n;
        switch(n){
        case 1:
            cout<<x<<" + "<<y<<" = "<<x+y;
            break;
        case 2:
            cout<<x<<" - "<<y<<" = "<<x-y;
            break;
        case 3:
            cout<<x<<" * "<<y<<" = "<<x*y;
            break;
        case 4:
            if(y==0){
                cout<<"Division by zero not defined!! Please enter a valid number.";
                break;
            }else{
                cout<<x<<" / "<<y<<" = "<<x/y;
                break;
            }
        }
        cout<<"\nDo you wish to continue (y/n)? ";
        cin>>ch;
    }while(ch=='y');

    return 0;
}
