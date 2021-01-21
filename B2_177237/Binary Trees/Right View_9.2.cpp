#include <iostream>
using namespace std;

typedef
struct btnode{
    btnode *lchild;
    int data;
    btnode *rchild;
} *BTPTR;
void btcreate(BTPTR &T,int k){
    if(k!=0){
        T=new(btnode);
        T->lchild=NULL;
        T->rchild=NULL;
        T->data=k;
        int k1;
        cin>>k1;
        btcreate(T->lchild,k1);
        cin>>k1;
        btcreate(T->rchild,k1);
    }
}
void rightv_recursive(BTPTR T,int currlev){
    static int maxl=0;
    if(T!=NULL){
        if(currlev>=maxl){
            cout<<T->data<<"\n";
            maxl++;
        }
        rightv_recursive(T->rchild,currlev+1);
        rightv_recursive(T->lchild,currlev+1);
    }
}
int main(){
    //1 2 4 0 0 5 6 7 13 0 0 14 0 0 15 0 0 0 3 8 0 0 9 10 0 0 11 0 12 0 0
    BTPTR T1=NULL;
    int c;
    cin>>c;
    btcreate(T1,c);
    rightv_recursive(T1,0);
    return 0;
}

