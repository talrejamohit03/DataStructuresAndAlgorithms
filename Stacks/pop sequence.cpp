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
    //push 1st element onto the stack
    //for every iteration, check if popped element is equal to current element
    //if yes, then continue for the rest of the elements
    //if no, then keep pushing elements onto the stack till current element is found
    //if in this process, all elements are pushed onto the stack, that is, index crosses the size of the push sequence, return false
    stack s1;
    s1.top=-1;
    int n;
    cout<<"Enter size of push/pop sequence: ";
    cin>>n;
    int A[n],B[n];
    cout<<"Enter push sequence: ";
    for(int i=0;i<n;i++)
        cin>>A[i];
    cout<<"Enter pop sequence: ";
    for(int i=0;i<n;i++)
        cin>>B[i];
    int i=0,j=1;
    push(s1,A[0]);
    while(i<n){
        while(s1.elem[s1.top]!=B[i])
            push(s1,A[j++]);
        //if(i<n-1&&j==n)break;
        int flag=0;
        for(int m=0;m<s1.top;m++){
            if(B[i]==s1.elem[m]){
                flag=1;
                break;
            }
        }
        if(flag==1){
            cout<<"Sequence not possible";
            break;
        }else{
            pop(s1);
            i++;
        }
    }
    if(i==n)
        cout<<"Sequence is possible.";
    return 0;
}
