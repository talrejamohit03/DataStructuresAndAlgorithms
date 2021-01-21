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
void dead_end(BSTPTR T,int rmin,int rmax){
    if(T==NULL)
        return;
    if(rmin==rmax){
        cout<<T->data<<" ";
        return;
    }
    dead_end(T->lchild,rmin,T->data-1);
    dead_end(T->rchild,T->data+1,rmax);
}
void inpT(BSTPTR &T){
    int n;
    cout<<"Enter elements(-1 to terminate): ";
    cin>>n;
    while(n!=-1){
        ins_bst(T,n);
        cin>>n;
    }
}
int main(){
    //25 18 45 12 20 32 55 19 27 40 26 31 -1
    //output: 19 26
    BSTPTR T1=NULL;
    inpT(T1);
    dead_end(T1,0,10000);
    return 0;
}
