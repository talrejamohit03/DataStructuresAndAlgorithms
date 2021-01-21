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
    LPTR L1=NULL,T1;
    inpLL(L1);
    T1=L1;
    while(T1->next!=NULL){
        if(T1->data==T1->next->data)
            T1->next=T1->next->next;
        else
            T1=T1->next;
    }
    while(L1!=NULL){
        cout<<L1->data<<" ";
        L1=L1->next;
    }

}
