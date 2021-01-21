#include <iostream>
using namespace std;

typedef
struct queue{
	int f;
	int r;
	int s;
	int elem[50];
} *qptr;

void enq(qptr Q,int x){
	if(Q->f==(Q->r+1)%Q->s)
		cout<<"Queue is full";
	else{
		if(Q->r==-1)
			Q->f=0;
		Q->r=(Q->r+1)%Q->s;
		Q->elem[Q->r]=x;
	}
}
int deq(qptr Q){
	if(Q->f==-1){
		cout<<"Queue is empty";
		return 0;
	}else{
		int t=Q->elem[Q->f];
		if(Q->f==Q->r){
			Q->f=-1;
			Q->r=-1;
		}else
			Q->f=(Q->f+1)%Q->s;
		return t;
	}		
}
qptr initialQ(int siz){
	qptr q1=new(queue);
	q1->f=-1;
	q1->r=-1;
	q1->s=siz;
	return q1;
}
void bfs01(int G[][20],int n,int s,int dist[],int prevv[],int x,int y){
	qptr q1=initialQ(n),q2=initialQ(n);
	enq(q1,s);
	while(q1->f!=-1||q2->f!=-1){
		int v;
		if(q1->f!=-1)
			v=deq(q1);
		else
			v=deq(q2);
		//cout<<v<<" ";
		for(int i=0;i<n;i++){
			if(G[v][i]!=0&&G[v][i]+dist[v]<dist[i]){
				dist[i]=dist[v]+G[v][i];
				prevv[i]=v;
				if(G[v][i]==x)
					enq(q1,i);
				else
					enq(q2,i);
			}
		}
	}
	for(int i=0;i<s;i++){
		int c=prevv[i];
		cout<<i<" ";
		while(c!=s){
			cout<<c<<" ";
			c=prevv[c];
		}
		cout<<s<<" cost: "<<dist[i]<<endl;
	}
	for(int i=s+1;i<n;i++){
		int c=prevv[i];
		cout<<i<<" ";
		while(c!=s){
			cout<<c<<" ";
			c=prevv[c];
		}
		cout<<s<<" cost: "<<dist[i]<<endl;
	}
}
int main(){
	int n,a,b,w,ch,x1,y1;
	cout<<"Enter number of vertices: ";
	cin>>n;//9
	int G[n][20];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            G[i][j]=0;
    }
    cout<<"1.Directed 2. Undirected \nEnter choice: ";
    cin>>ch;//2
    cout<<"Enter distances X and Y: ";
    cin>>x1>>y1;//2 3
    cout<<"Enter edges as vertex numbers along with the distances(0 for X,1 for Y)(-1 -1 -1 to terminate):\n";
    cin>>a>>b>>w;
    //0 1 0 0 7 1 1 2 1 1 7 1 2 3 0 2 5 0 2 8 1 3 4 1 3 5 1 4 5 1 5 6 1 6 7 1 6 8 1 7 8 1 -1 -1 -1
    while(a!=-1&&b!=-1){
    	int d;
    	d=(w==0)?x1:y1;
        G[a][b]=d;
        if(ch==2)
            G[b][a]=d;
        cin>>a>>b>>w;
    }
    cout<<"\nWeight Matrix\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<G[i][j]<<" ";
        cout<<"\n";
    }
    int d[n],pv[n];
	for(int i=0;i<n;i++){
		d[i]=10000;
		pv[i]=0;
	}
	cout<<"Enter start vertex: ";
	cin>>a;
	d[a]=0;
	pv[a]=0;
	bfs01(G,n,a,d,pv,x1,y1);
	return 0;
}
