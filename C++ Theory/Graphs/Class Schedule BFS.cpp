#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

    vector<int> findOrder(int n, int m, vector<vector<int>> pre) 
    {
        vector<int> adj[n];
        int indegree[n]={0};
        for(int i=0;i<m;i++){
            adj[pre[i][0]].push_back(pre[i][1]);
            indegree[pre[i][1]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++)if(indegree[i]==0)q.push(i);
        vector<int> e;
        vector<int> r;
        while(!q.empty()){
            int n=q.front();
            r.push_back(n);
            q.pop();
            for(auto i:adj[n]){
                indegree[i]--;
                if(indegree[i]==0)q.push(i);
            }
        }
        for(int i=0;i<n;i++){
            if(indegree[i]>0)return e;
        }
        return r;
    }

int32_t main(){
    int n;cin>>n;
    int m;cin>>m;
    vector<vector<int>> pre(m);
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        pre[i].push_back(x);
        pre[i].push_back(y);
    }
    vector<int> z= findOrder(n,m,pre);
    for(auto i:z)cout<<i<<' ';
}