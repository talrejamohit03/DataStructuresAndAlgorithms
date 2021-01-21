#include <iostream>
using namespace std;

struct dnode{
    int data;
    dnode *right;
    dnode *left;
};
typedef dnode* DPTR;

void inpD(DPTR &D){
    DPTR T;
    int n;
    cout<<"Enter data(-1 to terminate): ";
    cin>>n;
    while(n!=-1){
        DPTR temp;
        temp=new(dnode);
        temp->data=n;
        temp->left=NULL;
        temp->right=NULL;
        if(D==NULL){
            D=temp;
            T=D;
        }
        else{
            T->right=temp;
            temp->left=T;
            T=T->right;
        }
        cout<<"Enter data(-1 to terminate): ";
        cin>>n;
    }
}
int main(){
    DPTR L=NULL,T,T2,TS;
    inpD(L);
    T=L;
    while(T->data>T->right->data)
        T=T->right;
    T2=T->right;
    L=T;
    T=T->left;
    TS=L;
    while(T!=NULL&&T2!=NULL){
        DPTR nex=T->left;
        if(T2->data<T->data){
            TS->right=T2;
            T2->left=TS;
            TS=TS->right;
            T2=T2->right;
            continue;
        }
        TS->right=T;
        T->left=TS;
        TS=TS->right;
        T=nex;
    }
    while(T!=NULL){
        TS->right=T;
        T->left=TS;
        TS=TS->right;
        T=T->left;
    }
    while(T2!=NULL){
        TS->right=T2;
        T2->left=TS;
        TS=TS->right;
        T2=T2->right;
    }
    TS->right=NULL;
    while(L!=NULL){
        cout<<L->data<<" ";
        L=L->right;
    }
    return 0;
}
