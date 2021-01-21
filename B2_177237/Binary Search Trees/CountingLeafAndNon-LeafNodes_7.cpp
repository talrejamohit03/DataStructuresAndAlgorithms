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
void cntleaf(BSTPTR T,int &nl,int &l){
    if(T!=NULL){
        if(T->lchild!=NULL||T->rchild!=NULL)
            nl++;
        else
            l++;
        cntleaf(T->lchild,nl,l);
        cntleaf(T->rchild,nl,l);
    }
}
int main(){
    BSTPTR T1=NULL;
    int n,nleaf=0,leaf=0;
    cout<<"Enter element(-1 to terminate): ";
    cin>>n;
    while(n!=-1){
        ins_bst(T1,n);
        cout<<"Enter next element(-1 to terminate): ";
        cin>>n;
    }
    cntleaf(T1,nleaf,leaf);
    cout<<"Non leaf nodes = "<<nleaf<<" leaf nodes = "<<leaf<<endl;
    return 0;
}
