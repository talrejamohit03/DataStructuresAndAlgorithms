#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
int main(){
    char phone[18],area[5],numb[11],last6[7];
    cout<<"Enter the phone number: ";
    cin.getline(phone,19);
    cout<<phone<<endl;
    char* tok=strtok(phone,"()-");
    strcpy(area,tok);
    cout<<area<<endl;
    tok=strtok(NULL,"()-");
    strcpy(numb,tok);
    cout<<numb<<endl;
    tok=strtok(NULL,"()-");
    strcpy(last6,tok);
    cout<<last6<<endl;

    strcat(numb,last6);
    int ar=atoi(area);
    long nu=atol(numb);
    cout<<"Area code is: "<<ar<<"\nPhone number is: "<<nu;
    return 0;
}
