#include <iostream>
using namespace std;

typedef
struct btnode{
    btnode *lchild;
    char data;
    btnode *rchild;
} *BTPTR;

void btcreate_ldrlrd(BTPTR &T, char lrd[], char ldr[],int low, int high){
    static int i=high;
    if(low<=high){
        T=new(btnode);
        T->lchild=NULL;
        T->rchild=NULL;
        T->data=lrd[i--];
        int j=low;
        while(ldr[j]!=T->data)j++;
        btcreate_ldrlrd(T->rchild,lrd,ldr,j+1,high);
        btcreate_ldrlrd(T->lchild,lrd,ldr,low,j-1);
    }
}
void serealize(BTPTR T){
    if(T!=NULL){
        cout<<T->data<<" ";
        serealize(T->lchild);
        serealize(T->rchild);
    }else
        cout<<". ";
}
int main(){
    BTPTR T1=NULL;
    char lrd1[10]="BFDMRNHJA";
    char ldr1[10]="BMFDARJNH";
    btcreate_ldrlrd(T1,lrd1,ldr1,0,8);
    serealize(T1);
    return 0;
}
