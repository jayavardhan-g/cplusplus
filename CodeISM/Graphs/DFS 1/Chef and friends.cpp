//https://www.codechef.com/problems/CHFNFRN
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

// void dfs(int node,int parent,vector<int> adj[],vector<bool> vis){
//     vis[node]=1;
//     for(auto next:adj[node]){
//         if(next!=parent){
//             if(!vis[next])dfs(next,node,adj,vis);
//         }
//     }
// }

void solve(){
    int n,m;
    cin>>n>>m;
    bool connect[n+1][n+1];
    
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        connect[x][y]=1;
        connect[y][x]=1;
    }
    // vector<bool> vis(n+1,0);
    // for(int i=1;i<n+1;i++){
    //     if(!vis[i])dfs(i,-1,adj,vis);
    // }
    
}

int32_t main(){
    int t;cin>>t;
    while(t--)solve();
}