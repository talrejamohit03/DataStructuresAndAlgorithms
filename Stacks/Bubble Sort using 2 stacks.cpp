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
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)
        cin>>A[i];
    stack s1,s2;
    s1.top=-1;s1.size=50;
    s2.top=-1;s2.size=50;
    push(s1,A[0]);
    //pop all elements onto the 2nd stack which are lesser than the current element,
    //push the current element
    //push back all elements from the second stack back into the first stack
    for(int i=1;i<n;i++){
        if(s1.elem[s1.top]>A[i])
            push(s1,A[i]);
        else{
            while(s1.elem[s1.top]<A[i]&&s1.top!=-1)
                push(s2,pop(s1));
            push(s1,A[i]);
            while(s2.top!=-1)
                push(s1,pop(s2));
        }
    }
    for(int j=s1.top;j>=0;j--)
        cout<<s1.elem[j]<<" ";
    return 0;
}
