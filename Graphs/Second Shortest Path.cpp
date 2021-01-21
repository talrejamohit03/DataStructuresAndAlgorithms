#include <iostream>
using namespace std;
const int n=7;

void shortest_path(int G[n][n],int distance[][2],int prev[][2],int c,int g,bool minflag=0){
    static bool visited[n]={0};
    if(c==g){
        cout<<g<<" ";
        int pr=prev[g-1][1];
        while(pr!=0){
            cout<<pr<<" ";
            pr=prev[pr-1][0];
        }
        cout<<"Second Minimum Cost: "<<distance[g-1][1];
        return;
    }
    for(int i=0;i<n;i++){
        if(G[c-1][i]!=0&&(!visited[i])){
            if(G[c-1][i]<distance[i][0]){
                distance[i][1]=distance[i][0];
                prev[i][1]=prev[i][0];
                distance[i][0]=distance[c-1][0]+G[c-1][i];
                prev[i][0]=c;
            }
            else if(G[c-1][i]>distance[i][0]&&G[c-1][i]<distance[i][1]){
                distance[i][1]=distance[c-1][0]+G[c-1][i];
                prev[i][1]=c;
            }
        }
    }
    visited[c-1]=1;
    int mincost1=10000,minv1=0,minv2=0,mincost2=10000;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            if(distance[i][0]<mincost1){
                mincost2=mincost1;
                minv2=minv1;
                mincost1=distance[i][0];
                minv1=i+1;
            }else if(distance[i][0]>mincost1&&distance[i][0]<mincost2){
                mincost2=distance[i][0];
                minv2=i+1;
            }
        }
    }
    if(minflag)
        shortest_path(G,distance,prev,minv1,g,0);
    else
        shortest_path(G,distance,prev,minv2,g,1);
}

int main(){
    //1 2 2 1 4 1 2 4 3 2 5 10 3 1 4 3 6 5 4 5 2 4 3 2 4 6 8 4 7 4 5 7 6 7 6 1 -1 -1 -1
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
    int distance1[n][2];
    for(int i=0;i<n;i++){
        distance1[i][0]=10000;
        distance1[i][1]=10000;
    }
    int prev1[n][2];
    for(int i=0;i<n;i++){
        prev1[i][0]=0;
        prev1[i][1]=0;
    }
    cout<<"Enter vertices between which shortest path has to be found: ";
    cin>>a>>b;
    distance1[a-1][0]=0;
    prev1[a-1][0]=0;
    shortest_path(G,distance1,prev1,a,b);
    return 0;
}
