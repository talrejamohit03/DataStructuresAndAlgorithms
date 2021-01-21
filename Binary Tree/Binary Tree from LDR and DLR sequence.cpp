#include <iostream>
using namespace std;

typedef
struct btnode{
    btnode *lchild;
    char data;
    btnode *rchild;
} *BTPTR;

void btcreate_ldrdlr(BTPTR &T, char dlr[], char ldr[],int low, int high){
    static int i=0;
    if(low<=high){
        T=new(btnode);
        T->lchild=NULL;
        T->rchild=NULL;
        T->data=dlr[i++];
        int j=low;
        while(ldr[j]!=T->data)j++;
        btcreate_ldrdlr(T->lchild,dlr,ldr,low,j-1);
        btcreate_ldrdlr(T->rchild,dlr,ldr,j+1,high);
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
    char dlr1[10]="AMBDFJRHN";
    char ldr1[10]="BMFDARJNH";
    btcreate_ldrdlr(T1,dlr1,ldr1,0,8);
    serealize(T1);
    return 0;
}
