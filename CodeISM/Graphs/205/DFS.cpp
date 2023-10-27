#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
int timer=1;

void dfs(int node, vector<int> adj[],int start[],int finish[],int color[]){
    start[node]=timer;
    timer++;
    color[node]=1;
    for(int i=0;i<adj[node].size();i++){
        if(color[adj[node][i]]==0)dfs(adj[node][i],adj,start,finish,color);
    }
    finish[node]=timer;
    color[node]=2;
    timer++;
}

int32_t main(){
    int n;cin>>n;
    vector<int> adj[n];
    for(int i=0;i<n;i++){
        int m;cin>>m;
        for(int j=0;j<m;j++){
            int x;cin>>x;
            adj[x].push_back(i);
            adj[i].push_back(x);
        }
    }
    int color[n]={0};
    int start[n]={0};
    int finish[n]={0};
    memset(color,0,sizeof(color));
    memset(start,0,sizeof(start));
    memset(finish,0,sizeof(finish));

    for(int i=0;i<n;i++){
        if(color[i]==0)dfs(i,adj,start,finish,color);
    }
    cout<<"Start"<<endl;
    for(int i=0;i<n;i++)cout<<start[i]<<' ';
    cout<<endl<<"Finish"<<endl;
    for(int i=0;i<n;i++)cout<<finish[i]<<' ';
}