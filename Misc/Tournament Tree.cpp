#include <iostream>
#include <cmath>
using namespace std;

typedef
struct btnode{
    btnode *lchild;
    int data;
    btnode *rchild;
    int space;//for printing tree as it is
} *BTPTR;

typedef
struct lnode{
    BTPTR data;
    lnode *next;
} *LPTR;

struct bst_queue{
    LPTR f;
    LPTR r;
};
typedef bst_queue *QPTR;

//assigning in order serial numbers
void bst_sort(BTPTR T){
    static int c=0;
    if(T!=NULL){
        bst_sort(T->lchild);
        T->space=c++;
        bst_sort(T->rchild);
    }
}
void bst_enq(QPTR &Q,BTPTR T){
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
BTPTR bst_deq(QPTR Q){
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
void create(BTPTR &T, int A[],int ll, int cl){
    static int i=0;
    T=new(btnode);
    T->lchild=NULL;
    T->rchild=NULL;
    if(cl<ll){
        create(T->lchild,A,ll,cl+1);
        create(T->rchild,A,ll,cl+1);
        T->data=max(T->lchild->data,T->rchild->data);
    }else
        T->data=A[i++];
}
void treeprint(BTPTR T1){
    BTPTR tag=new(btnode),T2;
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
            cout<<"  ";
        cout<<T2->data;
        if(T2->lchild!=NULL)
            bst_enq(Q1,T2->lchild);
        if(T2->rchild!=NULL)
            bst_enq(Q1,T2->rchild);
        prevsp=T2->space;
        if(Q1->f->data==tag&&Q1->r->data==tag)
            break;
    }
}
int main(){
    //8
    //6 3 9 2 7 5 2 8
    int *arr,n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    arr=new int[n];
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    double leaflevel=(log(n)/log(2));
    BTPTR T1=NULL;
    create(T1,arr,leaflevel,0);
    treeprint(T1);
    return 0;
}
