#include <iostream>
#include <string>
using namespace std;

void permutations(string s,int l,int h){
    if(l==h){
        cout<<s<<endl;
        return;
    }
    for(int i=l;i<h;i++){
        char temp=s[i];
        s[i]=s[l];
        s[l]=temp;
        permutations(s,l+1,h);
    }
}
int main(){
    string s1;
    cout<<"Enter the string of characters: ";
    cin>>s1;
    permutations(s1,0,s1.length());
    return 0;
}
