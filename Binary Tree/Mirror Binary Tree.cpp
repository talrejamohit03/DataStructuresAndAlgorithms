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
bool mirror(BTPTR T1, BTPTR T2){
    if(T1!=NULL&&T2!=NULL){
        if(T1->data==T2->data)
            return mirror(T1->lchild,T2->rchild)&&mirror(T1->rchild,T2->lchild);
        else
            return 0;
    }else if(T1==NULL&&T2==NULL)
        return 1;
}
int main(){
    //A M B . . D F . . . J . R H . . K . .
    //A J R K . . H . . . M D . F . . B . .
    BTPTR T1=NULL,T2=NULL;
    char c1,c2;
    cin>>c1;
    btcreate(T1,c1);
    cin>>c2;
    btcreate(T2,c2);
    if(mirror(T1,T2))
        cout<<"Mirror trees.";
    else
        cout<<"Not mirror.";
    return 0;
}

