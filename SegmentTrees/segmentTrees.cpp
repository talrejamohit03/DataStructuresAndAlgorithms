#include <bits/stdc++.h>
using namespace std;

//maximum element query

void build(int node,int st[],int a[],int s, int e){
    if(s==e){
        st[node]=a[s];
        return;
    }
    int mid=(s+e)/2;
    build(2*node,st,a,s,mid);
    build(2*node+1,st,a,mid+1,e);
    st[node]=max(st[2*node],st[2*node+1]);
}
void update(int st[],int a[],int id,int val,int node,int s,int e){
    if(s==e){
        st[node]=val;
        a[id]=val;
        return;
    }
    int mid=(s+e)/2;
    if(s<=id && id<=mid)
        update(st,a,id,val,2*node,s,mid);
    else
        update(st,a,id,val,2*node+1,mid+1,e);
    st[node]=max(st[2*node],st[2*node+1]);
}
int query(int st[],int node,int l,int r,int s,int e){
    if(r<s || l>e)
        return INT_MIN;
    else if(s>=l && e<=r)
        return st[node];
    int mid=(s+e)/2;
    return max(query(st,2*node,l,r,s,mid),query(st,2*node+1,l,r,mid+1,e));
}
int main(){
    int n;
    cin>>n;
    int st[2*n-1],a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    build(0,st,a,0,n-1);
    int q;
    cin>>q;
    while(q==1 || q==2){
        if(q==1){
            int l,r;
            cin>>l>>r;
            cout<<query(st,0,l,r,0,n-1);
        }
        else if(q==2){
            int i,v;
            cin>>i>>v;
            update(st,a,i,v,0,0,n-1);
        }
        cin>>q;
    }
    return 0;
}
