#include <iostream>

using namespace std;

union u{
    char c;
    struct mlnode *dlink;
};
struct mlnode{
    union u data;
    mlnode *next;
    int tag;
};
typedef mlnode *MPTR;

 MPTR inpML(MPTR &M){
    MPTR temp=new(mlnode),T=M;
    cout<<"Enter tag(1-char, 2-down link,-1 to terminate downlink): ";
    cin>>temp->tag;
    temp->next=NULL;
    if(temp->tag==1){
        cout<<"Enter character: ";
        cin>>(temp->data).c;
    }
    else if(temp->tag==2){
        (temp->data).dlink=inpML(temp);
        T->next=temp;
        T=T->next;
        T->next=inpML(T);
        return T;
    }
    //see extended question for shorter code for this part
    if(temp->tag==-1){
        return NULL;
    }
    if(M==NULL){
        M=temp;
        T=M;
        inpML(T);
        return M;
    }else if(M!=NULL){
        temp->next=inpML(temp);
        if(T->tag==2)
            return temp;
        else{
            T->next=temp;
            return temp;
        }

    }
 }
 void outML(MPTR M){
    if(M==NULL)
        cout<<"}";
    else if(M->tag==1){
        cout<<(M->data).c<<" ";
        outML(M->next);
    }else if(M->tag==2){
        cout<<"{";
        outML((M->data).dlink);
        outML(M->next);
    }
 }
int main(){
    MPTR M=NULL;
    inpML(M);
    cout<<"{";
    outML(M);
}
