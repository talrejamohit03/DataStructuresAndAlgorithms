#include <iostream>
#include <string>
//#include <cstring>
using namespace std;

struct stack{
    int top;
    string elements[50];
    int size;
};
void push(stack &s,string x){
    if(s.size-1==s.top)
        cout<<"Stack is full";
    else
        s.elements[++s.top]=x;
}
string pop(stack &s){
    if(s.top==-1)
        cout<<"Stack is empty";
    else
        return s.elements[s.top--];
}
void pretopost(stack &s,string A,int i){
    if(i==-1)
        cout<<pop(s);
    else{
        if((A[i]>='a'&&A[i]<='z')||(A[i]>='A'&&A[i]<='Z')){
            string temp="";
            temp+=A[i];
            push(s,temp);
        }
        else{
            string v1,v2,e;
            v1=pop(s);
            v2=pop(s);
            e=v1+v2+A[i];
            push(s,e);
        }
        /*for(int j=0;j<=s.top;j++)
            cout<<s.elements[j]<<" ";
        cout<<endl;*/
        pretopost(s,A,--i);
    }
}
int main(){
    stack s1;
    s1.top=-1;
    s1.size=50;
    string B="*-A/BC-/AKL";
    pretopost(s1,B,B.length()-1);
    return 0;
}
