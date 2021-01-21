#include <iostream>
using namespace std;

//percolate up
void ins_heap(int H[],int &n,int k){
    if(k!=-1){
        H[n]=k;
        for(int i=n;i>0;i--){
            if(H[i]<H[(i-1)/2])
                swap(H[i],H[(i-1)/2]);
        }
        int k1;
        cin>>k1;
        ins_heap(H,++n,k1);
    }
}
//percolate down
void heap_sort(int H[],int &n){
    if(n>0){
        cout<<H[0]<<" ";
        H[0]=H[--n];
        int i=0;
        while(2*i+2<=n){
            if(H[i]>H[2*i+1]||H[i]>H[2*i+2])
                swap(H[i],((H[2*i+1]<H[2*i+2])?H[2*i+1]:H[2*i+2]));
            i++;
        }
        heap_sort(H,n);
    }
}
int main(){
    int H1[50],n1=0,k1;
    cin>>k1;
    ins_heap(H1,n1,k1);
    cout<<"Heap: \n";
    for(int i=0;i<n1;i++)
        cout<<H1[i]<<" ";
    cout<<"\nAfter Heap Sort: \n";
    heap_sort(H1,n1);
    return 0;
}
