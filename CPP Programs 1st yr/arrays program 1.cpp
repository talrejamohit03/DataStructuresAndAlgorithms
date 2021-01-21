#include <iostream>
using namespace std;

int main(){
    int n,sum=0;
    cout<<"enter the number of elements in the array: ";
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++){
        cout<<"\nenter element: ";
        cin>>A[i];
    }
    for(int i=n-1;i>=0;i--){
        cout << A[i] << " ";
        sum+=A[i];
    }
    cout<<"Sum of elements is: "<<sum;
}
