#include <iostream>
using namespace std;

const int k=3;

typedef
struct kdnode{
    kdnode *lchild;
    int data[k];
    kdnode *rchild;
}* KDPTR;

void ins_kd(KDPTR &T,int key[],int i){
    if(T==NULL){
        T=new(kdnode);
        T->lchild=NULL;
        T->rchild=NULL;
        for(int j=0;j<k;j++)
            T->data[j]=key[j];
    }else{
        if(T->data[i]>key[i]){
            i=(i+1)%k;
            ins_kd(T->lchild,key,i);
        }else if(T->data[i]<=key[i]){
            i=(i+1)%k;
            ins_kd(T->rchild,key,i);
        }
    }
}
void dlrprint(KDPTR T){
    if(T!=NULL){
        cout<<"(";
        int i=0;
        for(i;i<k-1;i++)
            cout<<T->data[i]<<",";
        cout<<T->data[i]<<") ";
        dlrprint(T->lchild);
        dlrprint(T->rchild);
    }
}
int find_kd(KDPTR T,int key[]){
    static int i=0;
    if(T!=NULL){
        if(T->data[i]>key[i]){
            i=(i+1)%k;
            return find_kd(T->lchild,key);
        }else if(T->data[i]<key[i]){
            i=(i+1)%k;
            return find_kd(T->rchild,key);
        }else{
            int j=(i+1)%k,flag=1;
            while(j!=i){
                if(T->data[j]!=key[j]){
                    flag=0;
                    break;
                }
                j=(j+1)%k;
            }
            if(flag==1)
                return 1;
            else
                return find_kd(T->rchild,key);
        }
    }else
        return 0;
}
int mincoordinate(KDPTR T,int i){
    static int d=0, minim=T->data[i];
    if(T!=NULL){
        if(T->data[i]<minim)
            minim=T->data[i];
        if(d==i){
            d=(d+1)%k;
            minim=mincoordinate(T->lchild,i);
        }else{
            d=(d+1)%k;
            minim=mincoordinate(T->lchild,i);
            d=(d-1)%k;
            minim=mincoordinate(T->rchild,i);
        }
    }
    return minim;
}
int main(){
    KDPTR T1=NULL;
    int arr[k],n,a1[3]={20,5,7};
    //20 5 10 3 18 70 70 15 4 10 80 36 40 30 10 80 25 9 25 30 75 25 32 20
    cout<<"Enter number of elements: ";
    cin>>n;
    while(n>0){
        for(int i=0;i<k;i++)
            cin>>arr[i];
        ins_kd(T1,arr,0);
        n--;
    }
    dlrprint(T1);
    cout<<endl;
    if(find_kd(T1,a1))
        cout<<"Element found";
    else
        cout<<"Element not found";
    cout<<"\nMinimum 3rd coordinate is: "<<mincoordinate(T1,2);
    return 0;
}
