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

MPTR inpML(char ln[],MPTR &M,MPTR lp[]){
    MPTR temp=new(mlnode),T=M;
    cout<<"Enter tag(1-char, 2-down link,-1 to terminate downlink): ";
    cin>>temp->tag;
    temp->next=NULL;
    if(temp->tag==1){
        cout<<"Enter character: ";
        cin>>(temp->data).c;
        if((temp->data).c>='A'&&(temp->data).c<='Z'){
            temp->tag=2;
            int j=0;
            while(ln[j]!=(temp->data).c)
                j++;
            if(lp[j]==NULL){
                cout<<"Enter "<<ln[j]<<endl;
                lp[j]=inpML(ln,lp[j],lp);
            }
            (temp->data).dlink=lp[j];
        }
    }
    else if(temp->tag==2){
        (temp->data).dlink=inpML(ln,temp,lp);
    }
    if(temp->tag==-1)
        return NULL;
    if(M==NULL){
        M=temp;
        T=M;
        inpML(ln,T,lp);
        return M;
    }else{
        T->next=temp;
        T=T->next;
        T->next=inpML(ln,T,lp);
        return T;
    }
 }
 void outML(MPTR M){
    if(M==NULL)
        cout<<"} ";
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
    int n;
    cout<<"Enter number of lists: ";
    cin>>n;
    char lname[n];
    MPTR lptrs[n];
    cout<<"Enter the names: ";
    for(int i=0;i<n;i++){
        cin>>lname[i];
        lptrs[i]=NULL;
    }
    cout<<"Enter for list "<<lname[0]<<endl;
    inpML(lname,lptrs[0],lptrs);
    cout<<"{";
    outML(lptrs[0]);
}
