#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int32_t main(){
    int n;cin>>n;
    vector<int> adj[n];
    int m;cin>>m;
    int indegree[n]={0};
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        adj[x].push_back(y);
        indegree[y]++;
    }
    queue<int> q;
    for(int i=0;i<n;i++)if(indegree[i]==0)q.push(i);
    vector<int> r;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        r.push_back(node);
        for(int i=0;i<adj[node].size();i++){
            int next=adj[node][i];
            indegree[next]--;
            if(indegree[next]==0)q.push(next);
        }
    }
    for(auto i:r)cout<<i<<' ';
}