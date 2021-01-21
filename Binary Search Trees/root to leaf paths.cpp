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
    int data;
    lnode *next;
} *LPTR;
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
void rlpath(BSTPTR T){
    static LPTR L=NULL,T2;
    if(T!=NULL){
        LPTR temp=new(lnode),LR;
        temp->data=T->data;
        temp->next=NULL;
        if(T->rchild!=NULL)
                LR=temp;
        if(L==NULL){
            L=temp;
            T2=L;
        }else{
            T2->next=temp;
            T2=T2->next;
        }
        if(T->lchild==NULL&&T->rchild==NULL){
            LPTR tmp=L;
            while(tmp!=NULL){
                cout<<tmp->data<<" ";
                tmp=tmp->next;
            }
            cout<<"\n";
        }else{
            rlpath(T->lchild);
            T2=LR;
            rlpath(T->rchild);
        }
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
    rlpath(T1);
    return 0;
}
