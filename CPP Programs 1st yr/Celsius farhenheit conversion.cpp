#include <iostream>
using namespace std;
int main(){
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(6);
    while (true)
    {
        int ch;
        cout<<"\n1. To convert from Celsius to Fahrenheit\n"
        <<"2. To convert from Fahrenheit to Celsius \nEnter choice: ";
        cin>>ch;
        switch (ch)
        {
        case 1:
            float tc;
            cout<<"\nEnter Celsius temperature: ";
            cin>>tc;
            cout<<"\nTemperature in Fahrenheit is: "
            <<1.8*tc+32;
            break;
        case 2:
            float tf;
            cout<<"\nEnter Fahrenheit temperature: ";
            cin>>tf;
            cout<<"\nTemperature in Celsius is: "
            <<(tf-32)*100/180;
            break;
        }
    }
    return 0;
}
