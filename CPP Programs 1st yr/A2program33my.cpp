#include <iostream>
using namespace std;
class Date{
    private:
        int d;
        int m;
        int y;
    public:
        Date(int id,int im,int iy){
            d=id;m=im;y=iy;
        }
        Date (const Date &obj){
            d=obj.d;
            m=obj.m;
            y=obj.y;
        }
        static int Lm[12];
        void nextday(){
            if(d==Lm[m-1]){
                if(m==12){
                        d=1;
                        m=1;
                        y+=1;
                }else{
                        d=1;
                        m+=1;
                }
            }else{
                d+=1;
            }
            cout<<"Next day is: "<<d<<"/"<<m<<"/"<<y<<endl;
        }
        int getm(){
            return m;
        }
        int gety(){
            return y;
        }
};
int Date::Lm[12]={31,28,31,30,31,30,31,31,30,31,30,31};
void leapyr(int y){
        if(y%4==0&&y%100!=0){
                Date::Lm[1]+=1;
        }else if(y%400==0)
                Date::Lm[1]+=1;
}
int main(){
        int ud,um,uy;
        cout<<"Enter day month year: ";
        cin>>ud>>um>>uy;
        const Date uobj(ud,um,uy);//Object in constant state throughout the program.
        Date dobj(uobj);
        leapyr(uy);
        int ch;
        cout<<"Enter \n1. increment till next month."<<"\n2. increment till next year.\n";
        cin>>ch;
        if(ch==1){
            cout<<"Incrementing till next month: "<<endl;
            while(dobj.getm()!=um+1){
                dobj.nextday();
            }
        }else{
            cout<<"Incrementing till next year: "<<endl;
            while(dobj.gety()!=uy+1){
                dobj.nextday();
            }
        }
        return 0;
}
