#include <iostream>
using namespace std;

int main(){
    int A[50],size=0,v,i,j;
    cout<<"Enter size of array(less than 50): ";
    cin>>size;
    cout<<"Enter the elements: ";
    for(int j=0;j<size;j++){
        cout<<"Enter element "<<j+1<<" : ";
        cin>>A[j];
    }
    for(i=1;i<size;i++){
        j=i-1;
        v=A[i];
        while (A[j]>v&&j>=0){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=v;
    }
    for(int m=0;m<size;m++){
        cout<<A[m]<<" ";
    }
    return 0;
}
