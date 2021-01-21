#include <iostream>
using namespace std;

int main(){
    int A[50][50],n;
    cout<<"Enter the size of the matrix: ";
    cin>>n;
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
                cout<<"Enter element "<<i<<","<<j<<" ";
                cin>>A[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<A[i][j]<<" ";
        }
        cout<<"\n";
    }
    int sumd=0;
    cout<<"The upper triangular matrix is: \n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                sumd+=A[i][j];
            }
            if(j>=i){
                cout<<A[i][j]<<" ";
            }else{
                cout<<"  ";
            }
        }
        cout<<"\n";
    }
    cout<<"Sum of the diagonal elements is: "<<sumd;
    return 0;
}
