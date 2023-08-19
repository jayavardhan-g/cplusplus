#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

    int rec(int node,vector<vector<pair<int,int>>>&adj,vector<int>&v){
        if(v[node]!=-1)return v[node];
        
        int l=1e9;
        for(auto next:adj[node]){
            int x=next.second + rec(next.first,adj,v);
            l=min(x,l);
            
        }
        return l;
    }
    
     vector<int> shortestPath(int n,int M, vector<vector<int>>& edges){
        vector<vector<pair<int,int>>>radj(n);
        for(int i=0;i<M;i++){
            radj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        
        vector<int> r(n,-1);
        r[0]=0;
        for(int i=1;i<n;i++){
            r[i]=rec(i,radj,r); 
            if(r[i]==1e9)r[i]=-1;
        }
        return r;
    }

int32_t main(){
    int n;cin>>n;
    int m;cin>>m;
    vector<vector<int>> adj(m,vector<int>(3));
    for(int i=0;i<m;i++){
        cin>>adj[i][0]>>adj[i][1]>>adj[i][2];
    }
    vector<int> v= shortestPath(n,m,adj);
    for(auto i:v)cout<<i<<' ';
}