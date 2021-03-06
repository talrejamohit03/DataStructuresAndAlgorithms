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
struct bst_stack{
    LPTR top;
};
typedef bst_stack *SPTR;
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
    BSTPTR T1=NULL,tag=new(bstnode),T2;
    int n;
    cout<<"Enter element(-1 to terminate): ";
    cin>>n;
    while(n!=-1){
        ins_bst(T1,n);
        cout<<"Enter next element(-1 to terminate): ";
        cin>>n;
    }
    QPTR Q1=new(bst_queue);
    SPTR S1=new(bst_stack);
    Q1->f=NULL;
    Q1->r=NULL;
    S1->top=NULL;
    tag->data=-1;
    tag->lchild=NULL;
    tag->rchild=NULL;
    bst_enq(Q1,T1);
    bst_push(S1,T1);
    bst_push(S1,tag);
    bst_enq(Q1,tag);
    while(Q1->f!=NULL){
        T2=bst_deq(Q1);
        if(T2->data==-1){
            bst_enq(Q1,T2);
            bst_push(S1,T2);
            continue;
        }
        if(T2->rchild!=NULL){
            bst_enq(Q1,T2->rchild);
            bst_push(S1,T2->rchild);
        }
        if(T2->lchild!=NULL){
            bst_enq(Q1,T2->lchild);
            bst_push(S1,T2->lchild);
        }
        if(Q1->f->data==tag&&Q1->r->data==tag)
            break;
    }
    bst_pop(S1);
    while(S1->top!=NULL){
        T2=bst_pop(S1);
        if(T2->data==-1){
            cout<<"\n";
            continue;
        }
        cout<<T2->data<<" ";
    }
    return 0;
}

