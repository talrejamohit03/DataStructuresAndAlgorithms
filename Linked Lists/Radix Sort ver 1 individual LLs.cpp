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
    LPTR R[10],L1=NULL,T,TR[10];
    inpLL(L1);
    T=L1;
    int it=0;
    while(T!=NULL){
        int temp=T->data,itcurr=0;
        while(temp>0){
            temp=temp/10;
            itcurr++;
        }
        if(itcurr>it)
            it=itcurr;
        T=T->next;
    }
    for(int i=0;i<it;i++){
        T=L1;
        for(int i=0;i<10;i++)
            R[i]=NULL;
        while(T!=NULL){
            LPTR temp=new(lnode);
            temp->data=T->data;
            temp->next=NULL;
            int ind=temp->data;
            for(int j=0;j<i;j++)
                ind=ind/10;
            ind=ind%10;
            if(R[ind]==NULL){
                R[ind]=temp;
                TR[ind]=R[ind];
            }else{
                TR[ind]->next=temp;
                TR[ind]=TR[ind]->next;
            }
            T=T->next;
        }
        T=L1;
        for(int i=0;i<10;i++){
            TR[i]=R[i];
            while(TR[i]!=NULL){
                T->data=TR[i]->data;
                TR[i]=TR[i]->next;
                T=T->next;
            }
        }
    }
    while(L1!=NULL){
        cout<<L1->data<<" ";
        L1=L1->next;
    }

    return 0;
}
