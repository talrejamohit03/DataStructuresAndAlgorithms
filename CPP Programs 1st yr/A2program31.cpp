#include <iostream>
using namespace std;

struct student{
    char name[50];
    int rollno;
    char address[200];
    double marks[3];
};
void new_line(){
    char ch;
    do{
        cin.get(ch);
    }while(ch!='\n');
}
int main(){
    student arr[3];
    for(int i=0;i<10;i++){
        student temp;
        cout<<"Student "<<i+1<<":"<<endl;
        cout<<"Enter student name: ";
        cin.getline(temp.name,50);
        cout<<"Enter address: ";
        cin.getline(temp.address,200);
        cout<<"Enter roll number: ";
        cin>>temp.rollno;
        cout<<"Enter marks in subjects: "<<endl;
        for(int j=0;j<3;j++){
            cout<<"Subject "<<j+1<<": ";
            cin>>temp.marks[j];
        }
        new_line();
        arr[i]=temp;
    }
    for(int i=0;i<10;i++){
        cout<<"Student "<<i+1<<endl;
        cout<<arr[i].rollno<<"\t"<<arr[i].name<<"\t"<<arr[i].address<<endl;
        cout<<"Marks in subjects: "<<endl;
        for(int n=0;n<3;n++){
            cout<<"Subject "<<n+1<<": "<<arr[i].marks[n]<<" ";
        }
        cout<<"\n";
    }
}
