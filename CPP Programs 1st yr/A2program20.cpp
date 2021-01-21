#include <iostream>
#include <string>
using namespace std;

int main(){
    string str,subs;
    cout<<"Enter the string: ";
    getline(cin,str);
    cout<<"Enter substring: ";
    cin>>subs;
    int beg=0;
    cout<<"Substring found at positions: \n";
    while(beg<str.length()){
        int ind=str.find(subs,beg);
        if(ind==-1){
            cout<<"Not found!!";
            break;
        }else{
            cout<<ind<<" ";
            beg=ind+subs.length();
        }
    }
    return 0;
}
