#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
void dfs(int node,vector<int> adj[],int lvl[]){
    // vis[node]=1;
    
    for(int i=0;i<adj[node].size();i++){
        if(lvl[adj[node][i]]==-1){
            lvl[adj[node][i]]=lvl[node]+1;
            dfs(adj[node][i],adj,lvl);
        }
    }
}

int32_t main(){
    int n;cin>>n;
    vector<int> adj[n];
    for(int i=0;i<n;i++){
        int m;cin>>m;
        for(int j=0;j<m;j++){
            int x;cin>>x;
            adj[x].push_back(i);
            adj[i].push_back(x);
        }
    }
    int lvl[n];
    memset(lvl,-1,sizeof(lvl));
    lvl[0]=0;
    dfs(0,adj,lvl);
    for(int i=0;i<n;i++)cout<<lvl[i]<<' ';

}