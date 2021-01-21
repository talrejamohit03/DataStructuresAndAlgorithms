#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main(){
    ifstream fin1("FILE1.TXT");
    ifstream fin2("FILE2.TXT");
    ofstream fout("DATA.TXT");
    char ch1[20],ch2[20];
    do{
        fin1>>ch1;
        fin2>>ch2;
        int a=atoi(ch1);
        int b=atoi(ch2);
        if(a<b){
            fout<<ch1<<" ";
            fout<<ch2<<" ";
        }else{
            fout<<ch2<<" ";
            fout<<ch1<<" ";
        }
    }while(!(fin1.eof())&&!(fin2.eof()));
    if(!fin1.eof()){
        fin1>>ch1;
        fout<<ch1<<" ";
    }
    if(!fin2.eof()){
        fin2>>ch2;
        fout<<ch2<<" ";
    }
    fin1.close();
    fin2.close();
    fout.close();
}


