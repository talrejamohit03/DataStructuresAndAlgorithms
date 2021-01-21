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
           while(T->next!=NULL)
            T=T->next;
           T->next=temp;
       }
       cout<<"Enter next element (-1 to terminate): ";
       cin>>n;
    }
}
int main(){
    LPTR L1=NULL,L2=NULL,T1,T2;
    inpLL(L1);
    inpLL(L2);
    T1=L1;
    T2=L2;
    cout<<"Union of the lists is: \n";
    while(T1!=NULL&&T2!=NULL){
        if(T1->data>T2->data){
            cout<<T2->data<<" ";
            T2=T2->next;
        }else if(T1->data<T2->data){
            cout<<T1->data<<" ";
            T1=T1->next;
        }else{
            cout<<T1->data<<" ";
            T1=T1->next;
            T2=T2->next;
        }
    }
    while(T1!=NULL){
        cout<<T1->data<<" ";
        T1=T1->next;
    }
    while(T2!=NULL){
        cout<<T2->data<<" ";
        T2=T2->next;
    }
    cout<<"\nIntersection of the lists: \n";
    T1=L1;
    int flag=0;
    while(T1!=NULL){
        T2=L2;
        while(T2!=NULL){
            if(T1->data==T2->data){
                cout<<T1->data<<" ";
                flag=1;
                break;
            }
            T2=T2->next;
        }
        T1=T1->next;
    }
    if(flag==0)
        cout<<"No common elements.";
    return 0;
}
