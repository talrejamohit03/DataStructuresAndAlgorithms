#include <iostream>
using namespace std;
struct queue{
    int f;
    int r;
    int s;
    int elem[50];
};
void enq(queue &Q,int x){
    if(Q.f==((Q.r+1)%Q.s))
        cout<<"Queue is full";
    else{
        if(Q.r==-1)
            Q.f=0;
        Q.r=(Q.r+1)%Q.s;
        Q.elem[Q.r]=x;
    }
}
int dq(queue &q){
    if(q.f==-1)
        cout<<"Queue is empty.";
    else{
        int t=q.elem[q.f];
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
void display(queue &q){
    int i=q.f;
    if(q.f==q.r&&q.f!=-1)
        cout<<q.elem[i];
    else if(q.f==-1)
        cout<<"Queue is empty";
    else{
        while(i!=((q.r+1)%q.s)){
            cout<<q.elem[i]<<" ";
            i=(i+1)%q.s;
        }
    }
    cout<<endl;
}
int main(){
    queue q1;
    q1.f=-1;
    q1.r=-1;
    cout<<"enter size of queue: ";
    cin>>q1.s;
    int ch;
    do{
        cout<<"Enter 1. enqueue 2. dequeue 0. Exit: ";
        cin>>ch;
        if(ch==1){
            int a;
            cout<<"Enter element: ";
            cin>>a;
            enq(q1,a);
            display(q1);
        }
        else if(ch==2){
            cout<<dq(q1)<<" is dequeued.\n";
            display(q1);
        }
    }while(ch);
    return 0;
}
