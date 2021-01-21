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
typedef
struct bst_stack{
    LPTR top;
}*SPTR;
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
void inpT(BSTPTR &T){
    int n;
    cout<<"Enter element(-1 to terminate): ";
    cin>>n;
    while(n!=-1){
        ins_bst(T,n);
        cout<<"Enter next element(-1 to terminate): ";
        cin>>n;
    }
}
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
int main(){
    BSTPTR T1=NULL,T2=NULL;
    cout<<"Enter BST 1: ";
    inpT(T1);
    cout<<"Enter BST 2: ";
    inpT(T2);
    SPTR S1=new(bst_stack),S2=new(bst_stack);
    S1->top=NULL;
    S2->top=NULL;
    bst_push(S1,T1);
    bst_push(S2,T2);
    while(S1->top!=NULL&&S2->top!=NULL){
        while(T1!=NULL&&T1->lchild!=NULL){
            bst_push(S1,T1->lchild);
            T1=T1->lchild;
        }
        while(T2!=NULL&&T2->lchild!=NULL){
            bst_push(S2,T2->lchild);
            T2=T2->lchild;
        }
        if(S1->top->data->data<S2->top->data->data){
            T1=bst_pop(S1);
            if(T1->rchild!=NULL){
                bst_push(S1,T1->rchild);
                T1=T1->rchild;
            }else{
                T1=NULL;
            }
        }
        else if(S1->top->data->data>S2->top->data->data){
            T2=bst_pop(S2);
            if(T2->rchild!=NULL){
                bst_push(S2,T2->rchild);
                T2=T2->rchild;
            }else{
                T2=NULL;
            }
        }else{
            T1=bst_pop(S1);
            T2=bst_pop(S2);
            cout<<T1->data<<" ";
            if(T1->rchild!=NULL){
                bst_push(S1,T1->rchild);
                T1=T1->rchild;
            }else
                T1=NULL;
            if(T2->rchild!=NULL){
                bst_push(S2,T2->rchild);
                T2=T2->rchild;
            }else
                T2=NULL;
        }
    }
    return 0;
}
