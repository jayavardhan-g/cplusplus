#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
vector<int> cyc;
// int z=-1;
bool d=0;

void dfs(int node,int t,int parent,int vis[],vector<int> adj[]){
// void dfs(int node,vector<int> a,int parent,int vis[],vector<int> adj[]){
    vis[node]=1;
    if(d)return;
    for(auto next:adj[node]){
        if(next!= parent){
            if(vis[next]==1){
                int i;
                for(i=a.size()-1;i>=0;i--){
                    if(a[i]==next)break;
                }
                if(i-a.size()>2){
                    for(i;i<a.size();i++){
                        cyc.push_back(a[i]);
                    }
                    cyc.push_back(next);
                    d=1;
                }
            }
            if(d)return;
            if(vis[next]==0){
                // a.push_back(next);
                dfs(next,a,node,vis,adj);
            }
            if(d)return;
        }
    }

    vis[node]=2;
}

int32_t main(){
    int n,m;cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int vis[n+1]={0};
    for(int i=1;i<n+1;i++){
        if(!vis[i])dfs(i,vector<int>{0},-1,vis,adj);
    }
    if(d){
        cout<<cyc.size()<<endl;
        for(auto i:cyc)cout<<i<<' ';
    }else{
        cout<<"IMPOSSIBLE";
    }
}