#include <iostream>
#include <cmath>
#include <string>
using namespace std;
struct nrad{
    int n;
    char c;
};
string rev(string x){
    string y="";
    for(int i=x.length()-1;i>=0;i--)
        y+=x[i];
    return y;
}
string ntobpox(int n,int bs){
    string x="";
    string strnum[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    int dig,j=0;
    while(n>0){
        dig=n%bs;
        n=n/bs;
        x+=(dig<10)?dig+'0':dig-10+'A';
    }
    if(bs==10){
        string z="";
        for(int i=x.length()-1;i>=0;i--)
            z=z+strnum[x[i]-'0']+' ';
        return z;
    }
    return rev(x);
}
int bsret(char x){
    char A[5]="bpox";
    for(int i=0;i<4;i++){
        if(x=='p')
            return 10;
        else if(x==A[i])
            return pow(2,i+1);
    }
}
int main(){
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    nrad elem[n];
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++){
        cout<<"Element "<<i+1<<": ";
        cin>>elem[i].n>>elem[i].c;
        cout<<ntobpox(elem[i].n,bsret(elem[i].c))<<"\n";
    }
    return 0;
}
