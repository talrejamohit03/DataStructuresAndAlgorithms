#include <iostream>
using namespace std;

const int n=10;

void DFT(bool G[n][n],int u,int num[],bool flag=1){
    static bool visited[n]={0};
    static int cnt=0;
    visited[u-1]=1;
    for(int i=0;i<n;i++){
        if(G[u-1][i]&&(!visited[i]))
            DFT(G,i+1,num,0);
    }
    num[cnt++]=u;
    if(flag){
        for(int j=0;j<n;j++){
            if(!visited[j])
                DFT(G,j+1,num);
        }
    }
}
void strong_comp(bool G[n][n],int u,int num[],bool flag=1){
    static bool visited[n]={0};
    cout<<u<<" ";
    visited[u-1]=1;
    for(int i=0;i<n;i++){
        if(G[u-1][i]&&(!visited[i]))
            strong_comp(G,i+1,num,0);
    }
    if(flag){
        cout<<"}";
        for(int i=n-2;i>=0;i--){
            if(!visited[num[i]-1]){
                cout<<"{";
                strong_comp(G,num[i],num,0);
                cout<<"}";
            }
        }
    }
}
int main(){
    //1 2 1 4 2 3 2 6 3 1 3 4 3 5 4 5 6 3 7 6 7 8 8 6 8 10 9 8 10 9 -1 -1
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
    cout<<"Enter start vertex for DFT: ";
    cin>>x;
    int num1[n]={0};
    DFT(G,x,num1);
    for(int i=0;i<n;i++)
        cout<<num1[i]<<" ";
    cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            bool temp=G[i][j];
            G[i][j]=G[j][i];
            G[j][i]=temp;
        }
    }
    cout<<"\nAdjacency Matrix for Reverse Graph\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<G[i][j]<<" ";
        cout<<"\n";
    }
    cout<<"Strong components are: \n";
    cout<<"{";
    strong_comp(G,num1[n-1],num1);
    return 0;
}

