#include <iostream>
using namespace std;
int main(){
    int A[10],n;
    cout<<"Enter the number of students: ";
    cin>>n;
    for(int j=0;j<10;j++)
        A[j]=0;
    for(int i=1;i<=n;i++){
        int mark,j;
        cout<<"Enter marks of student "<<i<<" ";
        cin>>mark;
        if(mark!=100){
            j=mark/10;
            A[j]+=1;
        }else{
            A[9]+=1;
        }
    }
    for(int k=0;k<10;k++){
        for(int m=1;m<=A[k];m++)
            cout<<"*"<<" ";
        cout<<"\n";
    }
    return 0;
}
