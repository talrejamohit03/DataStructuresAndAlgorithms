#include <iostream>
using namespace std;

const int m=4;

struct mstnode{
    int keys[m];//0th index of keys array stores the size of the key,i.e.,the number of elements in the key
    mstnode *mstptrs[m];
};
typedef mstnode *MSTPTR;

void create(MSTPTR &T,int k){
    if(T==NULL){
        T=new(mstnode);
        T->keys[0]=1;
        T->keys[1]=k;
        for(int i=0;i<m;i++)
            T->mstptrs[i]=NULL;
    }else{
        int j=1;
        while(T->keys[j]<k&&j<=T->keys[0])j++;
        if(T->keys[0]<m-1){
            T->keys[0]+=1;
            for(int i=T->keys[0];i>j;i--)
                T->keys[i]=T->keys[i-1];
            T->keys[j]=k;

        }else
            create(T->mstptrs[j-1],k);
    }
}
void printsorted(MSTPTR T){
    if(T!=NULL){
        for(int i=0;i<T->keys[0]+1;i++){
            if(i!=0)
                cout<<T->keys[i]<<" ";
            printsorted(T->mstptrs[i]);
        }
    }
}
bool find_mst(MSTPTR T,int k){
    if(T!=NULL){
        int j=1;
        while(j<=T->keys[0]&&T->keys[j]<k)j++;
        if(T->keys[j]==k)
            return 1;
        else
            return find_mst(T->mstptrs[j-1],k);
    }
    return 0;
}
int min_mst(MSTPTR T){
    if(T->mstptrs[0]==NULL)
        return T->keys[1];
    return min_mst(T->mstptrs[0]);
}
int max_mst(MSTPTR T){
    if(T->mstptrs[T->keys[0]]==NULL)
        return T->keys[T->keys[0]];
    return max_mst(T->mstptrs[T->keys[0]]);
}
int main(){
    //10 60 100 200 40 120 -1
    //20 90 40 19 15 17 120 45 100 18 12 9 -1
    MSTPTR T1=NULL;
    int n1;
    cout<<"Enter keys: (-1 to terminate) ";
    cin>>n1;
    while(n1!=-1){
        create(T1,n1);
        cin>>n1;
    }
    printsorted(T1);
    cout<<"\nEnter element whose presence is to be checked: ";
    cin>>n1;
    if(find_mst(T1,n1))
        cout<<"Element is present.";
    else
        cout<<"Not present.";
    cout<<"Minimum element is: "<<min_mst(T1);
    cout<<"Maximum element is: "<<max_mst(T1);
    return 0;
}
