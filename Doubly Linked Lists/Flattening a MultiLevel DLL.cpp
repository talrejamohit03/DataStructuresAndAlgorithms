#include <iostream>

using namespace std;

typedef
struct dnode{
    dnode *left;
    int data;
    dnode *right;
    dnode *dlink;
} *DPTR;

DPTR inpD(DPTR &L){
    DPTR temp=new(dnode),T=L;
    int n;
    cout<<"Enter data: (-1 to terminate) ";
    cin>>n;
    if(n==-1)
        return NULL;
    else{
        temp->data=n;
        temp->left=NULL;
        temp->right=NULL;
        temp->dlink=NULL;
    }
    char c;
    cout<<"Do you want a down link?(y/n) ";
    cin>>c;
    if(c=='y'){
        temp->dlink=inpD(temp);
    }
    if(L==NULL){
        L=temp;
        T=L;
        T=inpD(L);
        return L;
    }else{
        T->right=temp;
        temp->left=T;
        T=T->right;
        T->right=inpD(T);
        return T;
    }
}
void flatten(DPTR L){
    if(L==NULL)
        return;
    cout<<L->data<<" ";
    flatten(L->dlink);
    flatten(L->right);
}
int main(){
    DPTR L1=NULL;
    inpD(L1);
    flatten(L1);
}
