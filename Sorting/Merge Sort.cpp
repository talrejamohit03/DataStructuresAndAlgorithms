#include <iostream>
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
	cout<<"Enter elements(-1 to terminate): ";
	cin>>a;
	while(a!=-1){
		arr[n++]=a;
		cin>>a;
	}
	merge_sort(arr,n);
	cout<<"Sorted Array\n";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	return 0;
}
