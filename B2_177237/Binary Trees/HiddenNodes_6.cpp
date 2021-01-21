#include <iostream>
using namespace std;

typedef
struct btnode{
    btnode *lchild;
    int data;
    btnode *rchild;
    int index;
} *BTPTR;
typedef
struct lnode{
    int data;
    lnode *next;
} *LPTR;
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
void leftv_recursive(BTPTR T,int currlev,LPTR &lv){
    static int maxl=0;
    static LPTR T1=lv;
    if(T!=NULL){
        if(currlev>=maxl){
            LPTR temp=new(lnode);
            temp->data=T->data;
            temp->next=NULL;
            if(lv==NULL){
                lv=temp;
                T1=lv;
            }
            else{
                T1->next=temp;
                T1=T1->next;
            }
            maxl++;
        }
        leftv_recursive(T->lchild,currlev+1,lv);
        leftv_recursive(T->rchild,currlev+1,lv);
    }
}
void rightv_recursive(BTPTR T,int currlev,LPTR &rv){
    static int maxl=0;
    static LPTR T2=rv;
    if(T!=NULL){
        if(currlev>=maxl){
            LPTR temp=new(lnode);
            temp->data=T->data;
            temp->next=NULL;
            if(rv==NULL){
                rv=temp;
                T2=rv;
            }
            else{
                T2->next=temp;
                T2=T2->next;
            }
            maxl++;
        }
        rightv_recursive(T->rchild,currlev+1,rv);
        rightv_recursive(T->lchild,currlev+1,rv);
    }
}
void bottomview(BTPTR T,bview elem[],int mi,int currlev){
    if(T!=NULL){
        if(currlev>=elem[T->index-mi].lev){
            elem[T->index-mi].val=T->data;
            elem[T->index-mi].lev=currlev;
        }
        bottomview(T->lchild,elem,mi,currlev+1);
        bottomview(T->rchild,elem,mi,currlev+1);
    }
}
int main(){
    //1 2 4 0 0 5 6 7 13 0 0 14 0 0 15 0 0 0 3 8 0 0 9 10 0 0 11 0 12 0 0
    BTPTR T1=NULL;
    LPTR LV=NULL,RV=NULL,TLV;
    int c,mi=0,mxi=0;
    cin>>c;
    btcreate(T1,c,0,mxi,mi);
    bview bottomelem[mxi-mi+1];
    for(int i=0;i<mxi-mi+1;i++){
        bottomelem[i].val=0;
        bottomelem[i].lev=0;
    }
    bottomview(T1,bottomelem,mi,0);
    leftv_recursive(T1,0,LV);
    rightv_recursive(T1,0,RV);
    TLV=LV;
    while(TLV!=NULL){
        cout<<TLV->data<<" ";
        TLV=TLV->next;
    }
    for(int i=0;i<mxi-mi+1;i++){
        LPTR TLV1=LV,TRV1=RV;
        int flag=1;
        while(TLV1!=NULL){
            if(TLV1->data==bottomelem[i].val){
                flag=0;
                break;
            }
            TLV1=TLV1->next;
        }
        if(flag==0)
            continue;
        cout<<bottomelem[i].val<<" ";
    }
    while(RV->next!=NULL){
        LPTR TRV=RV;
        while(TRV->next->next!=NULL)
            TRV=TRV->next;
        int flag=1;
        for(int j=0;j<mxi-mi+1;j++){
            if(TRV->next->data==bottomelem[j].val){
                flag=0;
                break;
            }
        }
        if(flag==0){
            TRV->next=NULL;
            continue;
        }
        cout<<TRV->next->data<<" ";
        TRV->next=NULL;
    }
}
