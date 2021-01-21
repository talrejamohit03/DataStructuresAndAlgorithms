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
void addbefore(LPTR L,int x,int y){
    LPTR temp,T;
    T=L;
    temp=new(lnode);
    temp->data=y;
    while(T->next->data!=x)
        T=T->next;
    temp->next=T->next;
    T->next=temp;
}
void del(LPTR L,int x){
    LPTR T;
    T=L;
    while(T->next->data!=x)
        T=T->next;
    T->next=T->next->next;
}
void addfront(LPTR &L,int n){
    LPTR T;
    T=new(lnode);
    T->data=n;
    T->next=L;
    L=T;
}
void addafter(LPTR L,int x,int y){
    LPTR temp,T;
    T=L;
    temp=new(lnode);
    temp->data=y;
    while(T->data!=x)
        T=T->next;
    temp->next=T->next;
    T->next=temp;
}
void addend(LPTR &L,int x){
    LPTR temp,T;
    T=L;
    temp=new(lnode);
    temp->data=x;
    temp->next=NULL;
    if(L==NULL)
        L=temp;
    else{
        while(T->next!=NULL)
            T=T->next;
        T->next=temp;
    }
}
int main(){

    LPTR L,T,T1;
    L=NULL;
    int n;
    cout<<"Enter elements -1 to stop entering: ";
    cin>>n;
    do{
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
       cout<<"Enter elements -1 to stop entering: ";
       cin>>n;
    }while(n!=-1);
    T1=L;
    //del(L,16);
    //addafter(L,18,13);
    cout<<"Length: "<<cnode(T1);
    while(L!=NULL){
        cout<<L->data<<" ";
        L=L->next;
    }
    return 0;
}
