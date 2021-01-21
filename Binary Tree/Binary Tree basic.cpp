#include <iostream>
using namespace std;

typedef
struct btnode{
    btnode *lchild;
    char data;
    btnode *rchild;
} *BTPTR;

void btcreate(BTPTR &T,char k){
    if(k!='.'){
        T=new(btnode);
        T->lchild=NULL;
        T->rchild=NULL;
        T->data=k;
        char k1;
        cin>>k1;
        btcreate(T->lchild,k1);
        cin>>k1;
        btcreate(T->rchild,k1);
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
    //A M B . . D F . . . J . R H . . K . .
    BTPTR T1=NULL;
    char c;
    cout<<"Enter elements of BT: ";
    cin>>c;
    btcreate(T1,c);
    serealize(T1);
}
