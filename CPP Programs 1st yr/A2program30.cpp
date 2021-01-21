#include <iostream>
#include <cstring>
using namespace std;

struct cricket{
    char pname[50];
    char tname[50];
    double avg;
};
void new_line(){
    char ch;
    do{
        cin.get(ch);
    }while(ch!='\n');
}
int main(){
    cricket player[50];
    char teams[30][50];
    int nteams=0;
    cout<<"Enter information: "<<endl;
    for(int i=0;i<50;i++){
        cricket temp;
        cout<<"Player "<<i+1<<":"<<endl;
        cout<<"Enter player name: ";
        cin.getline(temp.pname,50);
        cout<<"Enter team name: ";
        cin.getline(temp.tname,50);
        cout<<"Enter batting average: ";
        cin>>temp.avg;
        new_line();
        bool flag=1;
        for(int j=0;j<nteams;j++){
            if(!strcmp(temp.tname,teams[j])){
                flag=0;
                break;
            }
        }
        if(flag==1){
            strcpy(teams[nteams],temp.tname);
            nteams++;
        }
        player[i]=temp;
    }
    for(int i=0;i<nteams;i++){
        cout<<teams[i]<<endl;
        for(int j=0;j<50;j++){
            if(!strcmp(player[j].tname,teams[i])){
                cout<<player[j].pname<<"\t"<<player[j].avg<<endl;
            }
        }
    }
}
