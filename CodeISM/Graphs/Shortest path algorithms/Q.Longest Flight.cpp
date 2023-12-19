#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int32_t main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    vector<int> indegree(n+1,0);
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        indegree[y]++;
        adj[x].push_back(y);
    }
    vector<int> dis(n+1,-1);
    vector<int> parent(n+1,0);
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0)q.push(i);
    }
    dis[1]=1e6;
    while(!q.empty()){
        int node= q.front();
        q.pop();

        for(auto next:adj[node]){
            indegree[next]--;
            if(indegree[next]==0)q.push(next);

            if(dis[next]<dis[node]+1){
                parent[next]=node;
                dis[next]=dis[node]+1;
            }
        }
    }
    if(dis[n]<=1e6){cout<<"IMPOSSIBLE";return 0;}

    stack<int> s;
    while(parent[n]!=n){
        s.push(n);
        n=parent[n];
    }
    cout<<s.size()<<endl;
    while(!s.empty()){
        cout<<s.top()<<' ';
        s.pop();
    }

}