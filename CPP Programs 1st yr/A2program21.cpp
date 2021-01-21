#include <iostream>
#include <string>
using namespace std;

int main(){
    int n,freq[26];
    string str[100];
    cout<<"Enter the number of lines: ";
    cin>>n;
    int words=n;
    for(int m=0;m<26;m++){
        freq[m]=0;
    }
    cout<<"Enter the lines: \n";
    cin.ignore(1,'\n');
    for(int i=0;i<n;i++){
        getline(cin,str[i],'\n');
    }
    cout<<"Your input is: \n";
    for(int k=0;k<n;k++){
        cout<<str[k]<<endl;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<str[i].length();j++){
            if(str[i][j]==' ')
                words++;
            for(int m=0;m<26;m++){
                if(str[i][j]==65+m||str[i][j]==97+m){
                    freq[m]++;
                    break;
                }
            }
        }
    }
    cout<<"Number of words: "<<words<<endl;
    cout<<"Frequency of each character: "<<endl;
    for(int m=0;m<26;m++){
        char ch=65+m;
        cout<<ch<<" : "<<freq[m]<<endl;
    }
    return 0;
}
