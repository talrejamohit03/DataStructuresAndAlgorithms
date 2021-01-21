#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int i=0,j=0;
    char ch[50],a[20][20],*p,b[30];
    cin.getline(ch,50);
    p=strtok(ch," ");
    while(p!=NULL){
        strcpy(a[i],p);
        p=strtok(NULL," ");
        i++;
    }
    for(int m=0;m<i;m++){
        cout<<a[m]<<" ";
    }
    return 0;
}
