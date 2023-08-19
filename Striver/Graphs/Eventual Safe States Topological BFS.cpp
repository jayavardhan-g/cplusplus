#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
    vector<int> adj2[V];
    int outdegree[V]={0};
    queue<int> q;
    for(int i=0;i<V;i++){
        outdegree[i]=adj[i].size();
        for(auto next:adj[i]){
            adj2[next].push_back(i);
        }
        if(outdegree[i]==0)q.push(i);
    }
    int k=0;
    // for(auto i:adj2){
    //     cout<<k++<<'-';
    //     for(auto j:i)cout<<j<<' ';
    //     cout<<endl;
    // }
    // cout<<endl<<endl<<endl;
    // for(auto i:outdegree)cout<<i<<' ';
    vector<int> r;
    while(!q.empty()){
        int n=q.front();
        r.push_back(n);
        q.pop();
        for(auto i:adj2[n]){
            outdegree[i]--;
            if(outdegree[i]==0)q.push(i);
        }
    }
    return r;
}

int32_t main(){
    int n;cin>>n;
    vector<int> adj[n];
    int m;cin>>m;
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        adj[x].push_back(y);
    }
    vector<int> v=eventualSafeNodes(n,adj);
    for(auto i:v)cout<<i<<' ';

}