#include <iostream>
#include <string>
using namespace std;
struct lnode{
    string data;
    lnode *next;
};
typedef lnode* LPTR;

void inpLL(LPTR &L){
    LPTR T;
    string n,st="*";
    cout<<"New Linked List\n";
    cout<<"Enter element (* to terminate): ";
    cin>>n;
    while(n!=st){
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
       cout<<"Enter next element (* to terminate): ";
       cin>>n;
    }
}
void palindromeLL(LPTR L){
    string sent="",rev;
    while(L!=NULL){
        sent+=L->data;
        L=L->next;
    }
    rev=sent;
    int l=0,h=sent.length()-1;
    while(l!=h){
        char t=rev[l];
        rev[l]=rev[h];
        rev[h]=t;
        l++;h--;
    }
    if(rev==sent)
        cout<<"Palindrome";
    else
        cout<<"Not palindrome";
}
int main(){
    LPTR L1;
    inpLL(L1);
    palindromeLL(L1);
}
