#include <iostream>
using namespace std;
const int n=7;

void shortest_path(int G[n][n],int distance[],int prev[],int c,int g){
    static bool visited[n]={0};
    int s1=c;
    distance[c-1]=0;
    while(c!=g){
        for(int i=0;i<n;i++){
            if(G[c-1][i]!=0&&(!visited[i])){
                if(G[c-1][i]<distance[i]){
                    distance[i]=distance[c-1]+G[c-1][i];
                    prev[i]=c;
                }
            }
        }
        visited[c-1]=1;
        int mincost=10000,minv=0;
        for(int i=0;i<n;i++){
            if(!visited[i]&&distance[i]<mincost){
                mincost=distance[i];
                minv=i+1;
            }
        }
        c=minv;
    }
    int pr=g;
    while(pr!=s1){
        cout<<pr<<" ";
        pr=prev[pr-1];
    }
    cout<<pr;
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
    int distance1[n];
    for(int i=0;i<n;i++)
        distance1[i]=10000;
    int prev1[n]={0};
    shortest_path(G,distance1,prev1,1,6);
    return 0;
}

