#include <iostream>
using namespace std;

const int n=5;
/*int degree(int v,int n,bool *G){
    static int i=0;
    if(i==n){
        i=0;
        return 0;
    }
    if(*(G+v+(i++)))
        return 1+degree(v,n,G);
    else
        return 0+degree(v,n,G);
}*/
int degree(int v,bool G[][n]){
    int d=0;
    for(int i=0;i<n;i++){
        if(G[v][i])
            d++;
    }
    return d;
}
int in_degree(int v,bool G[n][n]){
    int d=0;
    for(int i=0;i<n;i++){
        if(G[i][v])
            d++;
    }
    return d;
}
float cycles(bool G[n][n],int v=1,int i=0){
    static int vv[n+1];//visited vertices
    float ncyc=0;
    if(v<=n){
        if(i>=3&&vv[0]==v){
           /*for(int m=0;m<i;m++)
               cout<<vv[m]<<" ";
           cout<<vv[0];
           cout<<"\n";*/
           return 1.0/(2*i);
        }
        for(int c=0;c<i;c++){//checking whether current vertex has been visited or not
            if(vv[c]==v)
                return 0;
        }
        vv[i]=v;
        for(int j=0;j<n;j++){
            if(G[v-1][j])
                ncyc+=cycles(G,j+1,i+1);
        }
    }
    return ncyc;
}
void paths(bool G[n][n],int v1,int v2,int i=0){
    static int vv[n];//visited vertices
    if(v1==v2){
       for(int m=0;m<i;m++)
           cout<<vv[m]<<" ";
       cout<<v2<<endl;
       return;
    }
    for(int c=0;c<i;c++){//checking whether current vertex has been visited or not
        if(vv[c]==v1)
            return;
    }
    vv[i]=v1;
    for(int j=0;j<n;j++){
        if(G[v1-1][j])
            paths(G,j+1,v2,i+1);
    }
}
int main(){
    //1 2 3 1 1 4 2 3 3 4 2 5 4 5 -1 -1
    int x,a,b,ch;
    cout<<"Enter number of vertices: ";
    cin>>x;
    //*((int *)(&n))=x;
    //cout<<"n is "<<n<<endl;
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
    if(ch==2){
        for(int k=0;k<n;k++)
            cout<<"Degree of vertex "<<k+1<<" is "<<degree(k,G)<<endl;
    }else{
        for(int k=0;k<n;k++){
            cout<<"Out-Degree of vertex "<<k+1<<" is "<<degree(k,G)<<endl;
            cout<<"In-Degree of vertex "<<k+1<<" is "<<in_degree(k,G)<<endl;
        }
    }
    float tcyc=0;
    for(int v=1;v<=n;v++)
        tcyc+=cycles(G,v);
    if(ch==1)tcyc=tcyc*2;
    cout<<"Number of cycles is "<<tcyc<<endl;
    cout<<"Enter 2 vertices to find out the paths: ";
    cin>>a>>b;
    paths(G,a,b);
    return 0;
}
