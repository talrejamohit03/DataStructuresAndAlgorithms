#include <iostream>
using namespace std;
typedef
struct dnode{
    struct dnode *left;
    int data;
    struct dnode *right;
}*DPTR;

void inpD(DPTR &D){
    DPTR T;
    int n;
    cout<<"Enter data(-1 to terminate): ";
    cin>>n;
    while(n!=-1){
        DPTR temp;
        temp=new(dnode);
        temp->data=n;
        temp->left=NULL;
        temp->right=NULL;
        if(D==NULL){
            D=temp;
            T=D;
        }
        else{
            T->right=temp;
            temp->left=T;
            T=T->right;
        }

        cout<<"Enter data(-1 to terminate): ";
        cin>>n;
    }
}
void printD(DPTR D){
    while(D!=NULL){
        cout<<D->data<<" ";
        D=D->right;
    }
}
void ins_bef(DPTR D,int x,int y){
    DPTR temp;
    temp->data=x;
    while(D->data!=y)
        D=D->right;
    D->left->right=temp;
    temp->left=D->left;
    temp->right=D;
    D->left=temp;
}
void del_front(DPTR &D){
    D->right->left=NULL;
    D=D->right;
}
void del_back(DPTR D){
    while(D->right!=NULL)
        D=D->right;
    D->left->right=NULL;
}
void del(DPTR D,int x){
    while(D->data!=x)
        D=D->right;
    D->left->right=D->right;
    D->right->left=D->left;
}
int main(){
    DPTR D1=NULL;
    inpD(D1);
    printD(D1);
    cout<<"Deleting Front: \n";
    del_front(D1);
    printD(D1);
    cout<<"Inserting 4 before 9: \n";
    ins_bef(D1,4,9);
    printD(D1);
    cout<<"Deleting back: \n";
    del_back(D1);
    printD(D1);
    cout<<"Deleting 4: ";
    del(D1,4);
    printD(D1);
    return 0;
}

