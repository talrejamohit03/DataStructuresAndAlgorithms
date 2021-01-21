#include <iostream>
using namespace std;
class Complex{
    public:
        Complex addition(Complex cobj);
        Complex subtraction(Complex cobj);
        Complex multiplication(Complex cobj);
        void set_data();
        void get_data();
    private:
        double a;
        double b;
};
Complex Complex::addition(Complex cobj){
    Complex temp;
    temp.a=a+cobj.a;
    temp.b=b+cobj.b;
    return temp;
}
Complex Complex::subtraction(Complex cobj){
    Complex temp;
    temp.a=a-cobj.a;
    temp.b=b-cobj.b;
    return temp;
}
Complex Complex::multiplication(Complex cobj){
    Complex temp;
    temp.a=a*cobj.a-b*cobj.b;
    temp.b=b*cobj.a+a*cobj.b;
    return temp;
}
void Complex::set_data(){
    cout<<"Enter real part of complex number ";
    cin>>a;
    cout<<"Enter imaginary part of complex number ";
    cin>>b;
}
void Complex::get_data(){
    cout<<"Complex number is "<<a<<"+"<<b<<"i"<<endl;
}
int main(){
    Complex obj1,obj2,obj3;
    cout<<"For 1st complex number: "<<endl;
    obj1.set_data();
    cout<<"For 2nd complex number: "<<endl;
    obj2.set_data();
    obj3=obj1.addition(obj2);
    cout<<"After addition: "<<endl;
    obj3.get_data();
    obj3=obj1.subtraction(obj2);
    cout<<"After subtraction: "<<endl;
    obj3.get_data();
    obj3=obj1.multiplication(obj2);
    cout<<"After multiplication: "<<endl;
    obj3.get_data();
    return 0;
}
