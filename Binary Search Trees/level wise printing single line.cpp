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

struct bst_queue{
    LPTR f;
    LPTR r;
};
typedef bst_queue *QPTR;
void bst_enq(QPTR &Q,BSTPTR T){
    LPTR temp=new(lnode);
    temp->data=T;
    temp->next=NULL;
    if(Q->f==NULL){
        Q->f=temp;
        Q->r=temp;
    }else{
        Q->r->next=temp;
        Q->r=Q->r->next;
    }
}
BSTPTR bst_deq(QPTR Q){
    if(Q->f==NULL)
        return NULL;
    LPTR temp=Q->f;
    if(Q->r==NULL){
        Q->f=NULL;
        Q->r=NULL;
    }else{
        Q->f=Q->f->next;
    }
    return temp->data;
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
    QPTR Q1=new(bst_queue);
    Q1->f=NULL;
    Q1->r=NULL;
    bst_enq(Q1,T1);
    while(Q1->f!=NULL){
        T1=bst_deq(Q1);
        cout<<T1->data<<" ";
        if(T1->lchild!=NULL)
            bst_enq(Q1,T1->lchild);
        if(T1->rchild!=NULL)
            bst_enq(Q1,T1->rchild);
    }
    return 0;
}
