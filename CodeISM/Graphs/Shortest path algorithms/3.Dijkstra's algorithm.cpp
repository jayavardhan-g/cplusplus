#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int32_t main(){
    int n,m;cin>>n>>m;
    vector<pair<int,int>> adj[n+1];
    int indegree[n+1]={0};
    for(int i=0;i<m;i++){
        int x,y,d;cin>>x>>y>>d;
        indegree[y]++;
        adj[x].push_back({y,d});
    }
    vector<int> distance(n+1,1e9);
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>> > pq;

    pq.push({0,1});
    distance[1]=0;
    while(!pq.empty()){
        int node = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        for(auto i:adj[node]){
            int next = i.first;
            int nd = i.second;
            if(distance[next]> d+nd){
                distance[next] = d+nd;
                pq.push({distance[next],next});
            }
        }
    }
    for(auto i:distance)cout<<i<<' ';
}