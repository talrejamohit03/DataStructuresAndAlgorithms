#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements: \n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=1;i<n;i++){
        int key=arr[i],j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}
