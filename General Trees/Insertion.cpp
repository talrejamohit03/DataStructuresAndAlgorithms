#include <iostream>
using namespace std;

typedef
struct gtnode{
    gtnode *fc;//first child
    char data;
    gtnode *ns;//next sibling
}*TPTR;
typedef
struct lnode{
    TPTR data;
    lnode *next;
} *LPTR;

struct bst_queue{
    LPTR f;
    LPTR r;
};
typedef bst_queue *QPTR;
void bst_enq(QPTR &Q,TPTR T){
    LPTR temp=new(lnode);
    temp->data=T;
    temp->next=NULL;
    if(Q->f==NULL){
        Q->f=temp;
        Q->r=temp;
    }else{
        Q->r->next=temp;
        Q->r=Q->r->next;
    }
}
TPTR bst_deq(QPTR Q){
    if(Q->f==NULL)
        return NULL;
    LPTR temp=Q->f;
    if(Q->r==NULL){
        Q->f=NULL;
        Q->r=NULL;
    }else{
        Q->f=Q->f->next;
    }
    return temp->data;
}
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
void treeprintlevel(TPTR T){
    TPTR tag=new(gtnode);
    QPTR Q1=new(bst_queue);
    Q1->f=NULL;
    Q1->r=NULL;
    tag->data='.';
    bst_enq(Q1,T);
    bst_enq(Q1,tag);
    while(Q1->f!=NULL){
        T=bst_deq(Q1);
        if(T->data=='.'){
            cout<<"\n";
            if(Q1->f==NULL)
                break;
            bst_enq(Q1,T);
            continue;
        }
        cout<<T->data<<" ";
        TPTR temp=T->fc;
        while(temp!=NULL){
            bst_enq(Q1,temp);
            temp=temp->ns;
        }
    }
}
void prbracesGT(TPTR T){
    if(T!=NULL){
        cout<<T->data<<" ";
        if(T->fc!=NULL)
            cout<<"{";
        prbracesGT(T->fc);
        if(T->ns==NULL)
            cout<<"}";
        prbracesGT(T->ns);
        return;
    }
}
int main(){
    //A B I . K R . S T . . . . M L . C . D . . J . P N . G . . . .
    TPTR T1=NULL;
    char k1;
    cout<<"Enter keys: ";
    cin>>k1;
    ins_gt(T1,k1);
    treeprintlevel(T1);
    cout<<"\n{";
    prbracesGT(T1);
    return 0;
}
