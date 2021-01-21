#include <iostream>
using namespace std;

typedef
struct btnode{
	char data;
	btnode *lchild;
	btnode *rchild;
} *BTPTR;
typedef
struct gtnode{
    gtnode *fc;//first child
    char data;
    gtnode *ns;//next sibling
    bool flag;
}*TPTR;
typedef
struct lnode{
    BTPTR data;
    lnode *next;
} *LPTR;

struct bst_queue{
    LPTR f;
    LPTR r;
};
typedef bst_queue *QPTR;
void bst_enq(QPTR &Q,BTPTR T){
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
BTPTR bst_deq(QPTR Q){
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
        T->flag=0;
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
void treeprintlevel_BT(BTPTR T){
    BTPTR tag=new(btnode);
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
        if(T->lchild!=NULL)
        	bst_enq(Q1,T->lchild);
        if(T->rchild!=NULL)
        	bst_enq(Q1,T->rchild);
    }
}
BTPTR GT_BT(TPTR T){
	if(T==NULL||T->flag)
		return NULL;
	BTPTR Tb=new(btnode);
	Tb->data=T->data;
	T->flag=1;
	//cout<<Tb->data<<" ";
	Tb->lchild=NULL;
	Tb->rchild=NULL;
	TPTR T1=T->fc;
	bool lflag=1;
	while(T1!=NULL){
		if(!T1->flag){
			if(lflag){
				Tb->lchild=GT_BT(T1);
				lflag=0;
				T1=T1->ns;
				continue;
			}
			Tb->rchild=GT_BT(T1);
			break;
		}
		T1=T1->ns;
	}
	T1=T->fc;
	while(T1!=NULL){
		if(T1->flag==0){
			T->flag=0;
			break;
		}
		T1=T1->ns;
	}
	//cout<<T->data<<T->flag<<"ret ";
	return Tb;
}
void allBTs(TPTR T){
	BTPTR B=GT_BT(T);
	treeprintlevel_BT(B);
	while(!T->flag){
		B=GT_BT(T);
		treeprintlevel_BT(B);
	}
}
int main(){
    //A B M . J R . S . T . . Q . . C P E . F . G . . . D H . I . . . .
    TPTR T1=NULL;
    char k1;
    cout<<"Enter keys: ";
    cin>>k1;
    ins_gt(T1,k1);
    allBTs(T1);
    return 0;
}
