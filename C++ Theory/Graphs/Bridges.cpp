#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

    int timer=1;
    void dfs(int node,int parent, vector<bool> &vis, vector<int> &time, vector<int> &low, vector<int> adj[],vector<vector<int>> &r){
        time[node]=low[node]=timer;
        vis[node]=1;
        timer++;

        for(auto next:adj[node]){
            if(parent==next)continue;
            if(!vis[next]){
                dfs(next,node,vis,time,low,adj,r);
                low[node]=min(low[node],low[next]);
                if(low[node]>time[parent])r.push_back({parent,node});
            }else{
                low[node]=min(low[node],low[next]);
            }
            
        }

        // if(low[node]> time[parent])r.push_back({parent,node});
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }

        vector<int> low(n),time(n);
        vector<bool> vis(n,0);
        vector<vector<int>> r;
        dfs(0,0,vis,time,low,adj,r);
        return r;
    }

int32_t main(){
    int k;cin>>k;
    int n;cin>>n;
    vector<vector<int>> connections(n,vector<int>(2));
    for(int i=0;i<n;i++)cin>>connections[i][0]>>connections[i][1];

    vector<vector<int>> r= criticalConnections(k,connections);
    for(auto i:r)cout<<i[0]<<' '<<i[1]<<endl;
}