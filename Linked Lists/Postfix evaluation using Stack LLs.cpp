#include <iostream>
#include <cstdlib>
using namespace std;

struct lnode{
    int data;
    lnode *next;
};
typedef lnode* LPTR;
struct lstack{
    LPTR top;
};
typedef lstack *SPTR;
void lpush(SPTR &S,int x){
    LPTR temp;
    temp=new(lnode);
    temp->data=x;
    temp->next=S->top;
    S->top=temp;
}
int lpop(SPTR &S){
    if(S->top==NULL)
        cout<<"Stack is empty.";
    else{
        int t=S->top->data;
        S->top=S->top->next;
        return t;
    }
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
    SPTR S1;
    S1=new(lstack);
    S1->top=NULL;
    int n,i=0;
    cout<<"Enter size of the expression: ";
    cin>>n;
    char A[n+1];
    cin.ignore();
    cout<<"Enter the expression: ";
    cin.getline(A,n+1);
    while(A[i]!='\0'){
        int ni=0;
        char n[6]="";
        if(A[i]==' ')i++;
        if(A[i]>='0'&&A[i]<='9'){
            int l=i;
            while(A[i]!=' ')
                i++;
            for(l;l<i;l++)
                n[ni++]=A[l];
            int nd=atoi(n);
            lpush(S1,nd);
        }else
            lpush(S1,eval(A[i++],lpop(S1),lpop(S1)));
    }
    cout<<lpop(S1);
    return 0;
}
