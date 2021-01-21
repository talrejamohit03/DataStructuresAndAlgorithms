#include <iostream>
using namespace std;

const int n=8;
typedef
struct lnode{
    int data;
    lnode *next;
} *LPTR;

struct lqueue{
    LPTR f;
    LPTR r;
};
typedef lqueue *QPTR;
void enq(QPTR &Q,int T){
    LPTR temp=new(lnode);
    temp->data=T;
    temp->next=NULL;
    if(Q->f==NULL){
        Q->f=temp;
        Q->r=temp;
    }else{
        Q->r->next=temp;
        Q->r=Q->r->next;
    }
}
int deq(QPTR Q){
    if(Q->f==NULL)
        return NULL;
    LPTR temp=Q->f;
    if(Q->r==Q->f){
        Q->f=NULL;
        Q->r=NULL;
    }else{
        Q->f=Q->f->next;
    }
    return temp->data;
}
void BFT(bool G[n][n],int u,QPTR &Q1){
    static int cnt=0,flag=0,vv[n];
    static bool visited[n]={0};
    if(Q1==NULL){
        QPTR Q1=new(lqueue);
        Q1->f=NULL;
        Q1->r=NULL;
        enq(Q1,u);
        visited[u-1]=1;
        cnt++;
    }
    int v=deq(Q1);
    for(int i=0;i<n;i++){
        if(G[v-1][i]&&(!visited[i])){
            enq(Q1,i+1);
            visited[i]=1;
            cnt++;
            flag=0;
        }
    }
    while(cnt!=n){
        enq(Q1,u);
        int v;
        while(Q1->f!=NULL){
            v=deq(Q1);
        }
        if(flag)
            cout<<"("<<u<<")"<<endl;
        for(int j=0;j<n;j++){
            if(!visited[j]){
                u=j+1;
                flag=1;
                break;
            }
        }
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
    return 0;
}
