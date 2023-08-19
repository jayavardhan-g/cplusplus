//
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

	vector<int> topoSort(int V, vector<int> adj[]) 
	{   
	    //bfs
        int indegree[V]={0};
        for(int i=0;i<V;i++){
            for(auto n:adj[i]){
                indegree[n]++;
            }
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0)q.push(i);
        }
        vector<int> r;
        while(!q.empty()){
            int i=q.front();
            q.pop();
            r.push_back(i);
            for(auto next:adj[i]){
                indegree[next]--;
                if(indegree[next]==0){
                    q.push(next);
                }
            }
        }
        return r;
    }

int32_t main(){
    int n;cin>>n;
    vector<int> adj[n];
    int m;cin>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    vector<int> ans=topoSort(n,adj);
    // reverse(ans.begin(),ans.end());
    for(auto  i:ans)cout<<i<<' ';
    
}