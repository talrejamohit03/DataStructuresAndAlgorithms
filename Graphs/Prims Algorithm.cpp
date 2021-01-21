#include <iostream>
using namespace std;
const int n=7;

void min_spanning_tree(int G[n][n],int c){
    static bool visited[n]={0};
    static int cost=0,cnt=0;
    visited[c-1]=1;
    cnt++;
    if(cnt==n){
        cout<<"Total minimum cost: "<<cost<<endl;
        return;
    }
    int startv=0,nextv=0,minadj=10000;
    for(int i=0;i<n;i++){
        if(visited[i]){
            for(int j=0;j<n;j++){
                if(G[i][j]!=0&&G[i][j]<minadj&&(!visited[j])){
                    minadj=G[i][j];
                    nextv=j+1;
                    startv=i+1;
                }
            }
        }
    }
    cout<<startv<<"-"<<nextv<<" cost: "<<minadj<<endl;
    cost+=minadj;
    min_spanning_tree(G,nextv);
}

int main(){
    //1 2 2 1 4 1 2 4 3 2 5 10 3 1 4 3 6 5 4 5 7 4 3 2 4 6 8 4 7 4 5 7 6 7 6 1 -1 -1 -1
    int x,a,b,ch,d;
//    cout<<"Enter number of vertices: ";
//    cin>>x;
    //*((int *)(&n))=x;
    //cout<<"n is "<<n<<endl;
    int G[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            G[i][j]=0;
    }
    cout<<"1.Directed 2. Undirected \nEnter choice: ";
    cin>>ch;
    cout<<"\nEnter edges as vertex numbers(-1 -1 to terminate):\n";
    cin>>a>>b>>d;
    while(a!=-1&&b!=-1){
        G[a-1][b-1]=d;
        if(ch==2)
            G[b-1][a-1]=d;
        cin>>a>>b>>d;
    }
    cout<<"\nCost Matrix\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<G[i][j]<<" ";
        cout<<"\n";
    }
    cout<<"\nMinimum spanning tree is:\n";
    min_spanning_tree(G,1);
    return 0;
}
