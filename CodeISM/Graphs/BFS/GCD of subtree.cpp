#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
vector<vector<int>> adj;
vector<int> hcf;
vector<bool> vis;

void dfs(int node){
    vis[node]=1;
    int temp=node;
    for(auto i:adj[node]){
        if(!vis[i]){
            dfs(i);
        }
        temp = __gcd(temp, hcf[i] );
    }

    hcf[node]=temp;
}

int32_t main(){
    int n;cin>>n;
    hcf.resize(n+1);
    vis.resize(n+1,0);
    adj.resize(n+1);
    for(int i=1;i<=n;i++){
        int z;cin>>z;
        adj[i].resize(z);
        for(int j=0;j<z;j++)cin>>adj[i][j];
    }

    for(int i=1;i<=n;i++){
        if(!vis[i])dfs(i);
    }
    for(auto i:hcf)cout<<i<<' ';

}