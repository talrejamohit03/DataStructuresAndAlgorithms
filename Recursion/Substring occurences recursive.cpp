#include <iostream>
#include <string>

using namespace std;

int occ(string s1,string s2){
    static int l1=0,l2=0;
    if(s1[l1]==s2[l2] && l2<s2.length()){
        l1++;l2++;
        if(l2+1==s2.length()){
            l2=0;
            return 1+occ(s1,s2);
        }
        return occ(s1,s2);
    }else if(l1==s1.length())
        return 0;
    else{
        l1++;
        return occ(s1,s2);
    }
}

int main(){
    string a1("talrejamohitaka"),a2("mohit");
    cout<<occ(a1,a2);
    return 0;

}
