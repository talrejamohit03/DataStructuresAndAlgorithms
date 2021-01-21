#include <iostream>
using namespace std;

const int n=12;
int degree(int v,bool G[][n]){
    int d=0;
    for(int i=0;i<n;i++){
        if(G[v-1][i])
            d++;
    }
    return d;
}
void splice(int l1[],int l2[],int i,int cnt1,int cnt2){
    int n=0,j=i+1,temp[cnt1];
    for(j;j<cnt1;j++)
        temp[n++]=l1[j];
    j=i;
    int i2=0;
    while(i2<=cnt2-1)
        l1[j++]=l2[i2++];
    i2=0;
    while(i2<=n)
        l1[j++]=temp[i2++];
}
void Eulerian_circuit(bool G[n][n],int u,int vv[],int &cnt,int nedg){
    vv[cnt++]=u;
    //bool flag=1;
    for(int i=0;i<n;i++){
        if(G[u-1][i]){
           G[u-1][i]=0;
           G[i][u-1]=0;
           //flag=0;
           Eulerian_circuit(G,i+1,vv,cnt,nedg);
           G[u-1][i]=1;
           G[i][u-1]=1;
           cnt--;
        }
    }
    /*if(flag){
        int i=0;
        for(i;i<cnt;i++){
            if(degree(vv[i],G)!=0)
                break;
        }
        if(i==cnt)
            return;
        int tcnt=0,tvv[30];
        Eulerian_circuit(G,vv[i],tvv,tcnt,nedg);
        splice(vv,tvv,i,cnt,tcnt);
        cnt+=tcnt-1;
    }*/
    if(cnt==nedg){
        for(int i=0;i<cnt;i++)
            cout<<vv[i]<<" ";
        cout<<endl;
    }
}
int main(){
    //1 3 1 4 2 3 2 8 3 4 3 6 3 7 3 9 4 5 4 7 4 10 4 11 5 10 6 9 7 9 7 10 8 9 9 10 9 12 10 11 10 12 -1 -1
    int x,a,b,ch,nedg=0;
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
        nedg++;
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
    int cnt1=0;
    int vv1[50];
    Eulerian_circuit(G,x,vv1,cnt1,nedg);
    return 0;
}

