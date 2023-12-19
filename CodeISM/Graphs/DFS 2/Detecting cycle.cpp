#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

bool detectcycle_dfs(int node,vector<int> adj[],int color[]){
    color[node]=1;
    for(int i=0;i<adj[node].size();i++){
        if(color[adj[node][i]]==0){
            if(detectcycle_dfs(adj[node][i],adj,color))return true;
        }
        if(color[adj[node][i]]==1)return true;
    }
    color[node]=2;
    return false;
}

int32_t main(){
    int n;cin>>n;
    vector<int> adj[n];
    int m;cin>>m;
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        adj[x].push_back(y);
    }
    int color[n];
    memset(color,0,sizeof(color));
    bool r=false;
    for(int i=0;i<n;i++){
        if(color[i]==0){
            if(detectcycle_dfs(i,adj,color)){
                r=true;
                break;
            }
        }
    }
    if(r)cout<<"There is a cycle"<<endl;
    else cout<<"No cycle";
}