#include <iostream>
using namespace std;
typedef
struct bstnode{
    bstnode *lchild;
    bstnode *rchild;
    int data;
} *BSTPTR;
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
void range_node(BSTPTR T,int k){
    static int ul=0,ll=0;
    if(k<T->data){
        ul=T->data;
        range_node(T->lchild,k);
    }
    else if(k>T->data){
        ll=T->data;
        range_node(T->rchild,k);
    }else{
        if(T->lchild!=NULL)
            ll=T->lchild->data;
        if(T->rchild!=NULL)
            ul=T->rchild->data;
        cout<<"Upper Limit: "<<ul<<" Lower limit: "<<ll<<endl;
    }
}
void inpT(BSTPTR &T){
    int n;
    cout<<"Enter elements(-1 to terminate): ";
    cin>>n;
    ins_bst(T,n);
}
int main(){
    BSTPTR T1=NULL;
    inpT(T1);
    int n;
    while(true){
        cout<<"Enter node: ";
        cin>>n;
        range_node(T1,n);
        ll=0,ul=0;
        if (n==-1)
            break;
    }
}
