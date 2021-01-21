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
void pop(stack &s){
    if(s.top==-1)
        cout<<"Stack is empty";
    else
        s.top--;
}
/*bool seqpupo(stack &s,int A[],int B[],int i,int j){
    if(s.elem[s.top]==B[i]){
        pop(s);
        seqpupo(s,A,B,i++,j);
    }
    while(B[i]!=A[j]){
        push(s,A[j++]);i++;
    }
    if(i==)
        seqpupo(s,A,B,i++,j);
}*/
int main(){
    stack s1;
    s1.top=-1;
    int A[6]={1,2,3,4,5,6},B[6]={3,5,4,2,1,6},i=0,j=0;
    while(i<6){
        if(s1.top=-1 && s1.elem[s1.top]==B[i]){
            pop(s1);i++;continue;
        }
        while(B[i]!=A[j]&&j<6){
            push(s1,A[j]);
            j++;
        }
        j++;
        if(i==5){
            cout<<"Sequence is possible with a S X sequence.";
            break;
        }
        if(j==6||s1.elem[s1.top]!=B[i]){
            cout<<"Sequence not possible.";
            break;
        }
        i++;
    }
    return 0;
}
