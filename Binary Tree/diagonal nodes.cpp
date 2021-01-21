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

void btcreate(BTPTR &T,int k,int i,int &mx){
    if(k!=0){
        T=new(btnode);
        T->lchild=NULL;
        T->rchild=NULL;
        T->index=i;
        if(i>mx)
            mx=i;
        T->data=k;
        int k1;
        cin>>k1;
        btcreate(T->lchild,k1,i,mx);
        cin>>k1;
        btcreate(T->rchild,k1,i+1,mx);
    }
}

void diagonallink(BTPTR T,LPTR elem[]){
    if(T!=NULL){
        LPTR curr=new(lnode);
        curr->data=T;
        curr->next=NULL;
        if(elem[T->index]==NULL)
            elem[T->index]=curr;
        else{
            LPTR temp=elem[T->index];
            while(temp->next!=NULL)
                temp=temp->next;
            temp->next=curr;
        }
        diagonallink(T->rchild,elem);
        diagonallink(T->lchild,elem);
    }
}
int main(){
    //1 2 4 0 0 5 6 7 13 0 0 14 0 0 15 0 0 0 3 8 0 0 9 10 0 0 11 0 12 0 0
    BTPTR T1=NULL;
    int k1,mx=0;
    cin>>k1;
    btcreate(T1,k1,0,mx);
    LPTR elements[mx+1];
    for(int i=0;i<mx+1;i++)
        elements[i]=NULL;
    diagonallink(T1,elements);
    for(int i=0;i<mx+1;i++){
        LPTR temp=elements[i];
        while(temp!=NULL){
            cout<<temp->data->data<<" ";
            temp=temp->next;
        }
        cout<<"\n";
    }
    return 0;
}
