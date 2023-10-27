//https://cses.fi/problemset/task/1668
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
bool r=true;

void dfs(int node,vector<int> adj[],int team[] ){
    if(r==false )return;

    for(int i=0;i<adj[node].size();i++){
        if(team[adj[node][i]]==-1){
            team[adj[node][i]]=team[node]==1?2:1;
            dfs(adj[node][i],adj,team);
        }else if(team[node] != team[adj[node][i]])continue;
        else r=false;
    }
}

int32_t main(){
    int n;cin>>n;
    vector<int> adj[n];
    int m;cin>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    }
    // for(int i=0;i<n;i++){
    //     for(auto j:adj[i])cout<<j<<' ';
    //     cout<<endl;
    // }
    int team[n];
    memset(team,-1,sizeof(team));

    for(int i=0;i<n;i++){
        // for(int j=0;j<n;j++)cout<<team[j]<<' ';
        // cout<<endl;
        if(team[i]==-1){
            team[i]=1;
            dfs(i,adj,team);
        }
    }

    if(r){
        for(int i=0;i<n;i++)cout<<team[i]<<' ';
        cout<<endl;
    }else {
        cout<<"IMPOSSIBLE"<<endl;
    }

}