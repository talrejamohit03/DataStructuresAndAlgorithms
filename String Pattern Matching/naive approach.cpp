#include <bits/stdc++.h>
using namespace std;

int main(){
    string s1,s2;
    cin>>s1>>s2;
    int j=0,start=0;
    vector<int> indices;
    for(int i=0;i<s1.length();i++){
        if(s1[i]==s2[j]){
            if(j==0)
                start=i;
            j++;
            if(j==s2.length())
                indices.push_back(start);
        }
        else if(s1[i]==s2[0]){
            j=1;
            start=i;
        }
    }
    for(int i=0;i<indices.size();i++)
        cout<<indices[i]<<" ";
    return 0;
}
