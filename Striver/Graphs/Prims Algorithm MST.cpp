#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

vector<pair<int,int>> prim(int n,vector<vector<int>> &v){
    vector<pair<int,int>> adj[n];
    for(int i=0;i<v.size();i++){
        adj[v[i][0]].push_back({v[i][1],v[i][2]});
        adj[v[i][1]].push_back({v[i][0],v[i][2]});
    }

    priority_queue< pair<int,pair<int,int>>, vector< pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;
    bool vis[n]={0};    
    vector<pair<int,int>> r;
    // pq.push({0,{0,-1}});
    for(auto i:adj[0])pq.push({i.second,{i.first,0}});
    vis[0]=1;
    int w=0;
    while(!pq.empty()){
        auto i=pq.top();
        pq.pop();
        int x=i.second.first;
        int y=i.second.second;
        int d=i.first;

        if(vis[x])continue;
        vis[x]=1;
        r.push_back({x,y});
        w+= d;
        for(auto next:adj[x]){
            pq.push({next.second,{next.first,x}});
        }
    }
    cout<<w<<endl;
    return r;
}
int32_t main(){
    int n;cin>>n;
    int m;cin>>m;
    vector<vector<int>> v(m,vector<int>(3));
    for(int i=0;i<m;i++){
        cin>>v[i][0]>>v[i][1]>>v[i][2];
    }
    vector<pair<int,int>> r= prim(n,v);
    for(auto i:r)cout<<i.first<<' '<<i.second<<endl;
}