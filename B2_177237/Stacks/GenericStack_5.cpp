#include <iostream>

using namespace std;
union u{
    int k;
    float f;
    char str[50];
};
struct stack{
    int top;
    union u elements[50];
    int size;
    int tags[50];
};
void push(stack *s,union u x){
    //cout<<"Pushed"<<endl;
    if(s->size-1==s->top)
        cout<<"Stack is full";
    else
        s->elements[++s->top]=x;
}
union u pop(stack *s){
    //cout<<"Popped"<<endl;
    if(s->top==-1)
        cout<<"Stack is empty";
    else
        return s->elements[s->top--];
}

int main(){
    stack *s1;
    s1=new (stack);
    s1->top=-1;
    cout<<"How many inputs? ";
    cin>>s1->size;
    for(int i=0;i<s1->size;i++){
        union u u1;
        cout<<"1.int 2. float 3. char: ";
        cin>>s1->tags[i];
        cout<<"Enter: ";
        switch(s1->tags[i]){
            case 1:
                cin>>u1.k;
                break;
            case 2:
                cin>>u1.f;
                break;
            case 3:
                cin.ignore(10,'\n');
                cin.getline(u1.str,100);
                break;
        }
        push(s1,u1);
    }
    for(int i=s1->size-1;i>=0;i--){
        switch(s1->tags[i]){
            case 1:
                cout<<pop(s1).k<<endl;
                break;
            case 2:
                cout<<pop(s1).f<<endl;
                break;
            case 3:
                cout<<pop(s1).str<<endl;
                break;
        }
    }
    return 0;
}
