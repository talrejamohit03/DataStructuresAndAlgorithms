#include <iostream>
using namespace std;
void fillArr(int L[],int s){
    for(int i=0;i<s;i++){
        cout<<"Enter element "<<i+1<<" ";
        cin>>L[i];
    }
}
int main(){
    int A[50],B[50],C[100];
    int *a,*b,*c,*maxptr,sizea,sizeb,sizemax,sizemin;
    a=A;b=B;c=C;
    cout<<"Enter size of A: ";
    cin>>sizea;
    fillArr(A,sizea);
    cout<<"Enter size of B: ";
    cin>>sizeb;
    fillArr(B,sizeb);
    if(sizea>sizeb){
        sizemin=sizeb;
        sizemax=sizea;
        maxptr=A;
    }else{
        sizemin=sizea;
        sizemax=sizeb;
        maxptr=B;
    }
    for(int i=0;i<sizemin;i++){
        *(c+(2*i))=*(a+i);
        *(c+(2*i+1))=*(b+i);
    }
    int exc=0;
    for(int j=2*sizemin;j<sizea+sizeb;j++){
        *(c+j)= *(maxptr+sizemin+exc);
        exc++;
    }
    cout<<"Array C is:\n";
    for(int m=0;m<sizea+sizeb;m++)
        cout<<*(c+m)<<" ";
    return 0;
}
