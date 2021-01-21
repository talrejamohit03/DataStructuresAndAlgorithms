#include <iostream>
using namespace std;

void Knight_Tour(int G[][8],int x,int y,bool &flag){
    static int n=0,xm[8]={2,1,-1,-2,-2,-1,1,2},ym[8]={1,2,2,1,-1,-2,-2,-1};
    if(n==63){
        flag=1;
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(G[i][j]/10==0)
                    cout<<" ";
                cout<<G[i][j]<<" ";
            }
            cout<<"\n";
        }
        return;
    }
    for(int i=0;i<8;i++){
        if((x+xm[i])>=0&&(x+xm[i])<=7&&(y+ym[i])>=0&&(y+ym[i])<=7&&G[x+xm[i]][y+ym[i]]==-1){
            G[x+xm[i]][y+ym[i]]=++n;
            Knight_Tour(G,x+xm[i],y+ym[i],flag);
            if(flag)
                return;
            else{
                G[x+xm[i]][y+ym[i]]=-1;
                n--;
            }
        }
    }
}
int main(){
    int G[8][8];
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++)
            G[i][j]=-1;
    }
    bool f=0;
    G[0][0]=0;
    Knight_Tour(G,0,0,f);
    return 0;
}
