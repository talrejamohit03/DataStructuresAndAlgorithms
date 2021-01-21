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
       while(j>=0&&edg[j]->cost<key->cost){
           edg[j+1]=edg[j];
           j--;
       }
       edg[j+1]=key;
   }
}
void DFT(bool G[][20],int u,int n,bool visited[]){
    visited[u-1]=1;
    for(int i=0;i<n;i++){
        if(G[u-1][i]&&(!visited[i]))
            DFT(G,i+1,n,visited);
    }
}
void Rev_Krushkal_MST(E edges[],int n,int i,int nedg,bool G[][20]){
    static int cnt=0,mstcost=0;
    if(i==nedg){
        cout<<"Total Cost: "<<mstcost<<endl;
        return;
    }
    int u=edges[i]->s,v=edges[i]->e;
    G[u][v]=0;
    G[v][u]=0;
    bool visited1[n]={0};
    DFT(G,0,n,visited1);
    bool flag=1;
    for(int j=0;j<n;j++){
        if(!visited1[j]){
            flag=0;
            break;
        }
    }
    if(!flag){
        G[u][v]=1;
        G[v][u]=1;
        cout<<u+1<<"-"<<v+1<<" "<<edges[i]->cost<<endl;
        mstcost+=edges[i]->cost;
    }
    Rev_Krushkal_MST(edges,n,i+1,nedg,G);
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
    bool G[n][20];
    while(a!=-1&&b!=-1){
        G[a-1][b-1]=1;
        G[b-1][a-1]=1;
        edges[nedg]=new(edge);
        edges[nedg]->cost=d;
        edges[nedg]->s=a-1;
        edges[nedg]->e=b-1;
        cin>>a>>b>>d;
        nedg++;
    }
    insertionSort(edges,nedg);
    Rev_Krushkal_MST(edges,n,0,nedg,G);
    return 0;
}
