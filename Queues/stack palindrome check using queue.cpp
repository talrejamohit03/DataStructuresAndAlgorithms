#include <iostream>
using namespace std;
struct stack{
    int top;
    int size;
    char elem[50];
};
void push(stack &s,char x){
    if(s.top==s.size-1)
        cout<<"stack is full";
    else
        s.elem[++s.top]=x;
}
char pop(stack &s){
    if(s.top==-1)
        cout<<"Stack is empty";
    else
        return s.elem[s.top--];
}
struct queue{
    int f;
    int r;
    int s;
    char elem[50];
};
void enq(queue &Q,char x){
    if(Q.f==((Q.r+1)%Q.s))
        cout<<"Queue is full";
    else{
        if(Q.r==-1)
            Q.f=0;
        Q.r=(Q.r+1)%Q.s;
        Q.elem[Q.r]=x;
    }
}
char dq(queue &q){
    if(q.f==-1)
        cout<<"Queue is empty.";
    else{
        char t=q.elem[q.f];
        if(q.f==q.r){
            q.f=-1;
            q.r=-1;
            return t;
        }else{
            q.f=(q.f+1)%q.s;
            return t;
        }
    }
}
int main(){
    //pop all elements and enqueue into the queue
    //dequeue and enqueue n/2 elements in the queue
    //dequeue and push n/2 elements into the stack
    //keep dequeuing and popping, if at any instance elements are not the same, false
    queue q1;
    stack s1,s2;
    s1.top=-1;s2.top=-1;
    q1.f=-1;q1.r=-1;
    cout<<"Enter size of stack: ";
    cin>>s1.size;
    s2.size=s1.size;
    cout<<"enter stack string with each character separated by a space: ";
    for(int i=0;i<s1.size;i++){
        char c;
        cin>>c;
        push(s1,c);
    }
    while(s1.top!=-1){
        char c=pop(s1);
        push(s2,c);
        enq(q1,c);
    }
    int flag=1;
    while(s2.top!=-1){
        if(pop(s2)!=dq(q1)){
            flag=0;
            break;
        }
    }
    if(flag==0)
        cout<<"Not palindrome";
    else
        cout<<"Palindrome";
    return 0;

}
