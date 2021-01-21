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
void rem_dup(LPTR L){
    if(L->next!=NULL){
        LPTR start=L->next,prev=L;
        while(start!=NULL){
            if(start->data==L->data)
                prev->next=start->next;
            else
                prev=start;
            start=start->next;
        }
        rem_dup(L->next);
    }
}
int main(){
    LPTR L1=NULL;
    inpLL(L1);
    rem_dup(L1);
    while(L1!=NULL){
        cout<<L1->data<<" ";
        L1=L1->next;
    }
    return 0;

}
