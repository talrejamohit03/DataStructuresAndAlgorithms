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
    LPTR L1,L2,L=NULL;
    inpLL(L);
    L1=L;
    L2=L;
    int n;
    cout<<"Enter value of n: ";
    cin>>n;
    for(int i=0;i<n;i++)
        L2=L2->next;
    while(L2!=NULL){
        L1=L1->next;
        L2=L2->next;
    }
    cout<<n<<"th term from end is "<<L1->data;
}
