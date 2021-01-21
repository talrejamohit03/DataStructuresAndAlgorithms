#include <iostream>
using namespace std;

typedef
struct btnode{
    btnode *lchild;
    int data;
    btnode *rchild;
} *BTPTR;
typedef
struct lnode{
    BTPTR data;
    lnode *next;
} *LPTR;

struct bt_queue{
    LPTR f;
    LPTR r;
};
typedef bt_queue *QPTR;
void bt_enq(QPTR &Q,BTPTR T){
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
BTPTR bt_deq(QPTR Q){
    if(Q->f==NULL)
        return NULL;
    LPTR temp=Q->f;
    if(Q->r==Q->f){
        Q->f=NULL;
        Q->r=NULL;
    }else{
        Q->f=Q->f->next;
    }
    return temp->data;
}
void btcreate(BTPTR &T,int k){
    if(k!=0){
        T=new(btnode);
        T->lchild=NULL;
        T->rchild=NULL;
        T->data=k;
        int k1;
        cin>>k1;
        btcreate(T->lchild,k1);
        cin>>k1;
        btcreate(T->rchild,k1);
    }
}
void leftview(BTPTR T){
    BTPTR tag=new(btnode),T1=NULL;
    QPTR Q1=new(bt_queue);
    Q1->f=NULL;
    Q1->r=NULL;
    tag->data=-1;
    tag->lchild=NULL;
    tag->rchild=NULL;
    bt_enq(Q1,T);
    bt_enq(Q1,tag);
    int flag=1;
    while(Q1->f!=NULL){
        T1=bt_deq(Q1);
        if(T1->data==-1){
            flag=1;
            if(Q1->f==NULL)
                break;
            bt_enq(Q1,T1);
            continue;
        }
        if(flag==1){
            cout<<T1->data<<"\n";
            flag=0;
        }
        if(T1->lchild!=NULL)
            bt_enq(Q1,T1->lchild);
        if(T1->rchild!=NULL)
            bt_enq(Q1,T1->rchild);
    }
}
void leftv_recursive(BTPTR T,int currlev){
    static int maxl=0;
    if(T!=NULL){
        if(currlev>=maxl){
            cout<<T->data<<"\n";
            maxl++;
        }
        leftv_recursive(T->lchild,currlev+1);
        leftv_recursive(T->rchild,currlev+1);
    }
}
int main(){
    //1 2 4 0 0 5 6 7 13 0 0 14 0 0 15 0 0 0 3 8 0 0 9 10 0 0 11 0 12 0 0
    BTPTR T1=NULL;
    int c;
    cin>>c;
    btcreate(T1,c);
    //leftview(T1);
    leftv_recursive(T1,0);
    return 0;
}
