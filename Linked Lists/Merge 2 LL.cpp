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
    LPTR L1=NULL,L2=NULL,LM=NULL,T1,T2,T3;
    inpLL(L1);
    inpLL(L2);
    T1=L1;
    T2=L2;
    while(T1!=NULL&&T2!=NULL){
        if(LM==NULL){
            if(T1->data>T2->data){
                LM=T2;
                T2=T2->next;
            }
            else if(T1->data<T2->data){
                LM=T1;
                T1=T1->next;
            }else{
                LM=T1;
                T1=T1->next;
                T2=T2->next;
            }
            T3=LM;
        }else{
            if(T1->data>T2->data){
                T3->next=T2;
                T2=T2->next;
            }
            else if(T1->data<T2->data){
                T3->next=T1;
                T1=T1->next;
            }else{
                T3->next=T1;
                T1=T1->next;
                T2=T2->next;
            }
            T3=T3->next;
        }
    }
    if(T1!=NULL)
        T3->next=T1;
    if(T2!=NULL)
        T3->next=T2;
    while(LM!=NULL){
        cout<<LM->data<<" ";
        LM=LM->next;
    }
    return 0;
}
