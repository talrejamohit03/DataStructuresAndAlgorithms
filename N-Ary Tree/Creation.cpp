#include <iostream>
using namespace std;

typedef
struct ntnode{
    int data;
    ntnode *ptrs[10];
}*NPTR;

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
void deserealize(NPTR T,int n){
	if(T==NULL)
		return;
	cout<<T->data<<" ";
	for(int i=0;i<n;i++){
		if(T->ptrs[i]==NULL){
			cout<<-1<<" ";
			break;
		}
		deserealize(T->ptrs[i],n);
	}
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
    deserealize(T1,n);
	return 0;
}
