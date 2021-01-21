#include <iostream>
using namespace std;

bool palindrome(char s[],int n,int l=0){
    if(s[l]==s[n-1] && l<n)
        return palindrome(s,l+1,n-1);
    if(l>n)
        return 1;
    return 0;
}

int main(){
    char str[10]="malayalam";

    if(palindrome(str,9))
        cout<<"Palindrome";
    else
        cout<<"Not Palindrome";
    return 0;
}
