//https://practice.geeksforgeeks.org/problems/topological-sort/1
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
	void rec(int i,stack<int> &s,bool vis[],vector<int> adj[]){
	    vis[i]=1;
	    for(auto next:adj[i]){
            if(!vis[next])rec(next,s,vis,adj);
	    }
	    s.push(i);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
        bool vis[V]={0};
        stack<int> s;
        
        for(int i=0;i<V;i++){
            if(!vis[i])rec(i,s,vis,adj);
        }
        vector<int>ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
	}
int32_t main(){
    int n;cin>>n;
    vector<int> adj[n];
    int m;cin>>m;
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        adj[x].push_back(y);
    }
    vector<int> ans=topoSort(n,adj);
    for(auto i:ans)cout<<i<<' ';
}