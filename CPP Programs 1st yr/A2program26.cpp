#include <iostream>
#include <fstream>
using namespace std;
void vowel_words(){
    ifstream fin("FIRST.TXT");
    ofstream fout("SECOND.TXT");
    char ch[50];
    while(!fin.eof()){
        fin>>ch;
        if(ch[0]=='a'||ch[0]=='e'||ch[0]=='i'||ch[0]=='o'||ch[0]=='u'){
            fout<<ch<<" ";
        }
    }
    fin.close();
    fout.close();
}
int main(){
    vowel_words();
}
