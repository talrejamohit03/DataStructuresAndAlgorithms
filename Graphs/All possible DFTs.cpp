#include <iostream>
using namespace std;

void allDFT(bool G[][20],int u,int n,int cnt=0){
    static bool visited[20]={0};
    static int vv[20];
    vv[cnt]=u;
    visited[u-1]=1;
    bool adflag=1,prflag=1;//flag to flag the vertex with no adjacent vertices
    for(int i=0;i<n;i++){
        if(G[u-1][i]&&(!visited[i])){
            allDFT(G,i+1,n,cnt+1);
            adflag=0;
            prflag=0;
        }
    }
    /*if(adflag){//back-tracing the same path of visited vertices to check adjacent vertices which haven't been visited
        for(int i=cnt-1;i>=0;i--){
            bool f=0;
            for(int j=0;j<n;j++){
                if((!visited[j])&&G[vv[i]-1][j]){
                    allDFT(G,j+1,cnt+1,0);
                    f=1;
                    break;
                }
            }
            if(f)
                break;
        }
    }*/
    if(adflag){//in case of disconnected graph or weakly connected directed graph
        for(int j=0;j<n;j++){
            if(!visited[j]){
                allDFT(G,j+1,n,cnt+1);
                prflag=0;//flag that tells when to print
                break;
            }
        }
    }
    if(prflag){
        for(int i=0;i<n;i++)
            cout<<vv[i]<<" ";
        cout<<"\n";
    }
    visited[u-1]=0;
}
int main(){
    //1 2 3 1 1 4 2 3 3 4 2 5 4 5 -1 -1
    //1 2 1 4 3 2 3 1 3 4 4 5 2 5 -1 -1
    //1 2 1 3 1 4 2 5 4 6 7 3 7 2 7 8 8 5 -1 -1
    //1 2 1 5 1 4 2 5 2 3 3 4 3 6 4 5 -1 -1
    int n,a,b,ch;
    cout<<"Enter number of vertices: ";
    cin>>n;
    //*((int *)(&n))=x;
    bool G[n][20];
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
    int x;
    cout<<"Enter start vertex: ";
    cin>>x;
    allDFT(G,x,n,0);
    return 0;
}

