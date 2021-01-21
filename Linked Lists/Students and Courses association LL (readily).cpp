#include <iostream>
#include <cstring>
using namespace std;
typedef
struct lnode{
    char data[3];
    lnode *link[10];
    int cnt;
    lnode *next;
} *LPTR;
void inpLL(LPTR &L){
    LPTR T;
    char n[3];
    cout<<"New Linked List\n";
    cout<<"Enter element (* to terminate): ";
    cin>>n;
    while(strcmp(n,"*")){
       LPTR temp;
       temp=new(lnode);
       strcpy(temp->data,n);
       temp->next=NULL;
       if(L==NULL){
           L=temp;
           T=L;
       }else{
           T->next=temp;
           T=T->next;
       }
       cout<<"Enter next element (* to terminate): ";
       cin>>n;
    }
}
int main(){
    LPTR Ls=NULL,Lc=NULL,Ts,Tc;
    cout<<"Student Names(2 chars): \n";
    inpLL(Ls);
    cout<<"Course Names(2 chars): \n ";
    inpLL(Lc);
    Ts=Ls;Tc=Lc;
    while(Ts!=NULL){
        cout<<"Enter course name for "<<Ts->data<<" (* to terminate) : ";
        char c[3];
        cin>>c;
        Ts->cnt=0;
        while(strcmp(c,"*")){
            Tc=Lc;
            while(strcmp(Tc->data,c))
                Tc=Tc->next;
            Ts->link[Ts->cnt++]=Tc;
            Tc->link[Tc->cnt++]=Ts;
            cout<<"Enter next course name for "<<Ts->data<<" (* to terminate) : ";
            cin>>c;
        }
        Ts=Ts->next;
    }
    Ts=Ls;Tc=Lc;
    int n;
    cout<<"Enter choice of data 1.Student 2.Course -1.terminate: ";
    cin>>n;
    char name[3];
    while(n!=-1){
        if(n==1){
            cout<<"Enter name of student: ";
            cin>>name;
            while(strcmp(Ts->data,name))
                Ts=Ts->next;
            cout<<"Courses taken are: \n";
            for(int i=0;i<Ts->cnt;i++)
                cout<<Ts->link[i]->data<<" ";
        }else if(n==2){
            cout<<"Enter name of course: ";
            cin>>name;
            while(strcmp(Tc->data,name))
                Tc=Tc->next;
            cout<<"Students enrolled are: \n";
            for(int i=0;i<Tc->cnt;i++)
                cout<<Tc->link[i]->data<<" ";
        }
        cout<<"\nEnter choice of data 1.Student 2.Course -1.terminate: ";
        cin>>n;
    }
    return 0;
}
