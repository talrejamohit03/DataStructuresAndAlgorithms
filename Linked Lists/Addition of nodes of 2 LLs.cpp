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
void add_nodes(LPTR L1,LPTR &L2){
    static int carr=0;
    if(L1!=NULL&&L2!=NULL){
        add_nodes(L1->next,L2->next);
        L2->data=L2->data+L1->data+carr;
        carr=L2->data/10;
    }
}

int main(){
    LPTR L1=NULL,L2=NULL,T1,T2,TR;
    inpLL(L1);
    inpLL(L2);
    T1=L1;
    T2=L2;
    add_nodes(T1,T2);
    TR=L2->next;
    while(TR!=NULL){
        TR->data%=10;
        TR=TR->next;
    }
    while(L2!=NULL){
        cout<<L2->data<<" ";
        L2=L2->next;
    }
    return 0;
}
