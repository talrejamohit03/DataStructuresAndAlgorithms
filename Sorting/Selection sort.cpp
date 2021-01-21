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
    for(int i=0;i<n-1;i++){
        int m=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[m])
                m=j;
        }
        swap(arr[i],arr[m]);
    }
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}
