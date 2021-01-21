#include <iostream>

using namespace std;

void push1(int &elements[],int x,int top){
    elements[top]=x;
}
int pop1(int &elements[],int top){
    return elements[top];
}
void push2(int &elements[],int x,int top){
        elements[top]=x;
}
int pop2(int &elements[],int top){
    return elements[top];
}

int main(){
    int A[75],top1=0,top2=74;
    push1(A,10,top1++);
    push2(A,100,top2--);
    return 0;

}
