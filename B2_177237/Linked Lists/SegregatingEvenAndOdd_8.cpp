#include <iostream>

using namespace std;

struct lnode{
    int data;
    lnode *next;
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
           T->next=temp;
            T=T->next;
       }
       cout<<"Enter next element (-1 to terminate): ";
       cin>>n;
    }
}
int main(){
    LPTR L1=NULL,T,headE=NULL,TE,TO,headO=NULL,E2;
    inpLL(L1);
    T=L1;
    while(T!=NULL){
        if((T->data)%2==0){
            if(headE==NULL){
                headE=T;
                TE=headE;
            }
            else{
                TE->next=T;
                TE=TE->next;
            }
        }else{
            if(headO==NULL){
                headO=T;
                TO=headO;
            }
            else{
                TO->next=T;
                TO=TO->next;
            }
        }
    T=T->next;
    }
    TE->next=headO;
    TO->next=NULL;

    /*while(E->next!=NULL){
        E=E->next;
        E2=E2->next;
    }
    if((L1->data)%2!=0){
        LPTR temp=new(lnode);
        temp->data=L1->data;
        temp->next=NULL;
        E->next=temp;
        E=E->next;
        L1=L1->next;
    }
    T=L1;
    while(T!=E2){
        if((T->next->data)%2!=0){
            LPTR temp=new(lnode);
            temp->data=T->data;
            temp->next=NULL;
            E->next=temp;
            E=E->next;
            T->next=T->next->next;
            continue;
        }
        T=T->next;

    }*/
    while(headE!=NULL){
        cout<<headE->data<<" ";
        headE=headE->next;
    }
    return 0;
}
