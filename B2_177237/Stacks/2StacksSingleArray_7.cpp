#include <iostream>
using namespace std;

struct stack{
    int top;
    int size;
    int elem[50];
};
void push(stack &s,int x){
    if(s.top==s.size-1)
        cout<<"stack is full";
    else
        s.elem[++s.top]=x;
}
int pop(stack &s){
    if(s.top==-1)
        cout<<"Stack is empty";
    else
        return s.elem[s.top--];
}

int main(){
    stack s1,s2;
    s1.top=-1;
    s2.top=-1;
    cout<<"Enter size of stack 1: ";
    cin>>s1.size;
    cout<<"Enter size of stack 2: ";
    cin>>s2.size;
    int n=s1.size+s2.size;
    int A[n],x;
    cout<<"Enter elements of stack 1: ";
    for(int i=0;i<s1.size;i++){
        cin>>x;
        push(s1,x);
    }
    /*for(int i=0;i<=s1.top;i++)
        cout<<s1.elem[i]<<" ";*/
    cout<<"Enter elements of stack 2: ";
    for(int i=0;i<s2.size;i++){
        cin>>x;
        push(s2,x);
    }
    /*for(int i=0;i<=s2.top;i++)
        cout<<s2.elem[i]<<" ";*/
    for(int i=0;i<s1.size;i++)
        A[i]=pop(s1);
    for(int j=n-1;j>=s1.size;j--)
        A[j]=pop(s2);
    cout<<endl;
    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";
    return 0;
}
