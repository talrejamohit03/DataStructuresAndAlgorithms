#include <iostream>
using namespace std;

typedef
struct btnode{
    btnode *lchild;
    int data;
    btnode *rchild;
    btnode *lvptr;
} *BTPTR;
void ldr(BTPTR T,int A[]){
    static int i=0;
    if(T!=NULL){
        ldr(T->lchild,A);
        A[i++]=T->data;
        ldr(T->rchild,A);
    }
}
void btcreate(BTPTR &T,int k,int &s){
    if(k!=0){
        T=new(btnode);
        T->lchild=NULL;
        T->rchild=NULL;
        T->lvptr=NULL;
        T->data=k;
        s++;
        int k1;
        cin>>k1;
        btcreate(T->lchild,k1,s);
        cin>>k1;
        btcreate(T->rchild,k1,s);
    }
}
void convert(BTPTR &T,int A[],int s){
    if(T!=NULL){
        convert(T->rchild,A,s);
        T->data=A[--s];
        convert(T->lchild,A,s);
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
    //30 25 9 0 2 0 0 45 0 0 18 0 36 0 0
    int k,si=0;
    cin>>k;
    BTPTR T1=NULL;
    btcreate(T1,k,si);
    int arr[si];
    ldr(T1,arr);
    for(int i=1;i<si;i++){
        int j=i-1,v=arr[i];
        while (arr[j]>v&&j>=0){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=v;
    }
    convert(T1,arr,si);
    levellink(T1);
    levprint(T1);
    return 0;
}
