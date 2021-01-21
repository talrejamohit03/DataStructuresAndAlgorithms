#include <iostream>
using namespace std;

const int n=5;

typedef
struct gnode{
    int d;
    gnode *down;
    struct adnode *adptr;
}*GPTR;
typedef
struct adnode{
    int d;
    adnode *next;
}*APTR;
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
float cycles(GPTR G,int v=1,int i=0){
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
void paths(GPTR G,int v1,int v2,int i=0){
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
void insert_LL(APTR &T,int x){
    APTR temp=new(adnode),T1=NULL;
    temp->d=x;
    temp->next=NULL;
    if(T==NULL)
        T=temp;
    else{
        T1=T;
        while(T1->next!=NULL)
            T1=T1->next;
        T1->next=temp;
    }
}
int main(){
    //1 2 3 1 1 4 2 3 3 4 2 5 4 5 -1 -1
    int x,a,b,ch;
    cout<<"Enter number of vertices: ";
    cin>>x;
    //*((int *)(&n))=x;
    //cout<<"n is "<<n<<endl;
    GPTR G=new(gnode),T;
    G->d=1;
    G->adptr=NULL;
    T=G;
    for(int i=2;i<=n;i++){
        T->down=new(gnode);
        T=T->down;
        T->d=i;
        T->adptr=NULL;
    }
    T->down=NULL;
    cout<<"1.Directed 2. Undirected \nEnter choice: ";
    cin>>ch;
    cout<<"\nEnter edges as vertex numbers(-1 -1 to terminate):\n";
    cin>>a>>b;
    while(a!=-1&&b!=-1){
        T=G;
        for(int n=0;n<a-1;n++)
            T=T->down;
        insert_LL(T->adptr,b);
        if(ch==2){
            T=G;
            for(int n=0;n<b-1;n++)
                T=T->down;
            insert_LL(T->adptr,a);
        }
        cin>>a>>b;
    }
    T=G;
    cout<<"\nAdjacency List\n";
    while(T!=NULL){
        cout<<T->d<<"->";
        APTR T1=T->adptr;
        while(T1!=NULL){
            cout<<T1->d<<" ";
            T1=T1->next;
        }
        cout<<"\n";
        T=T->down;
    }
    /*if(ch==2){
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
    paths(G,a,b);*/
    return 0;
}
