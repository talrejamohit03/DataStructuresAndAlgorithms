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
LPTR ins_sort(LPTR &LS,LPTR LU){
    if(LU==NULL)
        return LS;
    else{
        LPTR TS=LS,TMP=LU->next;
        LU->next=NULL;
        if(LS->data>LU->data){
            LU->next=LS;
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
        return ins_sort(LS,TMP);
    }
}
int main(){
    LPTR L1=NULL,LS,LU;
    inpLL(L1);
    LU=L1->next;
    LS=L1;
    LS->next=NULL;
    L1=ins_sort(LS,LU);
    while(L1!=NULL){
        cout<<L1->data<<" ";
        L1=L1->next;
    }
    return 0;
}
