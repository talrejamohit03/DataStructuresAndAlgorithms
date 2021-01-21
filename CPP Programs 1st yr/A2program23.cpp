#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

int main(){
    ifstream fin("IN.TXT");
    int al=0,dig=0,sp=0;
    char ch;
    fin.get(ch);
    do{
        if(isalpha(ch))
            al++;
        else if (isdigit(ch))
            dig++;
        else
            sp++;
        fin.get(ch);
    }while(!fin.eof());
    ofstream fout("OUT.TXT");
    fout<<"Number of alphabets: "<<al<<"\nNumber of digits: "<<dig<<"\nNumber of special characters: "<<sp;
    fin.close();
    fout.close();
}

