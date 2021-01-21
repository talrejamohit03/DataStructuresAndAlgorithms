#include <iostream>
using namespace std;

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
void display(QPTR Q){
    LPTR T1=Q->f;
    while(T1!=NULL){
        cout<<T1->data<<" ";
        T1=T1->next;
    }
    cout<<"\n";
}
int main(){
    LPTR L1=NULL,T;
    QPTR Q1=new(lqueue);
    Q1->f=NULL;
    Q1->r=NULL;
    int n;
    cout<<"Enter elements to enqueue: (-1 to terminate)";
    cin>>n;
    while(n!=-1){
        l_enq(Q1,n);
        display(Q1);
        cin>>n;
    }
    while(Q1->f!=NULL){
        cout<<l_deq(Q1)<<" dequeued\n";
        display(Q1);
    }
    return 0;
}
