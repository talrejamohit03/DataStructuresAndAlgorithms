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
int findlev(BTPTR T,int key,int currlev){
    if(T!=NULL){
        if(T->data==key)
            return currlev;
        int temp=findlev(T->lchild,key,currlev+1);
        if(temp!=0)
            return temp;
        temp=findlev(T->rchild,key,currlev+1);
        if(temp!=0)
            return temp;
    }else
        return 0;
}
int main(){
    //1 2 4 0 0 5 6 7 13 0 0 14 0 0 15 0 0 0 3 8 0 0 9 10 0 0 11 0 12 0 0
    BTPTR T1=NULL;
    int c,k1;
    cin>>c;
    btcreate(T1,c);
    cout<<"Enter key: ";
    cin>>k1;
    cout<<k1<<" level is: "<<findlev(T1,k1,0);
    return 0;
}
