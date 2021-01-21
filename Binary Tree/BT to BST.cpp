#include <iostream>
using namespace std;

typedef
struct btnode{
    btnode *lchild;
    int data;
    btnode *rchild;
    int space;
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
void bst_sort(BTPTR T,int &c){
    if(T!=NULL){
        bst_sort(T->lchild,c);
        T->space=c++;
        bst_sort(T->rchild,c);
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
void ldr(BTPTR T,int A[]){
    static int i=0;
    if(T!=NULL){
        ldr(T->lchild,A);
        A[i++]=T->data;
        ldr(T->rchild,A);
    }
}
void btcreate(BTPTR &T,int k,int &s){
    if(k!=0){
        T=new(btnode);
        T->lchild=NULL;
        T->rchild=NULL;
        T->data=k;
        s++;
        int k1;
        cin>>k1;
        btcreate(T->lchild,k1,s);
        cin>>k1;
        btcreate(T->rchild,k1,s);
    }
}
void convertToBst(BTPTR T, int A[], int &n){
    if(T!=NULL){
        convertToBst(T->rchild,A,n);
        T->data=A[--n];
        convertToBst(T->lchild,A,n);
    }
}
void tree_printer(BTPTR T1){
    BTPTR tag=new(btnode),T2;
    int nn=0;
    bst_sort(T1,nn);
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
            cout<<"\n\n";
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
}
int main(){
    //30 25 9 0 2 0 0 45 0 0 18 0 36 0 0
    int k,si=0;
    cin>>k;
    BTPTR T1=NULL;
    btcreate(T1,k,si);
    tree_printer(T1);
    cout<<endl;
    int arr[si];
    ldr(T1,arr);
    //sorting the array(insertion sort)
    for(int i=1;i<si;i++){
        int j=i-1,v=arr[i];
        while (arr[j]>v&&j>=0){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=v;
    }
    convertToBst(T1,arr,si);
    tree_printer(T1);
    return 0;
}
