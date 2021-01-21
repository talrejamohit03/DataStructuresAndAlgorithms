#include <iostream>

using namespace std;

struct stack{
    int top;
    char elements[50];
    int size;
};
void push(stack &s,char x){
    if(s.size-1==s.top)
        cout<<"Stack is full";
    else
        s.elements[++s.top]=x;
}
char pop(stack &s){
    if(s.top==-1)
        cout<<"Stack is empty";
    else
        return s.elements[s.top--];
}
int precedence(char x){
    if(x=='*'||x=='/')
        return 2;
    else if(x=='+'||x=='-')
        return 1;
    return 0;
}
int main(){
    stack s1;
    s1.top=-1;s1.size=50;
    char A[14]="a+(b/c)+d*e-f";
    int i=0;
    while(A[i]!='\0'){
        if(A[i]<='z'&&A[i]>='a')
            cout<<A[i++];
        else{
            if(A[i]==')'){
                while(s1.elements[s1.top]!='(')
                    cout<<pop(s1);
                pop(s1);
                i++;
            }else if(A[i]=='(')
                push(s1,A[i++]);
            else{
                while(s1.top!=-1 && precedence(A[i])<=precedence(s1.elements[s1.top]))
                    cout<<pop(s1);
                push(s1,A[i++]);
            }
        }
    }
    while(s1.top!=-1)
        cout<<pop(s1);
    return 0;
}

