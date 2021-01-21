#include <iostream>
using namespace std;

const int n=8;

void DFT(bool G[n][n],int u,bool flag=1){
    static bool visited[n]={0};
    cout<<u<<" ";
    visited[u-1]=1;
    for(int i=0;i<n;i++){
        if(G[u-1][i]&&(!visited[i]))
            DFT(G,i+1,0);
    }
    if(flag){//indicates the start vertex
        for(int j=0;j<n;j++){
            if(!visited[j])
                DFT(G,j+1);
        }
    }
}
int main(){
    //1 2 3 1 1 4 2 3 3 4 2 5 4 5 -1 -1
    //1 2 1 4 3 2 3 1 3 4 4 5 2 5 -1 -1
    //1 2 1 3 1 4 2 5 4 6 7 3 7 2 7 8 8 5 -1 -1
    int x,a,b,ch;
//    cout<<"Enter number of vertices: ";
//    cin>>x;
    //*((int *)(&n))=x;
    bool G[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            G[i][j]=0;
    }
    cout<<"1.Directed 2. Undirected \nEnter choice: ";
    cin>>ch;
    cout<<"\nEnter edges as vertex numbers(-1 -1 to terminate):\n";
    cin>>a>>b;
    while(a!=-1&&b!=-1){
        G[a-1][b-1]=1;
        if(ch==2)
            G[b-1][a-1]=1;
        cin>>a>>b;
    }
    cout<<"\nAdjacency Matrix\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<G[i][j]<<" ";
        cout<<"\n";
    }
    cout<<"Enter start vertex: ";
    cin>>x;
    DFT(G,x);
    cout<<endl;
    return 0;
}
