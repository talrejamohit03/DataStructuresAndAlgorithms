#include <iostream>

using namespace std;

struct lnode{
    int data;
    lnode *next;
};
typedef lnode* LPTR;
int cnode(LPTR &L){
    if(L==NULL)
        return 0;
    else
        return 1+cnode(L->next);
}
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
    //output will not be correct if there are common elements between the 2 lists
    //we will have to use the stack method for it
    LPTR L1=NULL,L2=NULL,T1,T2,smin,smax;
    inpLL(L1);
    inpLL(L2);
    T1=L1;
    T2=L2;
    int l1=cnode(T1),l2=cnode(T2);
    LPTR Lmax=(l1>l2)?L1:L2;
    LPTR Lmin=(l1>l2)?L2:L1;
    smin=Lmin;smax=Lmax;
   //creating branching list
    while(smin->next!=NULL)
        smin=smin->next;
    for(int i=0;i<5;i++)
        smax=smax->next;
    smin->next=smax;
    smin=Lmin;smax=Lmax;
    int lmin=cnode(smin),lmax=cnode(smax);
    for(int j=0;j<(lmax-lmin);j++)
        Lmax=Lmax->next;
    while(Lmax!=Lmin){
        Lmax=Lmax->next;
        Lmin=Lmin->next;
    }
    cout<<"Intersection point is at: "<<Lmax->data;
    return 0;
}
