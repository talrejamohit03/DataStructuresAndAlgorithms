#include <iostream>
using namespace std;

typedef
struct btnode{
    btnode *lchild;
    int data;
    btnode *rchild;
    int index;
} *BTPTR;

struct bview{
    int val;
    int lev;
};
void btcreate(BTPTR &T,int k,int i,int &maxin,int &minin){
    if(k!=0){
        T=new(btnode);
        T->lchild=NULL;
        T->rchild=NULL;
        T->index=i;
        T->data=k;
        if(i>maxin)
            maxin=i;
        if(i<minin)
            minin=i;
        int k1;
        cin>>k1;
        btcreate(T->lchild,k1,i-1,maxin,minin);
        cin>>k1;
        btcreate(T->rchild,k1,i+1,maxin,minin);
    }
}
void topview(BTPTR T,int elem[],int mi){
    if(T!=NULL){
        if(!elem[T->index-mi])
            elem[T->index-mi]=T->data;
        topview(T->lchild,elem,mi);
        topview(T->rchild,elem,mi);
    }
}
//vertically the right rchild with the same index though having a lower level will be placed above all other lchildren and may
//also come above lchildren having a greater level value
void bottomview(BTPTR T,bview elem[],int mi,int currlev){
    if(T!=NULL){
        /*if(currlev>=elem[T->index-mi].lev){
            elem[T->index-mi].val=T->data;
            elem[T->index-mi].lev=currlev;
        }*/
        elem[T->index-mi].val=T->data;
        bottomview(T->lchild,elem,mi,currlev+1);
        bottomview(T->rchild,elem,mi,currlev+1);
    }
}
int main(){
    //1 2 4 0 0 5 6 7 13 0 0 14 0 0 15 0 0 0 3 8 0 0 9 10 0 0 11 0 12 0 0
    BTPTR T1=NULL;
    int c,mi=0,mxi=0;
    cin>>c;
    btcreate(T1,c,0,mxi,mi);
    int topelem[mxi-mi+1];
    bview bottomelem[mxi-mi+1];
    for(int i=0;i<mxi-mi+1;i++){
        topelem[i]=0;
        bottomelem[i].val=0;
        bottomelem[i].lev=0;
    }
    topview(T1,topelem,mi);
    for(int j=0;j<mxi-mi+1;j++)
        cout<<topelem[j]<<" ";
    bottomview(T1,bottomelem,mi,0);
    cout<<"\n";
    for(int j=0;j<mxi-mi+1;j++)
        cout<<bottomelem[j].val<<" ";
    return 0;
}
