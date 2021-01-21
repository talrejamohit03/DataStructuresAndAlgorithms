#include <iostream>
using namespace std;

typedef
struct bstnode{
    bstnode *lchild;
    bstnode *rchild;
    int data;
} *BSTPTR;
typedef
struct lnode{
    BSTPTR data;
    lnode *next;
} *LPTR;
struct bst_stack{
    LPTR top;
};
typedef bst_stack *SPTR;
void bst_push(SPTR &S,BSTPTR T){
    LPTR temp=new(lnode);
    temp->data=T;
    temp->next=S->top;
    S->top=temp;
}
BSTPTR bst_pop(SPTR &S){
    if(S->top==NULL)
        cout<<"Stack is empty.";
    else{
        LPTR temp=S->top;
        S->top=S->top->next;
        return temp->data;
    }
}
void ins_bst(BSTPTR &T,int k){
    if(T==NULL){
        T=new(bstnode);
        T->data=k;
        T->lchild=NULL;
        T->rchild=NULL;
    }else{
        if(k>T->data)
            ins_bst(T->rchild,k);
        else if(k<T->data)
            ins_bst(T->lchild,k);
        else
            cout<<"Duplicate element";
    }
}
int main(){
    BSTPTR T1=NULL;
    int n;
    cout<<"Enter element(-1 to terminate): ";
    cin>>n;
    while(n!=-1){
        ins_bst(T1,n);
        cout<<"Enter next element(-1 to terminate): ";
        cin>>n;
    }
    SPTR S1=new(bst_stack),S2=new(bst_stack);
    S1->top=NULL;
    S2->top=NULL;
    bst_push(S1,T1);
    int tag=0;
    while(S1->top!=NULL||S2->top!=NULL){
        if(tag==0){
            T1=bst_pop(S1);
            cout<<T1->data<<" ";
            if(T1->lchild!=NULL)
                bst_push(S2,T1->lchild);
            if(T1->rchild!=NULL)
                bst_push(S2,T1->rchild);
            if(S1->top==NULL){
                tag=1;
                cout<<"\n";
            }
        }
        else{
            T1=bst_pop(S2);
            cout<<T1->data<<" ";
            if(T1->rchild!=NULL)
                bst_push(S1,T1->rchild);
            if(T1->lchild!=NULL)
                bst_push(S1,T1->lchild);
            if(S2->top==NULL){
                tag=0;
                cout<<"\n";
            }
        }
    }
    return 0;
}


