#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
    bool cycle(int i,bool vis[],bool path[],vector<vector<int>> &adj){
        vis[i]=1;
        path[i]=1;
        for(auto next:adj[i]){

            if(path[next])return 1;
            // if(vis[next])return 0;
            else{
                if(cycle(next,vis,path,adj))return true;
            }
        }
        path[i]=0;
        return 0;
    }
    bool isCyclic(int V, vector<vector<int>> &adj) {
        bool vis[V]={0};
        bool path[V]={0};
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(cycle(i,vis,path,adj))return 1;
            }
        }
        return 0;
    }

int32_t main(){
    int n;cin>>n;
    int m;cin>>m;
    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }

    cout<<isCyclic(n,adj);
}