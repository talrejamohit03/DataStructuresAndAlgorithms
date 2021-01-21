#include<iostream>
#include<cstdlib>
using namespace std;
int main(){
    unsigned int s;
    cout<<"Enter a positive number for the seed: ";
    cin>>s;
    srand(s);
    for(int i=1;i<=10;i++)
        cout<<rand()/static_cast<double>(RAND_MAX)<<endl;
    return 0;
}
