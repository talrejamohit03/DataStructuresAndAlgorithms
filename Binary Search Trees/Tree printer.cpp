#include <iostream>
using namespace std;

typedef
struct bstnode{
    bstnode *lchild;
    bstnode *rchild;
    int data;
    int space;
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
/*int pathlength(BSTPTR T,BSTPTR TN){
    if(T==TN)
        return 0;
    if(TN->data<T->data)
        return 1+pathlength(T->lchild,TN);
    else if(TN->data>T->data)
        return 1+pathlength(T->rchild,TN);
}*/
/*void space_val(BSTPTR T,BSTPTR TH){
    static int c=1;
    if(T!=NULL){
        space_val(T->lchild,TH);
        T->space=(c++)-pathlength(TH,T);
        cout<<T->space<<" ";
        space_val(T->rchild,TH);
    }
}*/
void bst_sort(BSTPTR T){
    static int c=0;
    if(T!=NULL){
        bst_sort(T->lchild);
        T->space=c++;
        bst_sort(T->rchild);
    }
}
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
    BSTPTR T1=NULL,tag=new(bstnode),T2;
    int n;
    cout<<"Enter element(-1 to terminate): ";
    cin>>n;
    while(n!=-1){
        ins_bst(T1,n);
        cout<<"Enter next element(-1 to terminate): ";
        cin>>n;
    }
    //space_val(T1,T1);
    bst_sort(T1);
    QPTR Q1=new(bst_queue);
    Q1->f=NULL;
    Q1->r=NULL;
    tag->data=-1;
    tag->lchild=NULL;
    tag->rchild=NULL;
    bst_enq(Q1,T1);
    bst_enq(Q1,tag);
    int prevsp=0;
    while(Q1->f!=NULL){
        T2=bst_deq(Q1);
        if(T2->data==-1){
            cout<<"\n";
            bst_enq(Q1,T2);
            prevsp=0;
            continue;
        }
        for(int i=0;i<T2->space-prevsp;i++)
            cout<<" ";
        cout<<T2->data;
        if(T2->lchild!=NULL)
            bst_enq(Q1,T2->lchild);
        if(T2->rchild!=NULL)
            bst_enq(Q1,T2->rchild);
        prevsp=T2->space;
        if(Q1->f->data==tag&&Q1->r->data==tag)
            break;
    }
    return 0;
}



