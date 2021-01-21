#include <iostream>
#include <string>
using namespace std;

bool isRepeated(string s,int l,int h){
    for(int i=l+1;i<h;i++){
        if(s[l]==s[i])
            return 1;
    }
    return 0;
}
void swap(char &a, char &b){
    char temp=a;
    a=b;
    b=temp;
}
void permutations(string s,int l,int h){
    if(l==h){
        cout<<s<<endl;
        return;
    }
    for(int i=l;i<h;i++){
        if(isRepeated(s,i,h))
            continue;
        swap(s[i],s[l]);
        permutations(s,l+1,h);
        swap(s[i],s[l]);
    }
}
int main(){
    string s1;
    cout<<"Enter the string of characters: ";
    cin>>s1;
    permutations(s1,0,s1.length());
    return 0;
}
