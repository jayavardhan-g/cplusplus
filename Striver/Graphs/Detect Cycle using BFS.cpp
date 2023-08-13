#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
    bool isCycle(int n,vector<vector<int>> &adj){
        bool vis[n]={0};
        for(int i=0;i<n;i++){
            if(!vis[i]){
                queue<pair<int,int>> q;
                q.push({i,i});
                vis[i]=1;
                while(!q.empty()){
                    int f=q.front().first;
                    int s=q.front().second;
                    q.pop();
                    for(auto n2:adj[f]){
                        if(n2!=s && vis[n2])return 1;
                        if(!vis[n2] && n2!=s ){
                            vis[n2]=1;
                            q.push({n2,f});
                        }
                    }
                }
            }
        }
        return 0;
    }

int32_t main(){
    int n;cin>>n;
    vector<vector<int>> adj(n);
    int m;cin>>m;
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cout<<isCycle(n,adj);
}