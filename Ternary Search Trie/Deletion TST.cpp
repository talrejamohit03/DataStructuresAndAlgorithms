#include <iostream>
#include <cstring>
using namespace std;

struct tstnode{
    char data;
    bool bit;
    tstnode *lchild;
    tstnode *echild;
    tstnode *rchild;
    int space;//for printing TST as it is
};
typedef tstnode *TSTPTR;

typedef
struct lnode{
    TSTPTR data;
    lnode *next;
} *LPTR;

struct bst_queue{
    LPTR f;
    LPTR r;
};
typedef bst_queue *QPTR;

void bst_sort(TSTPTR T,int &c){
    if(T!=NULL){
        bst_sort(T->lchild,c);
        T->space=c+1;
        bst_sort(T->echild,c);
        c++;
        bst_sort(T->rchild,c);
    }
}
void bst_enq(QPTR &Q,TSTPTR T){
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
TSTPTR bst_deq(QPTR Q){
    if(Q->f==NULL)
        return NULL;
    LPTR temp=Q->f;
    if(Q->r==Q->f){
        Q->f=NULL;
        Q->r=NULL;
    }else{
        Q->f=Q->f->next;
    }
    return temp->data;
}

void createTST(TSTPTR &T,char word[],int i=0){
    if(word[i]=='\0')
        return;
    if(T==NULL){
        T=new(tstnode);
        T->data=word[i];
        T->lchild=NULL;
        T->echild=NULL;
        T->rchild=NULL;
        T->bit=0;
    }
    if(T->data==word[i])
        createTST(T->echild,word,i+1);
    else if(word[i]<T->data)
        createTST(T->lchild,word,i);
    else if(word[i]>T->data)
        createTST(T->rchild,word,i);
    if(word[i+1]=='\0'){
        T->bit=1;
        return;
    }
}
void deleteTST(TSTPTR &T,char word[],int i=0){
    if(T==NULL){
        cout<<"Word not found.\n";
        return;
    }
    if(word[i]<T->data)
        deleteTST(T->lchild,word,i);
    else if(word[i]>T->data)
        deleteTST(T->rchild,word,i);
    else if(T->data==word[i]){
        if(word[i+1]!='\0')
            deleteTST(T->echild,word,i+1);
        else
            T->bit=0;
        if(T->echild==NULL&&T->bit==0){//this means the node must be deleted
            TSTPTR temp=T->rchild;
            if(T->lchild!=NULL){
                T=T->lchild;
                T->rchild=temp;
            }else
                T=temp;
        }
    }
}
void printwords(TSTPTR T,int i=0){
    static char word[10];
    if(T!=NULL){
        printwords(T->lchild,i);
        word[i]=T->data;
        if(T->bit==1){
            word[i+1]='\0';
            cout<<word<<" ";
        }
        printwords(T->echild,i+1);
        printwords(T->rchild,i);
    }
}
void treeprint_asitis(TSTPTR T1){
    TSTPTR tag=new(tstnode),T2=NULL;
    int nn=0;//number of nodes
    bst_sort(T1,nn);
    QPTR Q1=new(bst_queue);
    Q1->f=NULL;
    Q1->r=NULL;
    tag->data='.';
    tag->lchild=NULL;
    tag->rchild=NULL;
    bst_enq(Q1,T1);
    bst_enq(Q1,tag);
    int prevsp=0,levsp=0,felem=1;
    while(Q1->f!=NULL){
        T2=bst_deq(Q1);
        if(T2->data=='.'){
            cout<<"\n\n";
            bst_enq(Q1,T2);
            prevsp=levsp;
            felem=1;
            continue;
        }
        for(int i=0;i<T2->space-prevsp;i++)
            cout<<" ";
        if(felem){
            levsp=T2->space;
            felem=0;
        }
        cout<<T2->data;
        if(T2->lchild!=NULL)
            bst_enq(Q1,T2->lchild);
        if(T2->echild!=NULL)
            bst_enq(Q1,T2->echild);
        if(T2->rchild!=NULL)
            bst_enq(Q1,T2->rchild);
        prevsp=T2->space;
        if(Q1->f->data==tag&&Q1->r->data==tag)
            break;
    }
}
int main(){
    //in as at be by he is it of on or to asm ae atd .
    TSTPTR T1=NULL;
    char word1[10];
    cout<<"Enter words (. to terminate): ";
    cin>>word1;
    while(strcmp(word1,".")){
        createTST(T1,word1);
        cin>>word1;
    }
    treeprint_asitis(T1);
    cout<<endl;
    printwords(T1);
    cout<<"\nEnter element to delete: (. to terminate) ";
    cin>>word1;
    while(strcmp(word1,".")){
        deleteTST(T1,word1);
        treeprint_asitis(T1);
        cout<<"\nEnter next element to be deleted: ";
        cin>>word1;
    }
    return 0;
}
