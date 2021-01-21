#include <iostream>
using namespace std;

const int n=5;
int degree(int v,bool G[][n]){
    int d=0;
    for(int i=0;i<n;i++){
        if(G[v-1][i])
            d++;
    }
    return d;
}
void Euler_path(bool G[n][n],int u){
    cout<<u<<" ";
    for(int i=0;i<n;i++){
        if(G[u-1][i]){
            G[u-1][i]=0;
            G[i][u-1]=0;
            Euler_path(G,i+1);
        }
    }
}
int main(){
    //1 2 2 3 3 4 4 2 2 5 5 4 5 1 1 4 -1 -1
    int x,a,b,ch;
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
    x=0;
    for(x;x<n;x++){
        if(degree(x+1,G)%2!=0)
            break;
    }
    cout<<"\nEuler's Path: ";
    Euler_path(G,x+1);
    return 0;
}
