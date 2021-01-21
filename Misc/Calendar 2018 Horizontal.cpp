#include <iostream>
#include <string>
using namespace std;

int main(){
    string months[12]={"January","February","March","April",
                        "May","June","July","August","September",
                        "October","November","December"
                    };
    int mdays[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    /*int year;
    cout<<"Enter year: ";
    cin>>year;
    int ryears=year%400,lyears=(ryears/4)-1;
    int space=((lyears*2)+(ryears-lyears))%7;*/
    cout<<endl;
    int space=1;
    //if(year%400==0||(year%4==0 && year%100!=0))mdays[1]++;
    for(int i=0;i<=11;i++){
        cout<<"******"<<months[i]<<"******\n";
        cout<<" S  M  T  W  T  F  S\n";
        for(int s=0;s<space;s++){
            cout<<"   ";
        }
        int d=1,wi=space;
        while(d<=mdays[i]){
            while(wi<=6){
                if(d/10==0)cout<<" ";
                cout<<d++<<" ";
                wi++;
                if(d>mdays[i])break;
            }
            wi=0;
            cout<<"\n";
        }
        /*for(int s=0;s<(mdays[i]%7);s++)
            cout<<"   ";*/
        cout<<"\n";
        space=(space+(mdays[i]%7))%7;
    }
}
