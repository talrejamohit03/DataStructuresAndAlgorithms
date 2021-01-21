#include <iostream>
using namespace std;

typedef
struct btnode{
    btnode *lchild;
    int data;
    btnode *rchild;
    int index;
} *BTPTR;

typedef
struct lnode{
    BTPTR data;
    lnode *next;
}*LPTR;
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
void btcreate(BTPTR &T,int k,int i,int &maxin,int &minin){
    if(k!=0){
        T=new(btnode);
        T->lchild=NULL;
        T->rchild=NULL;
        T->index=i;
        T->data=k;
        if(i>maxin)
            maxin=i;
        if(i<minin)
            minin=i;
        int k1;
        cin>>k1;
        btcreate(T->lchild,k1,i-1,maxin,minin);
        cin>>k1;
        btcreate(T->rchild,k1,i+1,maxin,minin);
    }
}
void verticallink(BTPTR T,LPTR elem[],int mi){
//    if(T!=NULL){
//        verticallink(T->lchild,elem,mi);
//        verticallink(T->rchild,elem,mi);
//        LPTR curr=new(lnode);
//        curr->data=T;
//        curr->next=NULL;
//        if(elem[T->index-mi]==NULL)
//            elem[T->index-mi]=curr;
//        else{
//            LPTR temp=elem[T->index-mi];
//            while(temp->next!=NULL)
//                temp=temp->next;
//            temp->next=curr;
//        }
//    }
    BTPTR tag=new(btnode),T1=NULL;
    QPTR Q1=new(bt_queue);
    Q1->f=NULL;
    Q1->r=NULL;
    tag->data=-1;
    tag->lchild=NULL;
    tag->rchild=NULL;
    bt_enq(Q1,T);
    bt_enq(Q1,tag);
    while(Q1->f!=NULL){
        T1=bt_deq(Q1);
        if(T1->data==-1){
            if(Q1->f==NULL)
                break;
            bt_enq(Q1,T1);
            continue;
        }
        LPTR curr=new(lnode);
        curr->data=T1;
        curr->next=NULL;
        if(elem[T1->index-mi]==NULL)
            elem[T1->index-mi]=curr;
        else{
            LPTR temp=elem[T1->index-mi];
            while(temp->next!=NULL)
                temp=temp->next;
            temp->next=curr;
        }
        if(T1->lchild!=NULL)
            bt_enq(Q1,T1->lchild);
        if(T1->rchild!=NULL)
            bt_enq(Q1,T1->rchild);
    }
}
int main(){
    //1 2 4 0 0 5 6 7 13 0 0 14 0 0 15 0 0 0 3 8 0 0 9 10 0 0 11 0 12 0 0
    BTPTR T1=NULL;
    int c,mi=0,mxi=0;
    cin>>c;
    btcreate(T1,c,0,mxi,mi);
    LPTR indices[mxi-mi+1];
    for(int i=0;i<mxi-mi+1;i++)
        indices[i]=NULL;
    verticallink(T1,indices,mi);
    for(int i=0;i<mxi-mi+1;i++){
        LPTR temp=indices[i];
        while(temp!=NULL){
            cout<<temp->data->data<<" ";
            temp=temp->next;
        }
        cout<<"\n";
    }
    return 0;
}
