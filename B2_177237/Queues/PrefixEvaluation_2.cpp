#include <iostream>
#include <cstdlib>
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
int eval(char op,int op1,int op2){
    switch(op){
        case('+'):
            return op1+op2;
        case('-'):
            return op1-op2;
        case('*'):
            return op1*op2;
        case('/'):
            return op1/op2;
    }
}
int main(){
    queue q1;
    q1.f=-1;
    q1.r=-1;
    q1.s=50;
    /*int expsize;
    cout<<"Enter size of expression: ";
    cin>>expsize;
    char exp[expsize];
    cin.ignore();
    cout<<"Enter expression: ";
    cin.getline(exp,expsize);*/
    char exp[26]="- + * 9 + 2 8 * / 8 4 6 3";
    for(int i=24;i>=0;i--){
        for(int n=q1.f;n<=q1.r;n++)
            cout<<q1.elem[n]<<" ";
        cout<<endl;
        if(exp[i]>='0'&&exp[i]<='9'){
            /*char nc[6]="";
            int l,u=i,ni=0;
            while(exp[i]!=' ')
                i--;
            l=i;
            for(int j=l+1;j<=u;j++)
                nc[ni++]=exp[j];
            int nd=atoi(nc);*/
            //enq(q1,nd);
            enq(q1,exp[i]-'0');
        }else if(exp[i]!=' '){
            int u=q1.r;
            while((q1.f%q1.s)+1!=u)
                enq(q1,dq(q1));
            enq(q1,eval(exp[i],dq(q1),dq(q1)));
        }
    }
    cout<<dq(q1);
}
