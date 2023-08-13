#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

    void rec(int node,vector<bool> &vis,vector<vector<int>> &adj){
        vis[node]=1;

        for(auto i:adj[node]){
            if(!vis[i]){
                rec(i,vis,adj);
            }
        }
    }
    
    int numProvinces(vector<vector<int>> &adj, int V) {
        vector<bool> vis(V,0);
        int ans=0;
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                ans++;
                rec(i,vis,adj);
            }
        }

        return ans;
    }
    
int32_t main(){
    int n;cin>>n;
    int m;cin>>m;
    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cout<<numProvinces(adj,n);
}