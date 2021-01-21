#include <iostream>
using namespace std;

typedef
struct treap{
    char k1;
    int k2;
    treap *lchild;
    treap *rchild;
}*TRPTR;
void rotateleft(TRPTR &T){
    TRPTR temp=T->rchild;
    T->rchild=temp->lchild;
    temp->lchild=T;
    T=temp;
}
void rotateright(TRPTR &T){
    TRPTR temp=T->lchild;
    T->lchild=temp->rchild;
    temp->rchild=T;
    T=temp;
}
void ins_treap(TRPTR &T,char c1,int c2){
    if(T==NULL){
        T=new(treap);
        T->k1=c1;
        T->k2=c2;
        T->lchild=NULL;
        T->rchild=NULL;
    }else{
        if(c1<T->k1){
            ins_treap(T->lchild,c1,c2);
            if(T->lchild->k2<T->k2)
                rotateright(T);
        }
        else if(c1>T->k1){
            ins_treap(T->rchild,c1,c2);
            if(T->rchild->k2<T->k2)
                rotateleft(T);
        }
    }
}
TRPTR max_trp(TRPTR T){
    if(T->rchild==NULL)
        return T;
    return max_trp(T->rchild);
}
TRPTR min_trp(TRPTR T){
    if(T->lchild==NULL)
        return T;
    return min_trp(T->lchild);
}
void ldrprint(TRPTR T){
    if(T!=NULL){
        ldrprint(T->lchild);
        cout<<T->k1<<" "<<T->k2<<" ";
        ldrprint(T->rchild);
    }
}
bool chktrp(TRPTR T){
    if(T!=NULL){
        if(T->lchild!=NULL&&T->rchild!=NULL){
            if(T->lchild->k1<T->k1&&T->rchild->k1>T->k1&&T->lchild->k2>T->k2&&T->rchild->k2>T->k2)
                return chktrp(T->lchild)&&chktrp(T->rchild);
            return 0;
        }
        else if(T->lchild!=NULL){
            if(T->lchild->k1<T->k1&&T->lchild->k2>T->k2)
                return chktrp(T->lchild);
            return 0;
        }else if(T->rchild!=NULL){
            if(T->rchild->k1>T->k1&&T->rchild->k2>T->k2)
                return chktrp(T->rchild);
            return 0;
        }
    }
    return 1;
}
void del_trpnode(TRPTR &T,char k,int c2){
    if(T!=NULL){
        if(k<T->k1)
            del_trpnode(T->lchild,k,c2);
        else if(k>T->k1)
            del_trpnode(T->rchild,k,c2);
        else{
            if(T->k2!=c2){
                cout<<"Node doesn't exist.";
                return;
            }
            if(T->lchild==NULL&&T->rchild==NULL)
                T=NULL;
            else{
                TRPTR temp;
                if(T->rchild==NULL)
                    temp=max_trp(T->lchild);
                else if(T->lchild==NULL)
                    temp=min_trp(T->rchild);
                else{
                    int ch;
                    cout<<"Do you want it to be replaced by \n1. min of rchild or 2.max of lchild: ";
                    cin>>ch;
                    if(ch==1)
                        temp=min_trp(T->rchild);
                    else
                        temp=max_trp(T->lchild);
                }
                char tempc=temp->k1;
                int tempn=temp->k2;
                del_trpnode(T,temp->k1,temp->k2);
                T->k1=tempc;
                T->k2=tempn;
                if(T->lchild!=NULL&&T->lchild->k2<T->k2)
                    rotateright(T);
                if(T->rchild!=NULL&&T->rchild->k2<T->k2)
                    rotateleft(T);
            }
        }
    }
}

int main(){
    //p 45 s 59 h 21 m 37 e 32 b 3 k 40 a 10 o 50 . -1
    TRPTR T1=NULL;
    char ch1;
    int ch2;
    cout<<"Enter elements: (. -1 to terminate) ";
    cin>>ch1>>ch2;
    while(ch1!='.'&&ch2!=-1){
        ins_treap(T1,ch1,ch2);
        cin>>ch1>>ch2;
    }
    ldrprint(T1);
    //T1->rchild->rchild->k1='a';
    //T1->rchild->rchild->k2=12;
    cout<<"\n";
    if(chktrp(T1))
        cout<<"It is a treap";
    else
        cout<<"Not treap";
    cout<<"\nEnter node to delete: ";
    cin>>ch1>>ch2;
    del_trpnode(T1,ch1,ch2);
    ldrprint(T1);
    return 0;
}
