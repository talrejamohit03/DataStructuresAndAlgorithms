#include <iostream>
using namespace std;

class Matrix{
    public:
        Matrix();
        Matrix(const Matrix &obj);
        int inverse();
        int det();
        bool isSingular();
        void print();
        int M[2][2];
};
Matrix::Matrix(){
    cout<<"Constructor initiated.\n";
}
Matrix::Matrix(const Matrix &obj){
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++)
            M[i][j]=obj.M[i][j];
    }
}
int Matrix::det(){
    return M[0][0]*M[1][1]-M[0][1]*M[1][0];
}
int Matrix::inverse(){
    double temp[2][2];
    int val=det();
    if(val==0){
        cout<<"\nInverse does not exist!!!";
        return 0;
    }
    temp[0][0]=M[1][1];
    temp[1][1]=M[0][0];
    temp[0][1]=-M[1][0];
    temp[1][0]=-M[0][1];
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            temp[i][j]/=val;
            cout<<temp[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
bool Matrix::isSingular(){
    if(det())
        return 1;
    return 0;
}
void Matrix::print(){
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++)
            cout<<M[i][j]<<" ";
        cout<<endl;
    }
}
int main(){
    Matrix mo;
    cout<<"Enter matrix: ";
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            cout<<"Enter element ("<<i<<","<<j<<") ";
            cin>>mo.M[i][j];
        }
    }
    cout<<"\nMatrix entered is: \n";
    mo.print();
    cout<<"\nDeterminant = "<<mo.det();
    cout<<"\nInverse matrix is: \n";
    mo.inverse();
    if(mo.isSingular())
        cout<<"\nMatrix is not Singular.";
    else
        cout<<"\nMatrix is singular.";
    Matrix cop(mo);
    cout<<"\nCopied matrix using copy constructor\n";
    cop.print();
    return 0;
}
