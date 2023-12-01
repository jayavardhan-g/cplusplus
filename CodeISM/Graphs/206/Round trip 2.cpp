//https://cses.fi/problemset/task/1678/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
bool poss= true;

bool dfs(int node, int color[],vector<int> adj[]){
    color[node]=1;
    for(int i=0;i<adj[node].size();i++){
        int next= adj[node][i];
        if(color[next]==0){
            if(dfs(next,color,adj))return true;
        }
        if(color[next]==1)return true;
    }
    return false;
}

int32_t main(){
    int n,m;cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        adj[x].push_back(y);
    }

}