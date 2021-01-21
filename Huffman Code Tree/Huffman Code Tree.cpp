#include <iostream>
#include <string>
using namespace std;

typedef
struct hcnode{
    hcnode *lchild;
    char data;
    int freq;
    hcnode *rchild;
}*HPTR;

typedef
struct lnode{
    HPTR hcdata;
    lnode *next;
}*LPTR;
void swap_hcnode(HPTR &h1,HPTR &h2){
    HPTR t=h1;
    h1=h2;
    h2=t;
}
//void sortnodes(HPTR A[],int n){
//    for(int i=0;i<n;i++){
//        HPTR temp=A[i];
//        for(int j=i;j<n;j++){
//            if(A[j]->freq<temp->freq)
//                temp=A[j];
//        }
//        swap_hcnode(A[i],temp);
//    }
//}
//insertion sort on linked list
LPTR ins_sort(LPTR &LS,LPTR LU){
    if(LU==NULL)
        return LS;
    else{
        LPTR TS=LS,TMP=LU->next;
        LU->next=NULL;
        if(LS->hcdata->freq>LU->hcdata->freq){
            LU->next=LS;
            LS=LU;
        }else{
            while(TS->next!=NULL&&TS->next->hcdata->freq<LU->hcdata->freq)
                TS=TS->next;
            if(TS->next==NULL)
                TS->next=LU;
            else{
                LU->next=TS->next;
                TS->next=LU;
            }
        }
        return ins_sort(LS,TMP);
    }
}
void compress(HPTR T,char bits[],int &n){
    if(T->lchild!=NULL){
        bits[n++]='0';
        compress(T->lchild,bits,n);
    }
    if(T->data>='a'&&T->data<='z'){
        cout<<T->data<<" ";
        for(int j=0;j<n;j++)
            cout<<bits[j];
        cout<<endl;
    }
    if(T->rchild!=NULL){
        bits[n++]='1';
        compress(T->rchild,bits,n);
    }
    n--;
}
void decompress(HPTR T,char s[],int n){
    static HPTR TH=T;
    static int i=0;
    if(i<=n){
        if(T->lchild==NULL&&T->rchild==NULL){
            cout<<T->data<<" ";
            decompress(TH,s,n);
        }
        else if(s[i]=='0'){
            i++;
            decompress(T->lchild,s,n);
        }
        else if(s[i]=='1'){
            i++;
            decompress(T->rchild,s,n);
        }
    }
}
int main(){
    //t 15 a 3 m 30 j 10 k 40 p 2 s 20 . -1
    char c;
    int n;
    cin>>c>>n;
    LPTR L1=NULL,T,LU,LS;
    while(c!='.'&&n!=-1){
        LPTR temp=new(lnode);
        temp->hcdata=new(hcnode);
        temp->hcdata->data=c;
        temp->hcdata->freq=n;
        temp->hcdata->lchild=NULL;
        temp->hcdata->rchild=NULL;
        temp->next=NULL;
        if(L1==NULL){
            L1=temp;
            T=L1;
        }else{
            T->next=temp;
            T=T->next;
        }
        cin>>c>>n;
    }
    LU=L1->next;
    LS=L1;
    LS->next=NULL;
    L1=ins_sort(LS,LU);
    while(L1->next!=NULL){
        HPTR h=new(hcnode);
        h->data='.';
        h->lchild=L1->hcdata;
        h->rchild=L1->next->hcdata;
        h->freq=L1->hcdata->freq+L1->next->hcdata->freq;
        T=L1->next;
        while(T->next!=NULL&&T->next->hcdata->freq<h->freq)
            T=T->next;
        LPTR temp=new(lnode);
        temp->hcdata=h;
        temp->next=T->next;
        T->next=temp;
        L1=L1->next->next;
    }
    HPTR head=L1->hcdata;
    char s1[50];
    int n1=0;
    compress(head,s1,n1);
    char code[20]="0100101000110110101";
    decompress(head,code,20);
    return 0;
}
