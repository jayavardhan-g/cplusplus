#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int32_t main(){
    int n,m;cin>>n>>m;
    vector<int> adj[n+1];
    int indegree[n+1]={0};
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        adj[x].push_back(y);
        indegree[y]++;
    }
    queue<int> q;
    for(int i=1;i<n+1;i++)if(indegree[i]==0)q.push(i);
    // if(q.empty()){
    //     cout<<"IMPOSSIBLE"<<endl;
    //     return 0;
    // }

    // for(int i=1;i<n+1;i++){
    //     cout<<i<<' ';
    //     for(int j=0;j<adj[i].size();j++)cout<<adj[i][j]<<' ';
    //     cout<<endl;
    // }
    // for(int i=1;i<n+1;i++)cout<<indegree[i]<<' ';
    // cout<<endl;
    vector<int> v;
    while(!q.empty()){
        int node= q.front();
        q.pop();
        // cout<<node<<' ';
        v.push_back(node);
        for(int i=0;i<adj[node].size();i++){
            int next= adj[node][i];
            indegree[next]--;
            if(indegree[next]==0)q.push(next);
        }
    }
    int possible=true;

    for(int i=1;i<n+1;i++){
        if(indegree[i]>0){
            possible=false;
            break;
        }
    }
    if(possible){
        for(auto i:v)cout<<i<<' ';
    }else cout<<"IMPOSSIBLE";
}