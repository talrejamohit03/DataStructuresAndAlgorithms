#include <iostream>
using namespace std;

class SavingsAccount{
    public:
        static double rate;
        double calculatemonthlyinterest();
        void modifyinterestrate(double newrate);
        void set_data();
        void get_data();
    private:
        double bal;
};
double SavingsAccount::rate=0.08;
double SavingsAccount::calculatemonthlyinterest(){
    double interest = (bal*rate)/12;
    bal+=interest;
    return interest;
}
void SavingsAccount::modifyinterestrate(double newrate){
    SavingsAccount::rate=newrate;
}
void SavingsAccount::set_data(){
    cout<<"Enter the balance you wish to deposit: ";
    cin>>bal;
}
void SavingsAccount::get_data(){
    cout<<"Your current savings are: "<<bal<<endl;
}
int main(){
    SavingsAccount saObj;
    saObj.set_data();
    saObj.get_data();
    cout<<"Monthly interest at 8% per annum for this month has been credited = "<<saObj.calculatemonthlyinterest()<<endl;
    saObj.get_data();
    double nr;
    cout<<"Enter new interest rate in percentage: ";
    cin>>nr;
    saObj.modifyinterestrate(nr/100);
    cout<<"Monthly interest at "<<nr <<"% per annum for the next month has been credited = "<<saObj.calculatemonthlyinterest()<<endl;
    saObj.get_data();
    return 0;
}
