#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter a year less than 4000: ";
    cin>>n;
    cout<<"\n";
    for(int i=0;i<(n/1000);i++)
        cout<<"M";
    n=n%1000;
    if(n>=400&&n<500)
        cout<<"CD";
    else if(n>=900)
        cout<<"CM";
    else if(n<400){
        for(int j=0;j<(n/100);j++)
            cout<<"C";
    }
    else if(n>=500&&n<900){
        cout<<"D";
        for (int i=0;i<(n-500)/100;i++)
            cout<<"C";
    }
    n=n%100;
    if(n>=40&&n<50)
        cout<<"XL";
    else if(n>=90)
        cout<<"XC";
    else if(n<40){
        for(int j=0;j<(n/10);j++)
            cout<<"X";
    }
    else if(n>=50&&n<90){
        cout<<"L";
        for (int i=0;i<(n-50)/10;i++)
            cout<<"X";
    }
    n=n%10;
    if(n==4)
        cout<<"IV";
    else if(n==9)
        cout<<"IX";
    else if(n<4){
        for(int j=0;j<n;j++)
            cout<<"I";
    }
    else if(n>=5&&n<9){
        cout<<"V";
        for (int i=0;i<n-5;i++)
            cout<<"I";
    }
    return 0;
}
