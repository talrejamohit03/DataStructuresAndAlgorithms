#include <iostream>
using namespace std;

typedef
struct btnode{
    btnode *lchild;
    char data;
    btnode *rchild;
} *BTPTR;

void btcreate(BTPTR &T,char k){
    if(k!='.'){
        T=new(btnode);
        T->lchild=NULL;
        T->rchild=NULL;
        T->data=k;
        char k1;
        cin>>k1;
        btcreate(T->lchild,k1);
        cin>>k1;
        btcreate(T->rchild,k1);
    }
}
struct lnode{
    BTPTR data;
    lnode *next;
};
typedef lnode* LPTR;
struct lstack{
    LPTR top;
};
typedef lstack *SPTR;
void lpush(SPTR &S,BTPTR x){
    LPTR temp;
    temp=new(lnode);
    temp->data=x;
    temp->next=S->top;
    S->top=temp;
}
BTPTR lpop(SPTR &S){
    if(S->top==NULL)
        cout<<"Stack is empty.";
    else{
        BTPTR t=S->top->data;
        S->top=S->top->next;
        return t;
    }
}
void LRDseq(BTPTR T){
    BTPTR T2=T,prev;
    SPTR S=new(lstack);
    S->top=NULL;
    lpush(S,T2);
    while(S->top!=NULL){
        while(T2!=prev&&T2->lchild!=NULL){
            lpush(S,T2->lchild);
            T2=T2->lchild;
        }
        T2=lpop(S);
        if(T2->rchild!=NULL&&T2!=prev){
            lpush(S,T2);
            lpush(S,T2->rchild);
            T2=T2->rchild;
            continue;
        }
        cout<<T2->data<<" ";
        prev=T2->rchild;
    }
}
int main(){
    //A M B . . D F . . . J R . . H N . . .
    BTPTR T1=NULL;
    char c;
    cin>>c;
    btcreate(T1,c);
    LRDseq(T1);
    return 0;
}
