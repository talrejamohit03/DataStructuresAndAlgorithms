#include<bits/stdc++.h>
using namespace std;

bool prune(set<vector<int> > &m,vector<int> &is,vector<int> curr,int idx,int k){
    //cout<<"pruning ";
    /*
    for(int i=0;i<curr.size();i++)
        cout<<curr[i]<<" ";
    cout<<"\n";
    */
    if(curr.size()>k)
        return 1;
    if(curr.size()==k){
        return !(m.find(curr)==m.end());
    }
    for(int i=idx;i<is.size();i++){
        curr.push_back(is[i]);
        if(!prune(m,is,curr,i+1,k))
            return 0;
        curr.pop_back();
    }
    return 1;
}
void join(vector<vector<int> > &lk,vector<vector<int> > &ck){
    //cout<<"joining \n";
    set<vector<int> > m;
    for(int i=0;i<lk.size();i++){
        m.insert(lk[i]);
    }
    int k=lk[0].size();
    for(int i=0;i<lk.size()-1;i++){
        for(int j=i+1;j<lk.size();j++){
            int n=0;
            for(n;n<k-1;n++){
                if(lk[i][n]!=lk[j][n])
                    break;
            }
            if(n==k-1){
                vector<int> tmp(lk[i]);
                tmp.push_back(lk[j][k-1]);
                /*
                cout<<"after join ";
                for(int i=0;i<tmp.size();i++)
                    cout<<tmp[i]<<" ";
                */
                vector<int> sub;
                if(prune(m,tmp,sub,0,k)){
                    //cout<<"valid \n";
                    ck.push_back(tmp);
                }
            }
        }
    }
}
bool checkFreq(vector<int> is,int ms){
    ifstream fin;
    fin.open("transactions.txt");
    string tid;
    int iid;
    set<int> isn;
    for(int i=0;i<is.size();i++)
        isn.insert(is[i]);
    int supp=0;
    while(!fin.eof()){
        fin>>tid;
        fin>>iid;
        int curr=0;
        while(iid!=-1){
            if(isn.find(iid)!=isn.end())
                curr++;
            fin>>iid;
        }
        if(curr==isn.size())
            supp++;
    }
    fin.close();
    return (supp>=ms);
}

int main(){
    ifstream fin;
    fin.open("transactions.txt");
    map<int,int> it;
    string tid;
    int iid;
    while(!fin.eof()){
        fin>>tid;
        fin>>iid;
        while(iid!=-1){
            it[iid]++;
            fin>>iid;
        }
    }
    fin.close();
    int min_supp=2;
    vector<vector<int> > lk,ck,ans;
    for(map<int,int>::iterator i=it.begin();i!=it.end();i++){
        if(i->second>=min_supp){
            vector<int> tmp;
            tmp.push_back(i->first);
            lk.push_back(tmp);
            ans.push_back(tmp);
        }
    }
    while(lk.size()>0){
        ck.clear();
        join(lk,ck);
        lk.clear();
        for(int i=0;i<ck.size();i++){
            if(checkFreq(ck[i],min_supp)){
                lk.push_back(ck[i]);
                ans.push_back(ck[i]);
            }
        }
    }
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
