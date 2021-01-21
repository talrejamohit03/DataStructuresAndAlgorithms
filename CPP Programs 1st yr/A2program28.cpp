#include <iostream>
#include <cmath>
using namespace std;

struct BankDeposit{
    double amt;
    int tenure;
};
struct Dates{
    int date;
    int month;
    int year;
};

void getDate(Dates &dt){
    cout<<"Enter date: ";
    cin>>dt.date;
    cout<<"Enter month: ";
    cin>>dt.month;
    cout<<"Enter year: ";
    cin>>dt.year;
}

int main(){
    Dates dob,dod,dom;
    cout<<"Date of Birth: ";
    getDate(dob);
    cout<<"Date of Deposit: ";
    getDate(dod);
    int age=dod.year-dob.year;
    if(dod.month<dob.month)
        age--;
    cout<<"Your age is: "<<age<<endl;
    double rate=8;
    if(age>=60)
        rate =9;
    BankDeposit bdo;
    cout<<"Enter the amount you wish to deposit: ";
    cin>>bdo.amt;
    cout<<"Enter the tenure: ";
    cin>>bdo.tenure;
    double matAmt=bdo.amt*pow((1+rate/100),bdo.tenure);
    dom=dod;
    dom.year=dod.year+bdo.tenure;
    cout<<"You would get an amount of: "<<matAmt<<" on "<<dom.date<<"/"<<dom.month<<"/"<<dom.year<<endl;
    return 0;
}
