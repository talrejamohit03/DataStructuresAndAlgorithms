#include <bits/stdc++.h>
using namespace std;

int partition(int arr[],int low,int high){
    int pivot=arr[low];
    int l=low+1,h=high;
    while(l<h){
        while(l<=high&&arr[l]<=pivot)l++;
        while(h>low&&arr[h]>=pivot)h--;
        if(l<h){
            swap(arr[l],arr[h]);
        }
    }
    if(pivot>=arr[h])
        swap(arr[low],arr[h]);
    return h;
}
void quickSort(int arr[],int low,int high){
    if(low<high){
        int j=partition(arr,low,high);
        quickSort(arr,low,j-1);
        quickSort(arr,j+1,high);
    }
}
int main(){
    int arr[5]={23,19,19,12,30};
    quickSort(arr,0,4);
    for(int i=0;i<5;i++)
        cout<<arr[i]<<" ";
}
