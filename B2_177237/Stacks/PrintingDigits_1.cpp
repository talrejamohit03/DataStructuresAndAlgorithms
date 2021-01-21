#include <iostream>

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
int main(){
    int n=5783;
    stack s1;
    s1.top=-1;s1.size=50;
    while(n>0){
        push(s1,n%10);
        n=n/10;
    }
    while(s1.top>=0)
        cout<<pop(s1)<<" ";
}
