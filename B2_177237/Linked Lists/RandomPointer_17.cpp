#include <iostream>
using namespace std;

struct lnode{
    int data;
    struct lnode* next;
    struct lnode* rptr;
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
    LPTR L1=NULL,T;
    inpLL(L1);
    T=L1;
    while(T!=NULL){
        LPTR T2;
        T2=L1;
        int n;
        cout<<"Enter random pointer element for (-1 for NULL)"<<T->data<<": ";
        cin>>n;
        if(n==-1){
            T->rptr=NULL;
            T=T->next;
            continue;
        }
        while(T2->data!=n)
            T2=T2->next;
        T->rptr=T2;
        T=T->next;
    }
    cout<< (L1->next->rptr->data);
}
