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
int cnode(LPTR L){
    if(L==NULL)
        return 0;
    else
        return 1+cnode(L->next);
}
struct snode{
    int data;
    snode *next;
};
typedef snode* SPTR;
void push(SPTR &S,int x){
    SPTR temp;
    temp=new(snode);
    temp->data=x;
    temp->next=S;
    S=temp;
}
int pop(SPTR &S){
    if(S==NULL){
        cout<<"Stack is empty.";
        return NULL;
    }
    else{
        SPTR temp;
        temp=S;
        S=S->next;
        return temp->data;
    }
}
void palindLL(LPTR midplus,SPTR &S){
    if(midplus->data!=pop(S)){
        cout<<"Not palindrome.";
        return;
    }
    if(S==NULL){
        cout<<"Palindrome";
        return;
    }
    palindLL(midplus->next,S);
}
int main(){
    LPTR L1=NULL;
    inpLL(L1);
    LPTR s=L1,f=L1;
    int l=cnode(L1);
    SPTR S1;
    S1=NULL;
    if(l%2!=0){
        while(f->next!=NULL){
            push(S1,s->data);
            s=s->next;
            f=f->next->next;
        }
         s=s->next;
    }else{
        while(f!=NULL){
            push(S1,s->data);
            s=s->next;
            f=f->next->next;
        }
    }
    int flag=1;
    /*while(s->next!=NULL){
        if(pop(S1)!=s->data){
            flag=0;
            cout<<"Not palindrome.";
            break;
        }
        s=s->next;
    }
    if(flag==1)
        cout<<"palindrome";*/ //iterative method
    palindLL(s,S1);
    return 0;
}
