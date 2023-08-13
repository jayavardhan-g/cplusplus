//https://practice.geeksforgeeks.org/problems/eventual-safe-states/1
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

    bool rec(int i,vector<vector<int>> &adj,bool vis[],bool path[],set<int> &t){

        if(adj[i].size()==0){t.insert(i);return 1;}
        vis[i]=1;
        path[i]=1;
        bool r=1;
        for(auto next:adj[i]){
            if(path[next]){
                r=0;
            }
            else r=r&rec(next,adj,vis,path,t);
        }
        if(r==1)t.insert(i);

        path[i]=0;
        return r;
    }
    vector<int> eventualSafeNodes(int V, vector<vector<int>>&adj) {
        // vector<vector<int>> v(V);
        vector<int> t;
        // for(int i=0;i<V;i++){
        //     if(adj[i].size()==0)t.push_back(i);
        //     for(auto j:adj[i]){
        //         v[j].push_back(i);
        //     }
        // }
        // int x=0;
        // for(auto i:v){
        //     cout<<x++<<'-';
        //     for(auto j:i)cout<<j<<' ';
        //     cout<<endl;
        // }
        // for(auto i:t)cout<<i<<' ';
        // return t;
        bool vis[V]={0};
        bool path[V]={0};
        set<int> r;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                rec(i,adj,vis,path,r);
            }
        }
        for(auto i:r)t.push_back(i);

        return t;
    }

int32_t main(){
    int n;cin>>n;
    int m;cin>>m;
    vector<vector<int>>adj(n);
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        adj[x].push_back(y);
    }
    eventualSafeNodes(n,adj);

}