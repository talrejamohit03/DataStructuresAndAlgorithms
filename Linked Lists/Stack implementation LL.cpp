#include <iostream>

using namespace std;

struct snode{
    int data;
    snode *next;
};
typedef snode* SPTR;
void push(SPTR &S,int x){
    SPTR temp;
    temp=new(snode);
    temp->data=x;
    temp->next=S;
    S=temp;
}
void pop(SPTR &S){
    if(S==NULL)
        cout<<"Stack is empty.";
    else{
        cout<<S->data<<" is popped.";
        S=S->next;
    }
}
int main(){
    SPTR S1;
    S1=NULL;
    push(S1,2);
    push(S1,4);
    push(S1,6);
    pop(S1);
    pop(S1);
    pop(S1);
    return 0;
}
