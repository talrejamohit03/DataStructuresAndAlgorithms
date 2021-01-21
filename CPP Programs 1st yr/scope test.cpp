#include <iostream>
using namespace std;
int n=20;
void mohit(){
    int n=3;
    cout<<::n;
}
int main(){
    int n=5;
    cout<<::n<<endl;
    mohit();

}
