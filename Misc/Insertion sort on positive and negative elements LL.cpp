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
    cout<<"Enter element (0 to terminate): ";
    cin>>n;
    while(n!=0){
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
       cout<<"Enter next element (0 to terminate): ";
       cin>>n;
    }
}

void segregate(LPTR &L){
    LPTR Lp=NULL,Ln=NULL,T=L;
    while(T!=NULL){
        if(T->data>0){
            if(Lp==NULL){
                Lp=T;
            }
        }
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
        return ins_sort(LS,TMP);
    }
}
int main(){

}
