#include <iostream>
using namespace std;

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
int degree(int v,int n,bool *G){
    int d=0;
    for(int i=0;i<n;i++){
        if(*(G+v*n+i))
            d++;
    }
    return d;
}
int in_degree(int v,int n,bool *G){
    int d=0;
    for(int i=0;i<n;i++){
        if(*(G+i*n+v))
            d++;
    }
    return d;
}
float cycles(bool *G,const int n,int v=1,int i=0){
    //i keeps track of the size of the cycle
    static int vv[n+1];//visited vertices
    int ncyc=0;
    if(v<=n){
        if(i>=3&&vv[0]==v)
           return 1.0/i;
        for(int c=0;c<i;c++){//checking whether current vertex has been visited or not
            if(vv[c]==v)
                return 0;
        }
        vv[i]=v;
        for(int j=v;j<n;j++){
            if(*(G+(v-1)*n+j))
                ncyc+=cycles(G,n,j,i+1);
        }
    }
    return ncyc+cycles(G,n,v+1);
}
//int isCycle(bool G[n][n],int )
int main(){
    //1 2 3 1 1 4 2 3 3 4 2 5 4 5 -1 -1
    int n,a,b,ch;
    cout<<"Enter number of vertices: ";
    cin>>n;
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
            cout<<"Degree of vertex "<<k+1<<" is "<<degree(k,n,(bool *)G)<<endl;
    }else{
        for(int k=0;k<n;k++){
            cout<<"Out-Degree of vertex "<<k+1<<" is "<<degree(k,n,(bool *)G)<<endl;
            cout<<"In-Degree of vertex "<<k+1<<" is "<<in_degree(k,n,(bool *)G)<<endl;
        }
    }
    cout<<"Number of cycles is "<<cycles((bool *)G,n);
    return 0;
}
