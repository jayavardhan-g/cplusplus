#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

bool rec(int i,int j,bool vis[],vector<vector<int>> &adj){
    vis[i]=1;
    bool r=0;
    for(auto node:adj[i]){
        if(vis[node] && node!=j)return 1;
        if(!vis[node]){
            r= r|rec(node,i,vis,adj);
        }
    }
    return r;
}

bool isCycle(int n,vector<vector<int>> adj){
    bool vis[n]={0};

    for(int i=0;i<n;i++){
        if(!vis[i]){
            if(rec(i,i,vis,adj))return 1;
        }
    }
    return 0;
}

int32_t main(){
    int n;cin>>n;
    vector<vector<int>> adj(n);
    int m;cin>>m;
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cout<<isCycle(n,adj);
}