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
void revLL(LPTR bac,LPTR pres,LPTR &L){
    if(L==NULL)
        return;
    LPTR forw;
    forw=pres->next;
    if(forw==NULL)
        L=pres;
    else
        revLL(pres,forw,L);
    pres->next=bac;
}
int main(){
    LPTR L1=NULL;
    inpLL(L1);
    revLL(NULL,L1,L1);
    //Lpres=L;
    /*while(Lpres!=NULL){
        Lforw=Lpres->next;
        Lpres->next=Lback;
        Lback=Lpres;
        Lpres=Lforw;
    }
    L=Lback;*/
    while(L1!=NULL){
        cout<<L1->data<<" ";
        L1=L1->next;
    }
    return 0;
}
