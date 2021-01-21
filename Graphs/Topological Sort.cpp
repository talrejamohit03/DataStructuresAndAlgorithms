#include <iostream>
using namespace std;

const int n=14;

int in_degree(int v,bool G[n][n]){
    int d=0;
    for(int i=0;i<n;i++){
        if(G[i][v-1])
            d++;
    }
    return d;
}
void topological_sort(bool G[n][n],int indg[],char subjects[][5]){
    static int cnt=0;
    static bool visited[n]={0};
    cout<<"Possible choices: ";
    for(int i=0;i<n;i++){
        if(indg[i]==0&&(!visited[i])){
            cout<<i+1<".";
            cout<<subjects[i]<<" ";
        }
    }
    if(cnt==n){
        cout<<"No more possible";
        return;
    }
    int v;
    cout<<"Select subject(enter serial number): ";
    cin>>v;
    cnt++;
    visited[v-1]=1;
    for(int i=0;i<n;i++){
        if(G[v-1][i])
            indg[i]--;
    }
    topological_sort(G,indg,subjects);
}
int main(){
    //1 6 2 7 3 8 4 6 4 7 5 11 6 10 7 9 8 11 9 14 9 13 10 12 11 14 12 14 13 14 -1 -1
    //S P C M E DS DM DLD TOC OS EA CN AI PRJ
    int x,a,b,ch=1;
//    cout<<"Enter number of vertices: ";
//    cin>>x;
    //*((int *)(&n))=x;
    bool G[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            G[i][j]=0;
    }
    cout<<"Enter edges as vertex numbers(-1 -1 to terminate):\n";
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
    char subs[n][5];
    cout<<"Enter subjects for vertices: ";
    for(int i=0;i<n;i++)
        cin>>subs[i];
    int indeg[n];
    for(int i=0;i<n;i++)
        indeg[i]=in_degree(i+1,G);
    topological_sort(G,indeg,subs);
    return 0;
}
