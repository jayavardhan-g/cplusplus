//https://cses.fi/problemset/task/1666
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

void dfs(int node, bool vis[],vector<int> adj[]){
    if(vis[node])return;

    vis[node]=1;
    for(int i=0;i<adj[node].size();i++){
        int next= adj[node][i];
        dfs(next,vis,adj);
    }
}

int32_t main(){
    int n,m;cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int  x,y;cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    bool vis[n+1]={0};
    int t=0;
    vector<int> r;
    for(int i=1;i<n+1;i++){
        if(!vis[i]){
            r.push_back(i);
            t++;
            dfs(i,vis,adj);
        }
    }
    cout<<t-1<<endl;
    for(int i=1;i<r.size();i++)cout<<r[0]<<' '<<r[i]<<endl;
}