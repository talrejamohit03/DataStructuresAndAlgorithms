#include <iostream>
using namespace std;

struct stack{
    int top;
    int size;
    int elem[50];
};
void push(stack &s,int x){
    if(s.top==s.size-1)
        cout<<"stack is full";
    else
        s.elem[++s.top]=x;
}
int pop(stack &s){
    if(s.top==-1)
        cout<<"Stack is empty";
    else
        return s.elem[s.top--];
}

int main(){
    int k;
    cout<<"Enter value of k(no. of stacks): ";
    cin>>k;
    stack s1[k];
    cout<<"Enter sizes: ";
    int sumsize=0,tops[k];
    for(int i=0;i<k;i++){
        cout<<"Enter size of stack "<<i+1<<": ";
        cin>>s1[i].size;
        sumsize+=s1[i].size;
        /*int n1;
        cout<<"Enter number of elements u wish to enter in the stack "<<i+1<<" <= "<<s1[i].size<<": ";
        cin>>n1;*/
        s1[i].top=-1;
        cout<<"Enter elements of stack "<<i+1<<": ";
        for(int j=0;j<s1[i].size;j++){
            int x;
            cin>>x;
            push(s1[i],x);
        }
        cout<<"\n";
    }
    int arr[sumsize],j=0;
    for(int i=0;i<k;i++){
        //j=(i==0)?j:j+s1[i-1].size-1;
        tops[i]=(i==0)?s1[i].top:s1[i].top+s1[i-1].size;
        while(s1[i].top!=-1)
            arr[j++]=pop(s1[i]);
    }
    for(int s=0;s<sumsize;s++)
        cout<<arr[s]<<" ";
    return 0;
}
