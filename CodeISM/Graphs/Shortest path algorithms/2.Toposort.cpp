#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

//Steps
// Sort in topological order
// For every element in the topo vector relax the node distances i.e 
//     if (distance [next]> distance[node]+distance[node->next])distance[next]= distance[node]+distance[node->next]

int32_t main(){
    int n,m;cin>>n>>m;
    vector<pair<int,int>> adj[n+1];
    int indegree[n+1]={0};
    for(int i=0;i<m;i++){
        int x,y,d;cin>>x>>y>>d;
        indegree[y]++;
        adj[x].push_back({y,d});
    }
    queue<int> q;
    vector<int> topo;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0)q.push(i);
    }

    while(!q.empty()){
        int x= q.front();
        q.pop();
        topo.push_back(x);
        for(auto i:adj[x]){
            indegree[i.first]--;
            if(indegree[i.first]==0)q.push(i.first);
        }
    }
    vector<int> parent(n+1,0);
    vector<int> dis(n+1,1e9);
    dis[1]=0;

    for(int i=0;i<n;i++){
        int x=topo[i];

        for(auto next:adj[x]){
            if(dis[next.first]>dis[x]+next.second){

                parent[next.first]=x;
                dis[next.first]=dis[x]+next.second;

            }
        }
    }
    for(auto i:dis)cout<<i<<' ';
}