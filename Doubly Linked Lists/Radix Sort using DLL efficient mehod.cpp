#include <iostream>
using namespace std;
struct dnode{
    dnode *right;
    dnode *left;
    struct lnode *blink;
};
typedef dnode *RPTR;
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
    //L1 is the list that I have to sort
    T=L1;
    int it=0;
    //to find the number of iterations which is the number of digits in the maximum number...here I am calculating the number of
    //digits in every number.
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
    //initialising the main DLL of all buckets
    for(int n=0;n<10;n++){
        RPTR tempr=new(dnode);
        tempr->right=NULL;
        tempr->left=NULL;
        tempr->blink=NULL;
        if(R==NULL){
            R=tempr;
            TR=R;
        }else{
            TR->right=tempr;
            tempr->left=TR;
            TR=TR->right;
        }
    }
    TR=R;
    //radix sort
    for(int i=0;i<it;i++){
        T=L1;
        int prevind=0;
        //TR1 is pointer for blink type lnode, TR is pointer for dnode->right type dnode,
        //T is the pointer to the list to be sorted
        while(T!=NULL){
            LPTR temp=new(lnode),TR1;
            temp->data=T->data;
            temp->next=NULL;
            int ind=temp->data;//prevind stores the index of the previous element
            //by storing the previous index we can tell where to move, either left or right
            //index means the ones or tens or hundreds, etc place
            for(int j=0;j<i;j++)
                ind=ind/10;
            ind=ind%10;
            int diff=ind-prevind;
            if(diff>0){
                for(int j=0;j<diff;j++)
                    TR=TR->right;
            }else if(diff<0){
                for(int j=0;j<-diff;j++)
                    TR=TR->left;
            }
            TR1=TR->blink;
            if(TR1==NULL)
                TR->blink=temp;
            else{
                while(TR1->next!=NULL)
                    TR1=TR1->next;
                TR1->next=temp;
            }
            T=T->next;
            prevind=ind;
        }
        //emptying the buckets into the main list
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
