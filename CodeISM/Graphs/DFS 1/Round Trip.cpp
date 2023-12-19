#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

// int start= -1;

int dfs(int node,vector<int> &level,int parent,vector<int> &vis, vector<int> adj[]){
    
}

int32_t main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    int level[n+1]={0};
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> vis(n+1,0);
    
}