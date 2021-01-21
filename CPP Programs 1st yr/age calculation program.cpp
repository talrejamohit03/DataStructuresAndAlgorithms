#include <iostream>
using namespace std;

int main(){
    int bd,bm,by,cd,cm,cy,ay,am,ad;
    cout<<"Enter your date of birth DD MM YYYY: ";
    cin>>bd>>bm>>by;
    cout<<"Enter the current date DD MM YYYY: ";
    cin>>cd>>cm>>cy;
    int Lm[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    ay=cy-by;
    if(cm<bm){
        ay-=1;
        am=cm+12-bm;
    }else{
        am=cm-bm;
    }
    if(cd<bd){
        am-=1;
        ad=Lm[cm]-bd+cd;
    }else{
        ad=cd-bd;
    }
    cout<<"\nYour age is: "<<ay<<" years "<<am<<" months "<<ad<<" days.";
    return 0;
}
