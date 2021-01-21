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
//cflag is a flag for the siblings of the same parent that becomes true if any 1 child has children
void vertical_print(TPTR T,int cnt=0,bool cflag=0){
    if(T!=NULL){
        cout<<T->data<<" ";
        if(T->fc!=NULL){
            cout<<"\n";
            cflag=1;
            for(int i=0;i<cnt+1;i++)
                cout<<" ";
        }
        vertical_print(T->fc,cnt+1,0);
        if(cflag&&T->ns!=NULL){
            cout<<"\n";
            for(int i=0;i<cnt;i++)
                cout<<" ";
        }
        vertical_print(T->ns,cnt,cflag);
    }
}
int main(){
    //A B L P . Q . R . S . . C . D . . M E . F . . J H I O . N . . . . K . T . . .
    TPTR T1=NULL;
    char k1;
    cout<<"Enter keys: ";
    cin>>k1;
    ins_gt(T1,k1);
    vertical_print(T1);
    return 0;
}
