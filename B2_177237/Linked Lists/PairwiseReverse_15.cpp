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
void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}
void pw_rev(LPTR L){
    if(L!=NULL&&L->next!=NULL){
        swap(L->data,L->next->data);
        pw_rev(L->next->next);
    }
}
int main(){
    LPTR L1=NULL;
    inpLL(L1);
    pw_rev(L1);
    while(L1!=NULL){
        cout<<L1->data<<" ";
        L1=L1->next;
    }
}
