#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

    int timer=1;
    void dfs(int node,int parent,bool vis[],int time[],int low[],set<int> &r,vector<int> adj[]){
        vis[node]=1;
        time[node]=low[node]=timer;
        timer++;
        int child=0;
        for(auto next:adj[node]){
            if(next==parent)continue;
            child++;
            if(!vis[next]){
                dfs(next,node,vis,time,low,r,adj);
                low[node]=min(low[node],low[next]);
                if(low[next]>=time[node] && parent!=-1)r.insert(node);
            }else{
                low[node]=min(low[node],time[next]);
            }
        }
        if(child>1 && parent==-1)r.insert(node);    
    }

    vector<int> articulationPoints(int V, vector<int>adj[]) {
        bool vis[V]={0};
        int time[V];
        int low[V];
        set<int> r;
        
        dfs(0,0,vis,time,low,r,adj);
        
        vector<int> v;
        for(auto i:r){
            // cout<<i<<' ';
            // cout<<endl;
            v.push_back(i);
            
        }
        if(v.size()>0)return v;
        return {-1};
    }

int32_t main(){
    int n;cin>>n;
    vector<int> adj[n];
    int k;cin>>k;
    for(int i=0;i<k;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y); 
        adj[y].push_back(x); 
    }
    
}