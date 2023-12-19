#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
vector<int> cyc;
int z=-1;

void dfs(int node,int between,int parent,int vis[],vector<int> adj[]){
    vis[node]=1;
    for(int i=0;i<adj[node].size();i++){
        int next= adj[node][i];
        if(next!=parent){
            if(vis[next]){
                cyc.push_back(next);
                return;
            }
        }
    }
}

int32_t main(){
    int n,m;cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}