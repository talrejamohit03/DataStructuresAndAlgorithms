#include <iostream>
using namespace std;

void swap(int *x, int &y){
    int t;
    t=*x;
    *x=y;
    y=t;
    cout<<*x<<y;
}

int main(){
    int a=3, b=5;
    swap(&a,b);
    cout<<a<<b;
}

