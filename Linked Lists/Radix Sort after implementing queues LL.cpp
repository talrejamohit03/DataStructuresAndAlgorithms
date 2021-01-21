#include <iostream>
using namespace std;
struct rnode{
    rnode *bktnext;
    struct lqueue *blink;
};
typedef rnode *RPTR;
struct lnode{
    int data;
    lnode *next;
};
typedef lnode* LPTR;
struct lqueue{
    LPTR f;
    LPTR r;
};
typedef lqueue *QPTR;
void l_enq(QPTR Q,int x){
    LPTR temp;
    temp=new(lnode);
    temp->data=x;
    temp->next=NULL;
    if(Q->r==NULL){
        Q->f=temp;
        Q->r=temp;
    }else{
        Q->r->next=temp;
        Q->r=Q->r->next;
    }
}
int l_deq(QPTR Q){
    if(Q->f==NULL)
        cout<<"Queue is empty.";
    else{
        int t=Q->f->data;
        if(Q->f==Q->r){
            Q->f=NULL;
            Q->r=NULL;
        }else
            Q->f=Q->f->next;
        return t;
    }
}
void inpLL(LPTR &L){
    LPTR T;
    int n;
    cout<<"New Linked List\n";
    cout<<"Enter element (-1 to terminate): ";
    cin>>n;
    while(n!=-1){
       LPTR temp;
       temp=new(lnode);
       temp->data=n;
       temp->next=NULL;
       if(L==NULL){
           L=temp;
           T=L;
       }else{
           T->next=temp;
            T=T->next;
       }
       cout<<"Enter next element (-1 to terminate): ";
       cin>>n;
    }
}
int main(){
    LPTR L1=NULL,T;
    QPTR Q1,TR1;
    RPTR R=NULL,TR=R;
    inpLL(L1);
    T=L1;
    int it=0;
    while(T!=NULL){
        int temp=T->data,itcurr=0;
        while(temp>0){
            temp=temp/10;
            itcurr++;
        }
        if(itcurr>it)
            it=itcurr;
        T=T->next;
    }
    for(int n=0;n<10;n++){
        RPTR tempr=new(rnode);
        tempr->bktnext=NULL;
        tempr->blink=NULL;
        if(R==NULL){
            R=tempr;
            TR=R;
        }else{
            TR->bktnext=tempr;
            TR=TR->bktnext;
        }
    }
    TR=R;
    for(int i=0;i<it;i++){
        T=L1;
        //TR1 is pointer for blink type lnode, TR is pointer for bktnext type rnode
        while(T!=NULL){
            int ind=temp->data;
            for(int j=0;j<i;j++)
                ind=ind/10;
            ind=ind%10;
            TR=R;
            for(int j=0;j<ind;j++)
                TR=TR->bktnext;
            TR1=TR->blink;
            l_enq(TR1,T->data);
            T=T->next;
        }
        T=L1;
        TR=R;
        for(int i=0;i<10;i++){
            TR1=TR->blink;
            while(TR1->f!=NULL){
                T->data=l_deq(TR1);
                T=T->next;
            }
            TR=TR->bktnext;
        }
    }
    while(L1!=NULL){
        cout<<L1->data<<" ";
        L1=L1->next;
    }
    return 0;
}
