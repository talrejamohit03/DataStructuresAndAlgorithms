#include <iostream>
using namespace std;

typedef
struct ntnode{
    int data;
    ntnode *ptrs[10];
}*NPTR;
typedef
struct btnode{
	int data;
	btnode *lchild;
	btnode *rchild;
}*BTPTR;
void serealize(NPTR &T,int k,int n){
	T=new(ntnode);
	T->data=k;
	int k2;
	for(int i=0;i<n;i++){
		T->ptrs[i]=NULL;
		cin>>k2;
		if(k2==-1)
			break;
		serealize(T->ptrs[i],k2,n);
	}
}
BTPTR NT_BT(NPTR T,NPTR Tp,int n,int i=0){
	if(T==NULL||i>=n)
		return NULL;
	BTPTR B=new(btnode);
	B->data=T->data;
	B->lchild=NULL;
	B->rchild=NULL;
	B->lchild=NT_BT(T->ptrs[0],T,n);
	if(Tp!=NULL)
		B->rchild=NT_BT(Tp->ptrs[i+1],Tp,n,i+1);
	return B;
}
void deserealize_BT(BTPTR T){
    if(T!=NULL){
        cout<<T->data<<" ";
        deserealize_BT(T->lchild);
        deserealize_BT(T->rchild);
    }else
        cout<<". ";
}
int main(){
	//1 2 6 -1 7 -1 -1 3 8 -1 -1 4 -1 5 9 -1 10 -1 11 -1 -1 -1
    int n,k1;
    cout<<"Enter n: ";//n is the max number of children a node can have
    cin>>n;
    NPTR T1=NULL;
    cout<<"Enter sereal order: ";
    cin>>k1;
	serealize(T1,k1,n);
	BTPTR B1=NT_BT(T1,NULL,n);
	deserealize_BT(B1);
	return 0;
}
