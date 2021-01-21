#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void merge(int L[],int R[],int A[],int nL,int nR){
	int i=0,j=0,k=0;
	while(i<nL&&j<nR){
		if(L[i]<=R[j])
			A[k++]=L[i++];
		else
			A[k++]=R[j++];
	}
	while(i<nL)
		A[k++]=L[i++];
	while(j<nR)
		A[k++]=R[j++];
}
void merge_sort(int A[],int n){
	if(n<2)
		return;
	int mid=n/2;
	int left[mid],right[n-mid];
	for(int i=0;i<=mid-1;i++)
		left[i]=A[i];
	for(int i=mid;i<n;i++)
		right[i-mid]=A[i];
	merge_sort(left,mid);
	merge_sort(right,n-mid);
	merge(left,right,A,mid,n-mid);
}
int main(){
	int a,n=0,arr[50];
	ifstream fin("input.txt"),f3("output3.txt"),f4("output4.txt");
	ofstream f1("output1.txt"),f2("output2.txt");
	bool flag=1;
	char ch;
	while(!fin.eof()){
		fin>>ch;
		while(ch!='\n'){
			if(flag)
				f1<<ch<<" ";
			else
				f2<<ch<<" ";
			fin>>ch;
		}
		if(flag){
			f1<<"\n";
			flag=0;
		}else{
			f2<<"\n";
			flag=1;
		}
	}
	int A[3],B[3],C[3],i=0,j=0,k=0;
	char ch1,ch2;
	f1>>ch1;f2>>ch2;
	while(ch1!='\n'&&ch2!='\n'){
		A[i++]=atoi(ch1);
		B[j++]=atoi(ch2);
	}
	merge_sort(A,3);
	merge_sort(B,3);
	merge(A,B,C,3,3);
	cout<<"Sorted Array\n";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	return 0;
}
