#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

void rec(int i,vector<bool> &c,vector<vector<int>> &v,vector<int> &dfs){
    c[i]=1;
    dfs.push_back(i);
    for(int j=0;j<v[i].size();j++){
        if(!c[v[i][j]]){
            // dfs.push_back()
            rec(v[i][j],c,v,dfs);
        }
    }
    return;
}

int32_t main(){
    int n,m;cin>>n>>m;
    vector<vector<int>> v(n);
    int x,y;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    vector<int> bfs;
    queue<int> q;
    vector<bool> c(n,0);
    q.push(0);
    c[0]=1;
    // r.push_back(0);
    while(!q.empty()){
        int e=q.front();
        q.pop();
    
        bfs.push_back(e);
        for(auto i:v[e]){
            if(c[i]!=1){
                q.push(i);
                c[i]=1;
            }
        }
    }
    for(auto i:bfs)cout<<i<<' ';//bfs

    c=vector<bool>(n,0);
    vector<int> dfs;
    c[0]=1;
    rec(0,c,v,dfs);
    cout<<endl;
    for(auto i:dfs)cout<<i<<' ';//dfs
}