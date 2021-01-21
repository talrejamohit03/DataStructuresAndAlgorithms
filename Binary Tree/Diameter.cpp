#include <iostream>
using namespace std;

typedef
struct btnode{
    int data;
    btnode *lc;
    btnode *rc;
}*btptr;

btptr construct(btptr &T,int k){
    if(k==-1)
        return NULL;
    T=new(btnode);
    T->data=k;
    T->lc=NULL;
    T->rc=NULL;
    int k1;
    cin>>k1;
    T->lc=construct(T->lc,k1);
    cin>>k1;
    T->rc=construct(T->rc,k1);
    return T;
}
int diameter(btptr T,int &height){
    if(T==NULL)
        return 0;

    return 1+((diameter(T->lc)+diameter(T->rc))/2);
}

int main(){
    //1 2 3 -1 -1 4 5 -1 -1 6 -1 -1 7 -1 8 9 -1 -1 -1
    btptr t1=NULL;
    int n;
    cin>>n;
    construct(t1,n);
    cout<<"Diameter: "<<1+diameter(t1);
    return 0;
}
