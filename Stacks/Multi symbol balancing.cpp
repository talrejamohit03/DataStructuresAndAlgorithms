#include <iostream>
#include <cstring>
using namespace std;

struct stack{
    int top;
    char elements[50];
    int size;
};
void push(stack &s,char x){
    if(s.size-1==s.top)
        cout<<"Stack is full";
    else
        s.elements[++s.top]=x;
}
char pop(stack &s){
    if(s.top==-1)
        cout<<"Stack is empty";
    else
        return s.elements[s.top--];
}
int main(){
    char symba[20]="[()[{{()}((())}]{}]";
    stack s1;
    s1.top=-1;s1.size=50;
    for(int i=0;i<strlen(symba);i++){
        if(symba[i]=='{'||symba[i]=='['||symba[i]=='(')
            push(s1,symba[i]);
        else{
            char c=pop(s1);
            if((symba[i]==']'&&c!='[')||(symba[i]==')'&&c!='(')||(symba[i]=='{'&&c!='}')){
                cout<<"Symbols are not balanced.";
                break;
            }

        }
    }
    if(s1.top==-1)
        cout<<"Symbols are balanced.";
    return 0;
}
