#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream fin("IN.TXT");
    ofstream fout("OUT.TXT");
    char ch;
    fin.get(ch);
    do{
        if(ch==' '){
            fout<<ch;
            while (ch==' ')
                fin.get(ch);
        }
        fout<<ch;
        fin.get(ch);
    }while(!fin.eof());
    fin.close();
    fout.close();
}

