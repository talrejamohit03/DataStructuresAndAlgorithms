#include <iostream>
using namespace std;

struct mnode{
    int data;
    int cnt;
    mnode *lptrs[5];
};
typedef mnode *MPTR;
struct lnode{
    mnode *data;
    lnode *next;
};
typedef lnode* LPTR;
struct stackn{
    int top;
    mnode *elem[50];
};
void push(stackn s, MPTR M){
    s.elem[++s.top]=M;
}
MPTR pop(stackn s){
    if(s.top==-1)
        cout<<"Stack is empty.";
    else{
        return s.elem[s.top--];
    }
}
MPTR inpT(MPTR &L){
    L=new(mnode);
    cout<<"Enter number of branches(0 to terminate): ";
    cin>>L->cnt;
    if(L->cnt==0)
        return NULL;
    cout<<"Enter data: ";
    cin>>L->data;
    n=L->cnt-1;
    while(n>-1){
        L->lptrs[n]=inpT(L->lptrs[n]);
        n--;
    }
    return L;
}
LPTR findTarget(MPTR M,int x){
    static stackn S;
    static LPTR path=NULL,T;
    S.top=-1;
    if(M->data==x)
        return path;
    if(M==NULL)
        return NULL;
    if(M!=NULL){
        if(M->cnt==1){
            LPTR temp=new(lnode);
            temp->data=M;
            temp->next=NULL;
            if(path==NULL){
                path=temp;
                T=path;
            }else{
                T->next=temp;
                T=T->next;
            }
            T=findTarget(M->lptrs[0],x);
        }else{
            M->cnt--;
            push(S,M);
            LPTR br=T;
            T=findTarget(M->lptrs[M->cnt],x);
            if(T->data->data==x)
                return path;
            else{

            }
        }
    }
/*    if(M->data==x)
        cout<<M->data;
    else if(M!=NULL){
        if(M->cnt==1){
            cout<<M->data<<" ";
            findTarget(M->lptrs[1],x);
        }else{
            M->cnt--;
            push(S,M);
            findTarget(M->lptrs[M->cnt],x);
        }
    }
    else if(M==NULL){
        MPTR temp=pop(S);
        findTarget(temp->lptrs[--temp->cnt],x);
        if(temp->cnt>0)
            push(S,temp);
    }
}*/
int main(){
    MPTR L1=NULL;
    int n;
    L1=inpT(L1);
    cout<<"Enter target element: ";
    cin>>n;
    findTarget(L1,n);
    return 0;
}
