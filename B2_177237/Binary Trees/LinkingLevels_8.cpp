#include <iostream>
using namespace std;

typedef
struct btnode{
    btnode *lchild;
    char data;
    btnode *rchild;
    btnode *lvptr;
} *BTPTR;

void btcreate(BTPTR &T,char k){
    if(k!='.'){
        T=new(btnode);
        T->lchild=NULL;
        T->rchild=NULL;
        T->lvptr=NULL;
        T->data=k;
        char k1;
        cin>>k1;
        btcreate(T->lchild,k1);
        cin>>k1;
        btcreate(T->rchild,k1);
    }
}
void levellink(BTPTR T){
    if(T!=NULL){
        BTPTR Le,Lp=T,nexL;
        if(T->lchild!=NULL)
            Le=T->lchild;
        else if(T->rchild!=NULL)
            Le=T->rchild;
        int flag=0;
        while(Lp!=NULL){
            if(Lp->lchild!=NULL){
                Le->lvptr=Lp->lchild;
                if(flag==0&&Le->lchild!=NULL){
                    nexL=Le;
                    flag=1;
                }
                Le=Le->lvptr;
            }
            if(Lp->rchild!=NULL){
                Le->lvptr=Lp->rchild;
                if(flag==0&&Le->rchild!=NULL){
                    nexL=Le;
                    flag=1;
                }
                Le=Le->lvptr;
            }
            Lp=Lp->lvptr;
        }
        if(flag==1)
            levellink(nexL);
    }
}
void levprint(BTPTR T){
    BTPTR lev=T,nlev;
    int flag=0;
    while(lev!=NULL){
        cout<<lev->data<<" ";
        if(flag==0){
            if(lev->lchild!=NULL){
                nlev=lev->lchild;
                flag=1;
            }else if(lev->rchild!=NULL){
                nlev=lev->rchild;
                flag=1;
            }
        }
        lev=lev->lvptr;
    }
    cout<<"\n";
    if(flag==1)
        levprint(nlev);
}
int main(){
    //A M B . . D F . . . J R . . H N . . .
    //A M B . N . . D F . . . J . R H . . K . .
    BTPTR T1=NULL;
    char c;
    cin>>c;
    btcreate(T1,c);
    levellink(T1);
    levprint(T1);
    return 0;
}
