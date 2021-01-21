#include <iostream>
#include <string>

using namespace std;
int main(){
    string para;
    int i=0,nlines=0,nwords=0,freq[26];
    char ch;
    for(int m=0;m<26;m++){
        freq[m]=0;
    }
    cout<<"Enter the lines: \n";

    do{
        cin.get(ch);
        para[i++]=ch;
    }while(ch!=';');
    for(int j=0;j<i;j++){
        if(para[j]=='\n'){
            nlines++;
            nwords++;
        }
        else if(para[j]==' ')
            nwords++;
        for(int k=0;k<26;k++){
            if(para[j]==65+k||para[j]==97+k){
                freq[k]++;
                break;
            }
        }
    }
    cout<<"Number of lines is: "<<nlines+1<<"Number of words is: "<<nwords+1;
    cout<<"Frequency of each character is: \n";
    for(int m=0;m<26;m++){
        char lett=65+m;
        cout<<lett<<": "<<freq[m]<<endl;
    }
    return 0;
}
