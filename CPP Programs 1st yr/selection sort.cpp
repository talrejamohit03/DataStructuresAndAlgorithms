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
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(A[j]<A[i]){
                temp=A[j];
                A[j]=A[i];
                A[i]=temp;
            }
        }
    }
    for(int m=0;m<size;m++){
        cout<<A[m]<<" ";
    }
    return 0;
}
