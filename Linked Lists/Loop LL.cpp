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
    LPTR L1=NULL,T,s,f,TN,TN2;
    inpLL(L1);
    TN=L1;
    TN2=L1;
    s=L1;
    f=L1;
    for(int i=0;i<4;i++)
        TN2=TN2->next;
    while(TN->next!=NULL)
        TN=TN->next;
    TN->next=TN2;
    int flag=0;
    while(f->next!=NULL){
        s=s->next;
        f=f->next->next;
        if(f==s){
            flag=1;
            break;
        }
    }
    if(flag==1)
        cout<<"Loop present";
    else
        cout<<"Loop not present.";
    LPTR T1=L1;
    while(T1!=s){
        s=s->next;
        T1=T1->next;
    }
    cout<<"Intersection point is at: "<<T1->data;
    return 0;
}
