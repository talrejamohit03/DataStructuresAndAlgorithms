#include <iostream>
using namespace std;

int main(){
    int A[50],size=0,temp;
    cout<<"Enter size of array(less than 50): ";
    cin>>size;
    cout<<"Enter the elements: ";
    for(int j=0;j<size;j++){
        cout<<"Enter element "<<j+1<<" : ";
        cin>>A[j];
    }
    for(int i=size-1;i>0;i--){
        for(int j=0;j<=i;j++){
            if(A[j]>A[j+1]){
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
        }
    }
    for(int m=0;m<size;m++){
        cout<<A[m]<<" ";
    }
    return 0;
}
