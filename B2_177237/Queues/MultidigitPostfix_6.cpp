#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

struct stack{
    int top;
    int elements[50];
    int size;
};
void push(stack &s,int x){
    if(s.size-1==s.top)
        cout<<"Stack is full";
    else
        s.elements[++s.top]=x;
}
int pop(stack &s){
    if(s.top==-1)
        cout<<"Stack is empty";
    else
        return s.elements[s.top--];
}
int eval(char op,int op2,int op1){
    switch(op){
        case('+'):
            return op2+op1;
        case('-'):
            return op2-op1;
        case('*'):
            return op2*op1;
        case('/'):
            return op2/op1;
    }
}
int main(){
    char str[26]="16 15 2 * 21 7 / - 70 - +";
    int i=0;
    stack s1;
    s1.top=-1;s1.size=50;
    while(str[i]!='\0'){
        int ni=0;
        char n[5]="";
        for(int j=0;j<=s1.top;j++)
            cout<<s1.elements[j]<<" ";
        cout<<endl;
        if(str[i]==' ')i++;
        if(str[i]>='0'&&str[i]<='9'){
            int l=i;
            while(str[i]!=' ')
                i++;
            for(l;l<i;l++)
                n[ni++]=str[l];
            int nd=atoi(n);
            push(s1,nd);
            //cout<<"*******"<<nd<<endl;
        }else
            push(s1,eval(str[i++],pop(s1),pop(s1)));

    }
    cout<<pop(s1);
    return 0;
}
