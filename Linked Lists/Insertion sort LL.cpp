#include <iostream>
using namespace std;

struct lnode{
    int data;
    struct lnode* next;
};
typedef lnode* LPTR;

void inpLL(LPTR &L){
    LPTR T;
    int n;
    cout<<"New Linked List\n";
    cout<<"Enter element (-1 to terminate): ";
    cin>>n;
    while(n!=-1){
       LPTR temp;
       temp=new(lnode);
       temp->data=n;
       temp->next=NULL;
       if(L==NULL){
           L=temp;
           T=L;
       }else{
           while(T->next!=NULL)
                T=T->next;
            T->next=temp;
       }
       cout<<"Enter next element (-1 to terminate): ";
       cin>>n;
    }
}

int main(){
    LPTR L1=NULL,LS,LU,TS;
    inpLL(L1);
    LU=L1->next;
    LS=L1;
    LS->next=NULL;
    while(LU!=NULL){
        TS=LS;
        LPTR TMP=LU->next;
        LU->next=NULL;
        if(LS->data>LU->data){
            LU->next=LS;
            LS->next=NULL;
            LS=LU;
        }else{
            while(TS->next!=NULL&&TS->next->data<LU->data)
                TS=TS->next;
            if(TS->next==NULL)
                TS->next=LU;
            else{
                LU->next=TS->next;
                TS->next=LU;
            }
        }
        LU=TMP;
    }
    while(LS!=NULL){
        cout<<LS->data<<" ";
        LS=LS->next;
    }
    return 0;
}
