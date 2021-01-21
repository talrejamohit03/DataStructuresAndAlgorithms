#include <iostream>
using namespace std;

typedef
struct avlnode{
    avlnode *lchild;
    avlnode *rchild;
    int data;
    int space;
} *AVLPTR;
typedef
struct lnode{
    AVLPTR data;
    lnode *next;
} *LPTR;

struct bst_queue{
    LPTR f;
    LPTR r;
};
typedef bst_queue *QPTR;

void bst_sort(AVLPTR T){
    static int c=0;
    if(T!=NULL){
        bst_sort(T->lchild);
        T->space=c++;
        bst_sort(T->rchild);
    }
}
void bst_enq(QPTR &Q,AVLPTR T){
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
AVLPTR bst_deq(QPTR Q){
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

int height(AVLPTR T){
    if(T==NULL)
        return -1;
    else
        return (max(height(T->lchild),height(T->rchild))+1);
}
void rotateleft(AVLPTR &T){
    AVLPTR temp=T->rchild;
    T->rchild=temp->lchild;
    temp->lchild=T;
    T=temp;
}
void rotateright(AVLPTR &T){
    AVLPTR temp=T->lchild;
    T->lchild=temp->rchild;
    temp->rchild=T;
    T=temp;
}
AVLPTR ins_avl(AVLPTR &T,int k){
    AVLPTR T1=NULL,T2=NULL;
    if(T==NULL){
        T=new(avlnode);
        T->data=k;
        T->lchild=NULL;
        T->rchild=NULL;
    }else{
        if(k>T->data)
            T1=ins_avl(T->rchild,k);
        else if(k<T->data)
            T1=ins_avl(T->lchild,k);
        else
            cout<<"Duplicate element";
    }
    int d=height(T->rchild)-height(T->lchild);
    if(d>1){
        if(k>T->data&&k<T1->data){
            rotateright(T->rchild);
            rotateleft(T);
        }
        else
            rotateleft(T);
    }
    else if(d<-1){
        if(k>T1->data&&k<T->data){
            rotateleft(T->lchild);
            rotateright(T);
        }
        else
            rotateright(T);
    }
    return T;
}
void treeprint(AVLPTR T1){
    AVLPTR tag=new(avlnode),T2;
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
    AVLPTR T1=NULL;
    //int A[7]={7,6,5,4,3,2,1};
    int A[9]={3,5,1,9,2,8,6,7,4};
    for(int i=0;i<9;i++)
        ins_avl(T1,A[i]);
    treeprint(T1);
    return 0;
}
