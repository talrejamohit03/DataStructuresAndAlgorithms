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
int max_bst(BSTPTR T){
    if(T->rchild==NULL)
        return T->data;
    max_bst(T->rchild);
}
int min_bst(BSTPTR T){
    if(T->lchild==NULL)
        return T->data;
    min_bst(T->lchild);
}
void sort_bst(BSTPTR T){//LDR traversal gives sorted order
    if(T!=NULL){
        sort_bst(T->lchild);
        cout<<T->data<<" ";
        sort_bst(T->rchild);
    }
}
int height(BSTPTR T){
    if(T==NULL)
        return -1;
    else
        return (max(height(T->lchild),height(T->rchild))+1);
}
void del_bstnode(BSTPTR &T,int k){
    if(T!=NULL){
        if(k<T->data)
            del_bstnode(T->lchild,k);
        else if(k>T->data)
            del_bstnode(T->rchild,k);
        else{
            if(T->lchild==NULL&&T->rchild==NULL)
                T=NULL;
            else{
                int temp;
                if(T->rchild==NULL)
                    temp=max_bst(T->lchild);
                else if(T->lchild==NULL)
                    temp=min_bst(T->rchild);
                else{
                    int ch;
                    cout<<"Do you want it to be replaced by \n1. min of rchild or 2.max of lchild: ";
                    cin>>ch;
                    if(ch==1)
                        temp=min_bst(T->rchild);
                    else
                        temp=max_bst(T->lchild);
                }
                del_bstnode(T,temp);
                T->data=temp;
            }
        }
    }
}
int main(){
    BSTPTR T1=NULL;
    int n;
    cout<<"Enter element(-1 to terminate): ";
    cin>>n;
    while(n!=-1){
        ins_bst(T1,n);
        cout<<"Enter next element(-1 to terminate): ";
        cin>>n;
    }
    cout<<max_bst(T1)<<endl;
    sort_bst(T1);
    while(true){
        cout<<"Enter element to be deleted:(0 to break) ";
        cin>>n;
        del_bstnode(T1,n);
        sort_bst(T1);
        if(n==0)
            break;
    }
    //cout<<height(T1);

    return 0;
}
