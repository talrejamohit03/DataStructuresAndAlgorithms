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
int clicks(TPTR T,int currlev=0){
    if(T!=NULL){
        int nch=0;
        TPTR chld=T->fc;
        while(chld!=NULL){
            nch++;
            chld=chld->ns;
        }
        return max(nch+currlev,max(clicks(T->fc,currlev+1),clicks(T->ns,currlev)));
    }
    return 0;
}
int main(){
    //A B L P . Q . R . S . . C . D . . M E . F . . J H I O . N . . . . K . T . . .
    //answer 6
    //A B L . C . D . . M E . F . . J H I O . N . . . . K . T . . .
    //answer 5
    TPTR T1=NULL;
    char k1;
    cout<<"Enter keys: ";
    cin>>k1;
    ins_gt(T1,k1);
    cout<<"Number of clicks: "<<clicks(T1);
    return 0;
}
