#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int32_t main(){
    int n,m,r;cin>>n>>m>>r;
    int indegree[n+1]={0};
    int outdegree[n+1]={0};
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        adj[x].push_back(y);
        indegree[y]++;
        outdegree[x]++;
    }
    double prob[n+1]={0};
    prob[r]=1;
    vector<int> stuck;
    queue<int> q;
    for(int i=1;i<n+1;i++){
        if(indegree[i]==0)q.push(i);
        if(outdegree[i]==0)stuck.push_back(i);
    }

    while(!q.empty()){
        int node= q.front();
        q.pop();
        for(int i=0;i<adj[node].size();i++){
            int next=  adj[node][i];
            prob[next] += prob[node] * (1.0/outdegree[node]);
            indegree[next]--;
            if(indegree[next]==0)q.push(next);
        }
    }
    // for(int i=0;i<stuck.size();i++)cout<<stuck[i];
    double maxx=0;
    for(int i=0;i<stuck.size();i++){
        maxx= max(prob[stuck[i]], maxx);
    }
    for(int i=0;i<stuck.size();i++){
        if(prob[stuck[i]]==maxx)cout<<stuck[i]<<' ';
    }
}