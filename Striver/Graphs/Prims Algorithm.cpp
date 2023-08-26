#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    vector<pair<int,int>> adj[n];
    for(int i=0;i<m;i++){
        adj[g[i].first.first].push_back({g[i].first.second,g[i].second});
        // adj[g[i].first.second].push_back({g[i].first.first,g[i].second});
    }

    priority_queue< pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
    bool vis[n]={0};
    for(auto i:adj[0]){
        pq.push({i.second,{i.first,0}});
    }
    vis[0]=1;

    vector<pair<pair<int,int>,int>> r;
    while(!pq.empty()){
        auto i= pq.top();
        pq.pop();
        int node= i.second.first;
        int parent=i.second.second;
        int d=i.first;
    
        if(vis[node])continue;
        vis[node]=1;
        r.push_back({{node,parent},d});

        for(auto next:adj[node]){
            pq.push({next.second,{next.first,node}});
        }
    }
    return r;
}

int32_t main(){
    int n,m;cin>>n>>m;
    vector<pair<pair<int, int>, int>> g(m);
    for(int i=0;i<m;i++)cin>>g[i].first.first>>g[i].first.second>>g[i].second;
    vector<pair<pair<int, int>, int>> r=calculatePrimsMST(n,m,g);
    for(auto i:r)cout<<i.first.first<<' '<<i.first.second<<' '<<i.second<<endl;
}