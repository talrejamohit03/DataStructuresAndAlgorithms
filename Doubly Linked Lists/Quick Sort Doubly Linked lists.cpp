#include <iostream>

using namespace std;
typedef
struct dnode{
    struct dnode *left;
    int data;
    struct dnode *right;
}*DPTR;

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
void printD(DPTR D){
    while(D!=NULL){
        cout<<D->data<<" ";
        D=D->right;
    }
}
void swap(int &a,int &b){
    int temp;
    temp=a;
    a=b;
    b=temp;
}
DPTR partition(DPTR &D,DPTR low,DPTR high){
    DPTR l=low->right,h=high,p=low;
    while(h->right!=l){
        while(l!=NULL&&l->data<p->data)
            l=l->right;
        while(h->data>p->data)
             h=h->left;
        if(h->right!=l)
            swap(l->data,h->data);
    }
    swap(p->data,h->data);
    return h;
}
void quicksort(DPTR &D,DPTR low,DPTR high){
    DPTR J;
    if(low!=high){
        J=partition(D,low,high);
        //when pivot is the greatest element
        if(J!=high)
            quicksort(D,J->right,high);
        //when pivot is the smallest element
        if(J!=low)
            quicksort(D,low,J->left);
    }
}

int main(){
    DPTR D1=NULL,T;
    inpD(D1);
    T=D1;
    while(T->right!=NULL)
        T=T->right;
    quicksort(D1,D1,T);
    printD(D1);
}
