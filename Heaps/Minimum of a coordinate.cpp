#include <iostream>
using namespace std;

const int k=2;

typedef
struct kdnode{
    kdnode *lchild;
    int data[k];
    kdnode *rchild;
}* KDPTR;

void ins_kd(KDPTR &T,int key[]){
    static int i=0;
    if(T==NULL){
        T=new(kdnode);
        T->lchild=NULL;
        T->rchild=NULL;
        for(int j=0;j<k;j++)
            T->data[j]=key[j];
    }else{
        if(T->data[i]>key[i]){
            i=(i+1)%k;
            ins_kd(T->lchild,key);
        }else if(T->data[i]<=key[i]){
            i=(i+1)%k;
            ins_kd(T->rchild,key);
        }
    }
}
