#include <iostream>
#include <cstring>
using namespace std;

const int alp=3;

typedef struct trie *TRPTR;
union u{
    TRPTR ptr[alp+1];
    char key[10];
};
struct trie{
    union u data;
    int tag;
    int order;//for printing tree as it is
};
typedef
struct lnode{
    TRPTR data;
    lnode *next;
} *LPTR;

struct bst_queue{
    LPTR f;
    LPTR r;
};
typedef bst_queue *QPTR;
void bst_enq(QPTR &Q,TRPTR T){
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
TRPTR bst_deq(QPTR Q){
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
int orderassign(TRPTR T,int &sp){//for as it is printing
    if(T!=NULL){
        T->order=sp++;
        if(T->tag==2)
            T->order=T->order+strlen(T->data.key);
        if(T->tag==1){
            T->order=T->order+2*alp+2;
            int tempsp;
            for(int j=0;j<alp+1;j++)
                tempsp=orderassign(T->data.ptr[j],sp);
            return tempsp;
        }
    }
    return sp;
}
void createTrie(TRPTR &T,char word[],int i=0){
    if(T==NULL){
        T=new(trie);
        T->tag=2;
        strcpy(T->data.key,word);
    }else{
        if(T->tag==1)
            createTrie(T->data.ptr[word[i]-'a'],word,i+1);
        else{
            char tempword[10];
            strcpy(tempword,T->data.key);
            T->tag=1;
            for(int j=0;j<alp+1;j++)
                T->data.ptr[j]=NULL;
            if(tempword[i]=='\0')
                createTrie(T->data.ptr[alp],tempword,i+1);
            else
                createTrie(T->data.ptr[tempword[i]-'a'],tempword,i);
            if(word[i]=='\0')
                createTrie(T->data.ptr[alp],word,i+1);
            else
                createTrie(T->data.ptr[word[i]-'a'],word,i+1);
        }
    }
}
void trieprintasitis(TRPTR T){
    TRPTR T2,tag=new(trie);
    QPTR Q1=new(bst_queue);
    Q1->f=NULL;
    Q1->r=NULL;
    tag->tag=-1;
    int nnodes=1;
    nnodes=orderassign(T,nnodes);
    int prevsp=-nnodes/2;
    bst_enq(Q1,T);
    bst_enq(Q1,tag);
    while(Q1->f!=NULL){
        T2=bst_deq(Q1);
        if(T2->tag==-1){
            cout<<"\n\n";
            prevsp=0;
            if(Q1->f==NULL)
                break;
            bst_enq(Q1,T2);
            continue;
        }
        for(int s=0;s<T2->order-prevsp;s++)
            cout<<" ";
        if(T2->tag==1){
            cout<<"(";
            for(int i=0;i<alp+1;i++){
                char c='a'+i;
                if(i!=alp)cout<<c<<".";
                if(T2->data.ptr[i]!=NULL)
                    bst_enq(Q1,T2->data.ptr[i]);
            }
            cout<<")";
        }else
            cout<<T2->data.key<<" ";
        prevsp=T2->order;
    }
}
void deletetrnode(TRPTR &T,TRPTR Tp,char word[],int i=0){
    if(T==NULL){
        cout<<"Key not found\n";
        return;
    }
    if(T->tag==2){
        if(strcmp(T->data.key,word)){
            cout<<"Key not found\n";
            return;
        }
        T=NULL;
        return;
    }else{
        if(word[i]=='\0')
            deletetrnode(T->data.ptr[alp],T,word,i+1);
        else
            deletetrnode(T->data.ptr[word[i]-'a'],T,word,i+1);
    }
    int flag=2;
    TRPTR link=NULL;
    for(int j=0;j<alp+1;j++){
        if(T->data.ptr[j]!=NULL&&flag==1){
            flag=0;//2 data nodes are present hence this node must not be deleted
            break;
        }
        if(T->data.ptr[j]!=NULL){
            flag=1;//case when only 1 node is present is true
            link=T->data.ptr[j];
        }
    }
    if(flag==2)
        T=NULL;
    else if(flag==1)
        T=link;
        //Tp->data.ptr[link->data.key[i-1]-'a']=link;
}
int main(){
    //aab abbbc baa bccaa bc cabb abb cabbc .
    TRPTR T1=new(trie);
    //first node must be an index node
    T1->tag=1;
    for(int j=0;j<alp+1;j++)
        T1->data.ptr[j]=NULL;
    char word1[10];
    cout<<"Enter elements: (. to terminate) ";
    cin>>word1;
    while(strcmp(word1,".")){
        createTrie(T1,word1);
        cin>>word1;
    }
    trieprintasitis(T1);
    cout<<"\nEnter element to delete(. to terminate): ";
    cin>>word1;
    while(strcmp(word1,".")){
        deletetrnode(T1,NULL,word1);
        trieprintasitis(T1);
        cout<<"\nEnter next element to delete: ";
        cin>>word1;
    }
    return 0;
}
