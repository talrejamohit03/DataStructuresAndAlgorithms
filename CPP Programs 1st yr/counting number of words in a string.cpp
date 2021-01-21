#include <iostream>
#include <string>
using namespace std;
int main(){
    char s[80];
    int i=0,c=1;
    cout<<"Enter a line(max 80 characters): ";
    cin.getline(s,80);
    while(s[i]!='\0'){
        if(s[i]==' '){
            while(s[i]==' ')
                i++;
            c++;
        }
        //if(s[i]=='\0')
          //  i--;
        i++;
    }
    cout<<"\nNumber of words is: "<<c;
    return 0;
}
