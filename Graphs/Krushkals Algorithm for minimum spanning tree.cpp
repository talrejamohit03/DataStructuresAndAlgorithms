#include <iostream>
using namespace std;

typedef
struct edge{
    int s;
    int e;
    int cost;
}*E;

void insertionSort(E edg[], int n){
   for(int i=1;i<n;i++){
       E key=edg[i];
       int j=i-1;
       /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
       while(j>=0&&edg[j]->cost>key->cost){
           edg[j+1]=edg[j];
           j--;
       }
       edg[j+1]=key;
   }
}
int find_set(int S[],int x){
    if(S[x]==-1)
        return x;
    return find_set(S,S[x]);
}
bool union_set(int S[],int x,int y){
    int sx=find_set(S,x);
    int sy=find_set(S,y);
    if(sx!=sy){
        S[sy]=sx;
        return 1;
    }else
        return 0;
}
void Krushkal_MST(E edges[],int n,int i,int S[]){
    static int cnt=0,mstcost=0;
    if(cnt==n-1){
        cout<<"Total Cost: "<<mstcost<<endl;
        return;
    }
    if(union_set(S,edges[i]->s,edges[i]->e)){
        cout<<edges[i]->s+1<<"-"<<edges[i]->e+1<<" "<<edges[i]->cost<<endl;
        mstcost+=edges[i]->cost;
        cnt++;
    }
    Krushkal_MST(edges,n,i+1,S);
}
int main(){
    //1 2 2 1 4 1 2 4 3 2 5 10 3 1 4 3 6 5 4 5 7 4 3 2 4 6 8 4 7 4 5 7 6 7 6 1 -1 -1 -1
    int n,a,b,d;
    cout<<"Enter number of vertices: ";
    cin>>n;
    cout<<"Enter edges as vertex numbers along with cost(-1 -1 -1 to terminate):\n";
    cin>>a>>b>>d;
    int nedg=0;
    E edges[50];
    while(a!=-1&&b!=-1){
        edges[nedg]=new(edge);
        edges[nedg]->cost=d;
        edges[nedg]->s=a-1;
        edges[nedg]->e=b-1;
        cin>>a>>b>>d;
        nedg++;
    }
    int S[n];
    for(int i=0;i<n;i++)
        S[i]=-1;
    insertionSort(edges,nedg);
    Krushkal_MST(edges,n,0,S);
    return 0;
}
