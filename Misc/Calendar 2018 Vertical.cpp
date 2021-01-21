#include <iostream>
#include <string>
using namespace std;

int main(){
    string months[12]={"January","February","March","April",
                        "May","June","July","August","September",
                        "October","November","December"
                    };
    char days[8][2]={"S","M","T","W","T","F","S"};
    int mdays[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int space=1;
    for(int i=0;i<12;i++){
        cout<<"******"<<months[i]<<"******\n";
        int sdate=1;
        int index=space;
        for(int j=0;j<7;j++){
            cout<<days[j]<<" ";
            int sdw;//starting date of the weekday
            if(index!=0){
                cout<<"   ";
                sdw=8-index;
                index--;
            }else{
                sdw=sdate;
                sdate++;
            }
            while(sdw<=mdays[i]){
                if(sdw/10==0)cout<<" ";
                cout<<sdw<<" ";
                sdw+=7;
            }
            cout<<"\n";
        }
        cout<<"\n";
        space=(space+(mdays[i]%7))%7;
    }
    return 0;
}
