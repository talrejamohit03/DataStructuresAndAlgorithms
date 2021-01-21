#include <iostream>
using namespace std;
struct rnode{
    rnode *bktnext;
    struct lnode *blink;
};
typedef rnode *RPTR;
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
    LPTR L1=NULL,T,TR1;
    RPTR R=NULL,TR=R;
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
    for(int n=0;n<10;n++){
        RPTR tempr=new(rnode);
        tempr->bktnext=NULL;
        tempr->blink=NULL;
        if(R==NULL){
            R=tempr;
            TR=R;
        }else{
            TR->bktnext=tempr;
            TR=TR->bktnext;
        }
    }
    TR=R;
    for(int i=0;i<it;i++){
        T=L1;
        //TR1 is pointer for blink type lnode, TR is pointer for bktnext type rnode
        while(T!=NULL){
            LPTR temp=new(lnode),TR1;
            temp->data=T->data;
            temp->next=NULL;
            int ind=temp->data;
            for(int j=0;j<i;j++)
                ind=ind/10;
            ind=ind%10;
            TR=R;
            for(int j=0;j<ind;j++)
                TR=TR->bktnext;
            TR1=TR->blink;
            if(TR1==NULL){
                TR->blink=temp;
                TR1=TR->blink;
            }else{
                TR1->next=temp;
                TR1=TR1->next;
            }
            T=T->next;
        }
        T=L1;
        TR=R;
        for(int i=0;i<10;i++){
            TR1=TR->blink;
            while(TR1!=NULL){
                T->data=TR1->data;
                TR1=TR1->next;
                T=T->next;
            }
            TR->blink=NULL;
            TR=TR->bktnext;
        }

    }
    while(L1!=NULL){
        cout<<L1->data<<" ";
        L1=L1->next;
    }

    return 0;
}
