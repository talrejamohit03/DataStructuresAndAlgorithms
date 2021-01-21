#include <iostream>
using namespace std;

typedef
struct gtnode{
    gtnode *fc;//first child
    char data;
    gtnode *ns;//next sibling
}*TPTR;
TPTR ins_gt(TPTR &T,char k){
    if(k=='.')
        return NULL;
    if(T==NULL){
        T=new(gtnode);
        T->data=k;
        T->fc=NULL;
        T->ns=NULL;
    }
    char k1;
    cin>>k1;
    T->fc=ins_gt(T->fc,k1);
//    if(T->fc!=NULL)
//        cout<<T->fc->data<<" ";
    cin>>k1;
    T->ns=ins_gt(T->ns,k1);
//    if(T->ns!=NULL)
//        cout<<T->ns->data<<" ";
    return T;
}
int depth(TPTR T){
    if(T==NULL)
        return -1;
    int dep=0;
    TPTR sib=T;
    while(sib!=NULL){
        int currdep=1+depth(sib->fc);
        if(currdep>dep)
            dep=currdep;
        sib=sib->ns;
    }
    return dep;
}
int main(){
    //A B L P . Q . R . S . . C . D . . M E . F . . J H I O . N . . . . K . T . . .
    //answer 4
    //A B L P . Q . R . S . . C . D . . M E . F . . J H I . . . K . T . . .
    //answer 3
    TPTR T1=NULL;
    char k1;
    cout<<"Enter keys: ";
    cin>>k1;
    ins_gt(T1,k1);
    cout<<"Depth: "<<depth(T1);
    return 0;
}
